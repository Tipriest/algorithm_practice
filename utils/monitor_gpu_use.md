# 现有工具对比

工具	| 特点	 | 是否满足你的需求
|---|---|---|
nvtop | 终端 TUI，GPU 显存/功耗/利用率 | 有曲线，但不是多子图桌面窗口
btop++ / glances | CPU/内存/GPU 综合监控 | 界面不错，但不是 matplotlib 式多子图
Grafana + Prometheus | 专业仪表盘，可定制 | 功能强，但部署较重
nvidia-smi dmon | 命令行实时 GPU 数据 | 纯文本，无图形界面

结论： 没有一个轻量工具能同时用「移动曲线 + 四个子图」展示 GPU 显存、GPU 功耗、内存、CPU。所以我已在 utils/monitor_gpu.py 里写好一个

程序功能
四个实时滚动子图：

GPU 显存 — 每张卡一条曲线（GiB），虚线为显存上限
GPU 功耗 — 每张卡一条曲线（W），虚线为功耗上限
系统内存 — 已用 / 总量
CPU 占用率 — 总占用，可选每核曲线
支持单卡/多卡，自动检测 NVIDIA GPU（优先 pynvml，回退到 nvidia-smi）。

## 安装与运行
```bash
# 依赖
pip install psutil matplotlib nvidia-ml-py3

# 运行（默认 1 秒刷新，保留 120 个数据点）
python utils/monitor_gpu.py

# 可选参数
python utils/monitor_gpu.py --interval 0.5 --history 300   # 0.5s 刷新，5 分钟历史
python utils/monitor_gpu.py --per-core                     # 同时显示每个 CPU 核心
```

## 打包为 AppImage（便携版）

可将程序打包成单个 AppImage 文件，复制到其他 Linux 电脑（同 CPU 架构，如 x86_64）即可直接运行，无需安装 Python 或 pip 依赖。

### 构建环境要求（仅打包时需要）

在 **Ubuntu 22.04** 上任选其一：

```bash
# 方式 A：系统 Python（推荐）
sudo apt install python3.10-venv python3-tk curl

# 方式 B：已安装 miniforge / mamba / conda 也可自动使用
```

### 一键构建

```bash
chmod +x packaging/appimage/build_appimage.sh
./packaging/appimage/build_appimage.sh
```

构建完成后产物位于：

```
packaging/appimage/dist/MonitorGPU-x86_64.AppImage
```

### 在其他电脑上使用

```bash
chmod +x MonitorGPU-x86_64.AppImage
./MonitorGPU-x86_64.AppImage

# 可选参数（与 Python 脚本相同）
./MonitorGPU-x86_64.AppImage --interval 0.5 --history 300
./MonitorGPU-x86_64.AppImage --per-core
```

### AppImage 注意事项

- **CPU 架构需一致**：在 x86_64 机器上构建的 AppImage 只能在 x86_64 Linux 上运行；ARM 机器需重新构建。
- **NVIDIA 驱动仍需目标机器安装**：AppImage 内置 Python/matplotlib/psutil/pynvml，但 `nvidia-smi` 和 GPU 驱动由系统提供，无法打包进 AppImage。
- **图形界面**：需要桌面环境（X11 或 Wayland）；SSH 远程请先设置 `DISPLAY` 或使用 X11 转发。
- **FUSE**：部分系统需安装 `libfuse2`（Ubuntu 22.04 通常已自带）；若无法挂载，可用：
  ```bash
  ./MonitorGPU-x86_64.AppImage --appimage-extract-and-run
  ```

### 打包相关文件

| 文件 | 说明 |
|------|------|
| `packaging/appimage/build_appimage.sh` | 一键构建脚本 |
| `packaging/appimage/monitor-gpu.spec` | PyInstaller 配置 |
| `packaging/appimage/monitor-gpu.desktop` | 桌面入口 |
| `packaging/appimage/requirements-build.txt` | 构建依赖 |

构建中间文件在 `packaging/appimage/build/`，可安全删除后重新构建。

若运行时报 `PIL._tkinter_finder` 或 `PyImagingPhoto` 相关错误，请重新执行构建脚本（新版本已打包完整 Pillow Tk 模块并做了 frozen 模式兼容）。

### 文件管理器里显示齿轮图标？

分两种情况：

1. **打包问题（已修复）**：旧版构建在没有 ImageMagick 时，会把 SVG 误当作 PNG 嵌入 AppImage，导致图标无法显示。现在仓库内提供真实的 `monitor-gpu.png`（256×256），重新构建即可。
2. **系统行为（仍可能出现）**：Ubuntu 22.04 的 Nautilus 对 AppImage 文件本身，有时仍显示默认「可执行文件/齿轮」图标，即使 AppImage 内已嵌入正确图标。这是桌面环境对 AppImage  MIME 类型支持有限，**属于常见现象**，不影响程序功能。

若希望在文件夹和应用菜单中都显示自定义图标，可以安装 [AppImageLauncher](https://github.com/TheAssassin/AppImageLauncher)，首次运行 AppImage 时选择「Integrate and run」，它会注册桌面入口和图标。

手动重新生成图标 PNG：

```bash
python packaging/appimage/generate_icon.py
```

## 注意事项
需要 NVIDIA 驱动 和 nvidia-smi 才能显示 GPU 数据；无 GPU 时 CPU/内存仍正常，GPU 子图为空。
若 pip install nvidia-ml-py3 后 GPU 采样会更稳定、更快。
AMD 显卡需改用 rocm-smi，当前脚本面向 NVIDIA。
若在无图形界面的 SSH 环境运行，需先设置 export DISPLAY=:0 或使用 X11 转发。
如果你希望改成 Web 页面（浏览器访问、手机也能看），或加上 磁盘 I/O / 网络流量，可以说一下，我可以继续扩展。