#!/usr/bin/env python3
"""Real-time system monitor with rolling line charts (Ubuntu 22.04).

Displays four subplots:
  1. GPU VRAM usage (per GPU, supports multi-GPU)
  2. GPU power draw (per GPU)
  3. System memory usage
  4. CPU utilization

Dependencies:
  pip install psutil matplotlib nvidia-ml-py3

Usage:
  python utils/monitor_gpu.py
  python utils/monitor_gpu.py --interval 0.5 --history 300
"""

from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
import time
from collections import deque
from dataclasses import dataclass, field
from typing import Deque, List, Optional, Sequence, Tuple

import matplotlib

matplotlib.rcParams["toolbar"] = "None"


def _prepare_frozen_gui() -> None:
    """Work around Pillow/Tk issues inside a PyInstaller bundle."""
    if not getattr(sys, "frozen", False):
        return

    for mod in ("PIL._imagingtk", "PIL._tkinter_finder", "PIL.ImageTk"):
        try:
            __import__(mod)
        except ImportError:
            pass

    try:
        from PIL import ImageTk, _imagingtk

        _orig_init = ImageTk.PhotoImage.__init__

        def _photo_init(self, *args, **kwargs):
            master = kwargs.get("master")
            if master is not None:
                try:
                    _imagingtk.tkinit(master.tk.interpaddr())
                except Exception:
                    pass
            _orig_init(self, *args, **kwargs)

        ImageTk.PhotoImage.__init__ = _photo_init
    except Exception:
        pass


_prepare_frozen_gui()

import matplotlib.animation as animation
import matplotlib.pyplot as plt
import psutil

try:
    import pynvml

    _HAS_PYNVML = True
except ImportError:
    _HAS_PYNVML = False


@dataclass
class GpuInfo:
    index: int
    name: str
    memory_total_mib: float
    memory_used_mib: float = 0.0
    power_draw_w: float = 0.0
    power_limit_w: Optional[float] = None


@dataclass
class Sample:
    timestamp: float
    gpus: List[GpuInfo] = field(default_factory=list)
    mem_used_gb: float = 0.0
    mem_total_gb: float = 0.0
    mem_percent: float = 0.0
    cpu_percent: float = 0.0


class GpuCollector:
    """Collect GPU metrics via NVML or nvidia-smi fallback."""

    def __init__(self) -> None:
        self._backend: str = "none"
        self._handles: List = []
        self._static: List[GpuInfo] = []
        self._init()

    def _init(self) -> None:
        if _HAS_PYNVML:
            try:
                pynvml.nvmlInit()
                count = pynvml.nvmlDeviceGetCount()
                for i in range(count):
                    handle = pynvml.nvmlDeviceGetHandleByIndex(i)
                    name = pynvml.nvmlDeviceGetName(handle)
                    if isinstance(name, bytes):
                        name = name.decode("utf-8", errors="replace")
                    mem = pynvml.nvmlDeviceGetMemoryInfo(handle)
                    self._handles.append(handle)
                    self._static.append(
                        GpuInfo(
                            index=i,
                            name=name,
                            memory_total_mib=mem.total / (1024**2),
                        )
                    )
                self._backend = "pynvml"
                return
            except pynvml.NVMLError:
                pynvml.nvmlShutdown()

        if shutil.which("nvidia-smi"):
            gpus = self._query_nvidia_smi()
            if gpus:
                self._static = gpus
                self._backend = "nvidia-smi"
                return

        self._backend = "none"

    @staticmethod
    def _query_nvidia_smi() -> List[GpuInfo]:
        cmd = [
            "nvidia-smi",
            "--query-gpu=index,name,memory.total,memory.used,power.draw,power.limit",
            "--format=csv,noheader,nounits",
        ]
        try:
            out = subprocess.check_output(cmd, text=True, stderr=subprocess.DEVNULL)
        except (subprocess.CalledProcessError, FileNotFoundError):
            return []

        gpus: List[GpuInfo] = []
        for line in out.strip().splitlines():
            parts = [p.strip() for p in line.split(",")]
            if len(parts) < 5:
                continue
            try:
                idx = int(parts[0])
                name = parts[1]
                mem_total = float(parts[2])
                mem_used = float(parts[3])
                power = float(parts[4]) if parts[4] not in ("N/A", "[N/A]") else 0.0
                power_limit = None
                if len(parts) >= 6 and parts[5] not in ("N/A", "[N/A]", ""):
                    power_limit = float(parts[5])
            except ValueError:
                continue
            gpus.append(
                GpuInfo(
                    index=idx,
                    name=name,
                    memory_total_mib=mem_total,
                    memory_used_mib=mem_used,
                    power_draw_w=power,
                    power_limit_w=power_limit,
                )
            )
        return gpus

    @property
    def available(self) -> bool:
        return self._backend != "none"

    @property
    def backend(self) -> str:
        return self._backend

    def poll(self) -> List[GpuInfo]:
        if not self.available:
            return []

        if self._backend == "pynvml":
            result: List[GpuInfo] = []
            for handle, base in zip(self._handles, self._static):
                mem = pynvml.nvmlDeviceGetMemoryInfo(handle)
                power_mw = 0.0
                power_limit_w = None
                try:
                    power_mw = pynvml.nvmlDeviceGetPowerUsage(handle)
                except pynvml.NVMLError:
                    pass
                try:
                    limit_mw = pynvml.nvmlDeviceGetPowerManagementLimit(handle)
                    power_limit_w = limit_mw / 1000.0
                except pynvml.NVMLError:
                    pass
                result.append(
                    GpuInfo(
                        index=base.index,
                        name=base.name,
                        memory_total_mib=mem.total / (1024**2),
                        memory_used_mib=mem.used / (1024**2),
                        power_draw_w=power_mw / 1000.0,
                        power_limit_w=power_limit_w,
                    )
                )
            return result

        return self._query_nvidia_smi()

    def close(self) -> None:
        if self._backend == "pynvml" and _HAS_PYNVML:
            try:
                pynvml.nvmlShutdown()
            except pynvml.NVMLError:
                pass


