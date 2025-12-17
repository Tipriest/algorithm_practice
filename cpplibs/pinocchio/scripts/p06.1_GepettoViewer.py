# 注意：这个例子需要安装 gepetto-gui
# 使用方法：先启动 gepetto-gui，然后运行此脚本

import sys
from pathlib import Path

import pinocchio as pin

# 导入 Gepetto 可视化工具
from pinocchio.visualize import GepettoVisualizer

# --- 模型加载 ---
# 加载URDF模型。
pinocchio_model_dir = Path("/opt/openrobots/share")

model_path = pinocchio_model_dir / "example-robot-data/robots"
mesh_dir = pinocchio_model_dir
urdf_filename = "talos_reduced.urdf"
urdf_model_path = model_path / "talos_data/robots" / urdf_filename

# 从URDF文件构建运动学、碰撞和可视化模型。
model, collision_model, visual_model = pin.buildModelsFromUrdf(
    urdf_model_path, mesh_dir, pin.JointModelFreeFlyer()
)
# 创建GepettoVisualizer实例。
viz = GepettoVisualizer(model, collision_model, visual_model)

# --- 初始化和加载模型到查看器 ---
# 初始化查看器。这会尝试连接到正在运行的gepetto-gui服务。
try:
    viz.initViewer()
except ImportError as err:
    print(
        "Error while initializing the viewer. "
        "It seems you should install gepetto-viewer"
    )
    print(err)
    sys.exit(0)

# 在查看器中加载机器人模型。
try:
    viz.loadViewerModel("pinocchio")
except AttributeError as err:
    print(
        "Error while loading the viewer model. "
        "It seems you should start gepetto-viewer"
    )
    print(err)
    sys.exit(0)

# --- 显示机器人 ---
# 显示一个机器人位形。
q0 = pin.neutral(model)  # 获取中性位姿
viz.display(q0)

# 显示另一个机器人。
# 创建第二个GepettoVisualizer实例。
viz2 = GepettoVisualizer(model, collision_model, visual_model)
# 使用与第一个实例相同的查看器窗口。
viz2.initViewer(viz.viewer)
# 以不同的根节点名称加载模型，以避免与第一个机器人冲突。
viz2.loadViewerModel(rootNodeName="pinocchio2")
q = q0.copy()
q[1] = 1.0  # 修改位姿以示区别
viz2.display(q)
