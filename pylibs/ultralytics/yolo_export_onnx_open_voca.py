import torch
import os


def export_yolov11_opset12_onnx(
    weights_path: str,
    onnx_path: str = "yolov11n_opset12.onnx",
    img_size=(640, 640),
    device="cpu",
):
    device = torch.device(device)

    # 1. 加载 YOLOv11 模型
    # 如果你用的是 Ultralytics:
    #   from ultralytics import YOLO
    #   yolo = YOLO(weights_path)
    #   model = yolo.model  # nn.Module
    #
    # 如果你是自己写的网络，则按自己的方式构建后 load_state_dict。
    #
    # 这里用占位示例，你需要改成你自己的加载逻辑：
    from ultralytics import YOLO

    yolo = YOLO(weights_path)  # e.g. "yolo11n.pt"
    model = yolo.model  # nn.Module 真正的网络结构

    model.to(device)
    model.eval()

    # 2. 构造 dummy input
    dummy_input = torch.randn(1, 3, img_size[0], img_size[1], device=device)

    # 3. 确保使用 torch.onnx.export（非 dynamo_export）
    dynamic_axes = {
        "images": {0: "batch", 2: "height", 3: "width"},
        "output": {0: "batch"},
    }

    torch.onnx.export(
        model,  # 注意是 yolo.model，不是 yolo 本身
        dummy_input,
        onnx_path,
        export_params=True,
        opset_version=12,  # 显式设为 12
        do_constant_folding=True,
        input_names=["images"],
        output_names=["output"],
        dynamic_axes=dynamic_axes,
    )

    print(f"ONNX saved to: {os.path.abspath(onnx_path)}")

    # 4. 验证 ONNX 的 opset 是否真的是 12
    import onnx

    m = onnx.load(onnx_path)
    print("opset_import:", m.opset_import)


def export_yoloworld(
    # # weights_path: str,
    # onnx_path: str = "yolov11n_opset12.onnx",
    # img_size=(640, 640),
    # device="cpu",
):
    # device = torch.device(device)

    # 1. 加载 YOLOv11 模型
    # 如果你用的是 Ultralytics:
    from ultralytics import YOLO

    # Load the YOLO26 model
    model = YOLO("yoloe-v8l-seg.pt")

    # Export the model to ONNX format
    model.export(format="onnx")  # creates 'yolo26n.onnx'

    # Load the exported ONNX model
    onnx_model = YOLO("yoloe-v8l-seg.onnx")

    # Run inference
    results = onnx_model("https://ultralytics.com/images/bus.jpg")
    #
    # 如果你是自己写的网络，则按自己的方式构建后 load_state_dict。
    #
    # 这里用占位示例，你需要改成你自己的加载逻辑：
    # from ultralytics import YOLO

    # yolo = YOLO(weights_path)  # e.g. "yolo11n.pt"
    # model = yolo.model  # nn.Module 真正的网络结构

    # model.to(device)
    # model.eval()

    # # 2. 构造 dummy input
    # dummy_input = torch.randn(1, 3, img_size[0], img_size[1], device=device)

    # # 3. 确保使用 torch.onnx.export（非 dynamo_export）
    # dynamic_axes = {
    #     "images": {0: "batch", 2: "height", 3: "width"},
    #     "output": {0: "batch"},
    # }

    # torch.onnx.export(
    #     model,  # 注意是 yolo.model，不是 yolo 本身
    #     dummy_input,
    #     onnx_path,
    #     export_params=True,
    #     opset_version=12,  # 显式设为 12
    #     do_constant_folding=True,
    #     input_names=["images"],
    #     output_names=["output"],
    #     dynamic_axes=dynamic_axes,
    # )

    # print(f"ONNX saved to: {os.path.abspath(onnx_path)}")

    # 4. 验证 ONNX 的 opset 是否真的是 12
    # import onnx

    # m = onnx.load(onnx_path)
    # print("opset_import:", m.opset_import)

if __name__ == "__main__":
    # export_yolov11_opset12_onnx(
    #     weights_path="/home/tipriest/Downloads/yolo_results/yolo11_l_best.pt",  # 修改为你的 .pt 路径
    #     onnx_path="/home/tipriest/Downloads/yolo_results/yolo11_l_best.onnx",
    #     img_size=(640, 640),
    #     device="cpu",
    # )
    export_yoloworld()
