from ultralytics import SAM

# 加载官方标准 SAM 模型（可选：sam_b.pt / sam_l.pt / sam_h.pt）
model = SAM("sam_l.pt")

# 导出为 ONNX 格式，可根据需要调整参数
model.export(
    format="onnx",
    dynamic=True,  # 动态批大小与分辨率
    simplify=True,  # 尝试简化 ONNX 计算图
)
