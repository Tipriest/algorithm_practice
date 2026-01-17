import torch
from segment_anything import sam_model_registry, SamPredictor
from segment_anything.utils.onnx import SamOnnxModel
import warnings

# 加载原来的pth模型
checkpoint = "sam_vit_b_01ec64.pth"  # 参数路径
model_type = "vit_b"  # 模型类
sam = sam_model_registry[model_type](
    checkpoint=checkpoint
)  # sam创建与预训练参数加载

onnx_model_path = "sam_onnx_example.onnx"  # onnx模型输出路径
onnx_model = SamOnnxModel(
    sam, return_single_mask=True
)  # 一个新模型，输入为加载预训练参数的sam

# 动态轴定义,表示模型输入点个数可变
dynamic_axes = {
    "point_coords": {1: "num_points"},
    "point_labels": {1: "num_points"},
}

embed_dim = sam.prompt_encoder.embed_dim  # 嵌入维度: 256
embed_size = sam.prompt_encoder.image_embedding_size  # 嵌入的图像大小 [64,64]
mask_input_size = [4 * x for x in embed_size]  # 输入mask的大小 [256, 256]

# onnx的输入参数名称、大小与类型定义
dummy_inputs = {
    "image_embeddings": torch.randn(
        1, embed_dim, *embed_size, dtype=torch.float
    ),  # 图像嵌入维度
    "point_coords": torch.randint(
        low=0, high=1024, size=(1, 5, 2), dtype=torch.float
    ),  # 输入点的坐标
    "point_labels": torch.randint(
        low=0, high=4, size=(1, 5), dtype=torch.float
    ),  # 输入点的标签
    "mask_input": torch.randn(
        1, 1, *mask_input_size, dtype=torch.float
    ),  # 输入mask
    "has_mask_input": torch.tensor([1], dtype=torch.float),  # 是否有mask输入
    "orig_im_size": torch.tensor(
        [1500, 2250], dtype=torch.float
    ),  # 图像原始大小
}
# onnx的输出参数名称
output_names = ["masks", "iou_predictions", "low_res_masks"]

# 利用torch.onnx.export导出onnx模型
with warnings.catch_warnings():
    warnings.filterwarnings("ignore", category=torch.jit.TracerWarning)
    warnings.filterwarnings("ignore", category=UserWarning)
    with open(onnx_model_path, "wb") as f:
        torch.onnx.export(
            onnx_model,  # 要导出的PyTorch模型
            tuple(dummy_inputs.values()),  # 模型的输入数据
            f,  # noox模型的数据将被写入这个文件
            export_params=True,  # 是否导出模型参数, 默认为True。
            verbose=False,  # 是否打印日志信息
            opset_version=17,  # noox操作符集（opset）的版本
            do_constant_folding=True,  # 是否执行常量折叠优化，这可以简化模型并可能提高性能。
            input_names=list(dummy_inputs.keys()),  # 输入的名称列表
            output_names=output_names,  # 输出的名称列表
            dynamic_axes=dynamic_axes,  # 动态轴定义。动态轴允许在模型运行时改变某些维度的大小。这是一个字典，其键是输入或输出的名称，值是一个字典，表示哪些维度是动态的。
        )
