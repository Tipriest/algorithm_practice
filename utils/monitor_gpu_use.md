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

## 注意事项
需要 NVIDIA 驱动 和 nvidia-smi 才能显示 GPU 数据；无 GPU 时 CPU/内存仍正常，GPU 子图为空。
若 pip install nvidia-ml-py3 后 GPU 采样会更稳定、更快。
AMD 显卡需改用 rocm-smi，当前脚本面向 NVIDIA。
若在无图形界面的 SSH 环境运行，需先设置 export DISPLAY=:0 或使用 X11 转发。
如果你希望改成 Web 页面（浏览器访问、手机也能看），或加上 磁盘 I/O / 网络流量，可以说一下，我可以继续扩展。