def collect_sample(gpu_collector: GpuCollector) -> Sample:
    vm = psutil.virtual_memory()
    return Sample(
        timestamp=time.time(),
        gpus=gpu_collector.poll(),
        mem_used_gb=vm.used / (1024**3),
        mem_total_gb=vm.total / (1024**3),
        mem_percent=vm.percent,
        cpu_percent=psutil.cpu_percent(interval=None),
    )


def _gpu_colors(n: int) -> List[str]:
    palette = plt.cm.tab10.colors  # type: ignore[attr-defined]
    return [palette[i % len(palette)] for i in range(max(n, 1))]


class MonitorApp:
    def __init__(
        self,
        interval: float,
        history: int,
        show_per_core: bool,
    ) -> None:
        self.interval = interval
        self.history = history
        self.show_per_core = show_per_core

        self.gpu_collector = GpuCollector()
        psutil.cpu_percent(interval=None)

        self.times: Deque[float] = deque(maxlen=history)
        self.mem_used: Deque[float] = deque(maxlen=history)
        self.mem_percent: Deque[float] = deque(maxlen=history)
        self.cpu_total: Deque[float] = deque(maxlen=history)
        self.gpu_mem: dict[int, Deque[float]] = {}
        self.gpu_power: dict[int, Deque[float]] = {}
        self.core_cpu: dict[int, Deque[float]] = {}
        self.gpu_meta: dict[int, GpuInfo] = {}
        self.t0 = time.time()

        self.fig, self.axes = plt.subplots(2, 2, figsize=(12, 7), constrained_layout=True)
        self.fig.canvas.manager.set_window_title("System Monitor")  # type: ignore[union-attr]
        titles = [
            "GPU VRAM (GiB)",
            "GPU Power (W)",
            "System Memory (GiB)",
            "CPU Usage (%)",
        ]
        for ax, title in zip(self.axes.flat, titles):
            ax.set_title(title, fontsize=11, fontweight="bold")
            ax.grid(True, alpha=0.3)
            ax.set_xlim(0, history * interval)

        self.ax_mem, self.ax_power, self.ax_ram, self.ax_cpu = self.axes.flat

        self.lines_mem: dict[int, plt.Line2D] = {}
        self.lines_power: dict[int, plt.Line2D] = {}
        self.line_ram_used: Optional[plt.Line2D] = None
        self.line_ram_total: Optional[plt.Line2D] = None
        self.line_cpu: Optional[plt.Line2D] = None
        self.lines_core: dict[int, plt.Line2D] = {}

        self.status_text = self.fig.text(
            0.01,
            0.01,
            "",
            fontsize=9,
            va="bottom",
            family="monospace",
        )

        self._bootstrap()

    def _bootstrap(self) -> None:
        sample = collect_sample(self.gpu_collector)
        for gpu in sample.gpus:
            self.gpu_meta[gpu.index] = gpu
            self.gpu_mem[gpu.index] = deque(maxlen=self.history)
            self.gpu_power[gpu.index] = deque(maxlen=self.history)

        if self.show_per_core:
            for i in range(psutil.cpu_count(logical=True) or 1):
                self.core_cpu[i] = deque(maxlen=self.history)

        self._append_sample(sample)
        self._init_lines()

    def _append_sample(self, sample: Sample) -> None:
        t = sample.timestamp - self.t0
        self.times.append(t)
        self.mem_used.append(sample.mem_used_gb)
        self.mem_percent.append(sample.mem_percent)
        self.cpu_total.append(sample.cpu_percent)

        seen = set()
        for gpu in sample.gpus:
            seen.add(gpu.index)
            self.gpu_meta[gpu.index] = gpu
            if gpu.index not in self.gpu_mem:
                self.gpu_mem[gpu.index] = deque(maxlen=self.history)
                self.gpu_power[gpu.index] = deque(maxlen=self.history)
            self.gpu_mem[gpu.index].append(gpu.memory_used_mib / 1024.0)
            self.gpu_power[gpu.index].append(gpu.power_draw_w)

        for idx in self.gpu_mem:
            if idx not in seen:
                self.gpu_mem[idx].append(0.0)
                self.gpu_power[idx].append(0.0)

        if self.show_per_core:
            per_core = psutil.cpu_percent(percpu=True)
            for i, pct in enumerate(per_core):
                if i not in self.core_cpu:
                    self.core_cpu[i] = deque(maxlen=self.history)
                self.core_cpu[i].append(pct)

    def _init_lines(self) -> None:
        colors = _gpu_colors(len(self.gpu_mem))
        for i, idx in enumerate(sorted(self.gpu_mem)):
            gpu = self.gpu_meta.get(idx)
            label = f"GPU {idx}"
            if gpu:
                label = f"GPU {idx}: {gpu.name[:28]}"
            (line,) = self.ax_mem.plot([], [], color=colors[i], label=label, linewidth=1.8)
            self.lines_mem[idx] = line
            if gpu and gpu.memory_total_mib > 0:
                total_gib = gpu.memory_total_mib / 1024.0
                self.ax_mem.axhline(
                    total_gib,
                    color=colors[i],
                    linestyle="--",
                    alpha=0.35,
                    linewidth=1.0,
                )

        for i, idx in enumerate(sorted(self.gpu_power)):
            (line,) = self.ax_power.plot(
                [], [], color=colors[i], label=f"GPU {idx}", linewidth=1.8
            )
            self.lines_power[idx] = line
            gpu = self.gpu_meta.get(idx)
            if gpu and gpu.power_limit_w:
                self.ax_power.axhline(
                    gpu.power_limit_w,
                    color=colors[i],
                    linestyle="--",
                    alpha=0.35,
                    linewidth=1.0,
                )

        (self.line_ram_used,) = self.ax_ram.plot(
            [], [], color="#2ecc71", label="Used", linewidth=2.0
        )
        (self.line_ram_total,) = self.ax_ram.plot(
            [], [], color="#95a5a6", label="Total", linewidth=1.2, linestyle="--"
        )
        (self.line_cpu,) = self.ax_cpu.plot(
            [], [], color="#3498db", label="Total CPU", linewidth=2.0
        )

        if self.show_per_core:
            core_colors = _gpu_colors(len(self.core_cpu))
            for i, core_idx in enumerate(sorted(self.core_cpu)):
                (line,) = self.ax_cpu.plot(
                    [],
                    [],
                    color=core_colors[i],
                    alpha=0.35,
                    linewidth=0.9,
                    label=f"Core {core_idx}",
                )
                self.lines_core[core_idx] = line

        for ax in (self.ax_mem, self.ax_power, self.ax_ram, self.ax_cpu):
            ax.legend(loc="upper left", fontsize=8, framealpha=0.85)

        self.ax_mem.set_ylabel("GiB")
        self.ax_power.set_ylabel("Watts")
        self.ax_ram.set_ylabel("GiB")
        self.ax_cpu.set_ylabel("%")
        self.ax_cpu.set_ylim(0, 100)
        for ax in self.axes[1]:
            ax.set_xlabel("Time (s)")

    def _sync_xlim(self) -> None:
        if not self.times:
            return
        t_max = self.times[-1]
        t_min = max(0.0, t_max - self.history * self.interval)
        for ax in self.axes.flat:
            ax.set_xlim(t_min, max(t_max, t_min + 1))

    def _update_plot(self, _frame: int) -> Sequence[plt.Artist]:
        sample = collect_sample(self.gpu_collector)
        self._append_sample(sample)

        xs = list(self.times)
        for idx, line in self.lines_mem.items():
            ys = list(self.gpu_mem[idx])
            line.set_data(xs[-len(ys) :], ys)
        for idx, line in self.lines_power.items():
            ys = list(self.gpu_power[idx])
            line.set_data(xs[-len(ys) :], ys)

        mem_total = sample.mem_total_gb
        self.line_ram_used.set_data(xs, list(self.mem_used))
        self.line_ram_total.set_data(xs, [mem_total] * len(xs))

        self.line_cpu.set_data(xs, list(self.cpu_total))
        artists: List[plt.Artist] = list(self.lines_mem.values()) + list(
            self.lines_power.values()
        )
        artists.extend([self.line_ram_used, self.line_ram_total, self.line_cpu])

        if self.show_per_core:
            for core_idx, line in self.lines_core.items():
                ys = list(self.core_cpu[core_idx])
                line.set_data(xs[-len(ys) :], ys)
            artists.extend(self.lines_core.values())

        self._sync_xlim()
        self._autoscale_y()

        backend = self.gpu_collector.backend
        gpu_count = len(self.gpu_meta)
        self.status_text.set_text(
            f"GPU backend: {backend} | GPUs: {gpu_count} | "
            f"RAM: {sample.mem_percent:.1f}% | CPU: {sample.cpu_percent:.1f}% | "
            f"refresh: {self.interval:.1f}s"
        )
        return artists

    def _autoscale_y(self) -> None:
        for idx in self.gpu_mem:
            ys = list(self.gpu_mem[idx])
            if ys:
                self.ax_mem.set_ylim(0, max(max(ys) * 1.1, 0.5))
        for idx in self.gpu_power:
            ys = [y for y in self.gpu_power[idx] if y > 0]
            if ys:
                self.ax_power.set_ylim(0, max(max(ys) * 1.15, 10))
        if self.mem_used:
            total_line = list(self.line_ram_total.get_ydata()) if self.line_ram_total else []
            max_val = max(max(self.mem_used), max(total_line) if total_line else 0.0)
            self.ax_ram.set_ylim(0, max(max_val * 1.05, 0.5))

    def run(self) -> None:
        ani = animation.FuncAnimation(
            self.fig,
            self._update_plot,
            interval=int(self.interval * 1000),
            blit=False,
            cache_frame_data=False,
        )
        self._ani = ani  # keep reference
        try:
            plt.show()
        finally:
            self.gpu_collector.close()


def parse_args(argv: Optional[Sequence[str]] = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Real-time GPU / CPU / memory monitor with rolling charts."
    )
    parser.add_argument(
        "--interval",
        type=float,
        default=1.0,
        help="Sampling interval in seconds (default: 1.0)",
    )
    parser.add_argument(
        "--history",
        type=int,
        default=120,
        help="Number of data points to keep (default: 120)",
    )
    parser.add_argument(
        "--per-core",
        action="store_true",
        help="Also plot per-CPU-core usage (can be noisy on many-core CPUs)",
    )
    return parser.parse_args(argv)


def main(argv: Optional[Sequence[str]] = None) -> int:
    args = parse_args(argv)
    if args.interval <= 0 or args.history <= 1:
        print("interval must be > 0 and history must be > 1", file=sys.stderr)
        return 1

    print("Starting monitor... Close the chart window to exit.")
    if not _HAS_PYNVML:
        print("Tip: pip install nvidia-ml-py3  (faster GPU polling than nvidia-smi)")
    app = MonitorApp(
        interval=args.interval,
        history=args.history,
        show_per_core=args.per_core,
    )
    if not app.gpu_collector.available:
        print(
            "Warning: No NVIDIA GPU detected. GPU panels will stay empty.\n"
            "  - Install NVIDIA driver + nvidia-smi, or\n"
            "  - pip install nvidia-ml-py3",
            file=sys.stderr,
        )
    app.run()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
