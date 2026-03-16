#
# 在这个简短的脚本中，我们展示了如何使用 RobotWrapper
# 来集成不同类型的可视化查看器。
#

from pathlib import Path
from sys import argv

import pinocchio as pin

# 导入 RobotWrapper，这是一个方便的类，封装了模型、数据和可视化。
from pinocchio.robot_wrapper import RobotWrapper
from pinocchio.visualize import GepettoVisualizer, MeshcatVisualizer

# --- 选择可视化工具 ---
# 如果你想在这个例子中可视化机器人，
# 你可以通过命令行指定一个选项来选择使用哪个可视化工具：
# GepettoVisualizer: -g
# MeshcatVisualizer: -m
VISUALIZER = None
if len(argv) > 1:
    opt = argv[1]
    if opt == "-g":
        VISUALIZER = GepettoVisualizer
    elif opt == "-m":
        VISUALIZER = MeshcatVisualizer
    else:
        raise ValueError("Unrecognized option: " + opt)

# --- 使用 RobotWrapper 加载模型 ---
# 使用 RobotWrapper 加载 URDF 模型。
pinocchio_model_dir = Path("/opt/openrobots/share")

model_path = pinocchio_model_dir / "example-robot-data/robots"
mesh_dir = pinocchio_model_dir
urdf_filename = "talos_reduced.urdf"
urdf_model_path = model_path / "talos_data/robots" / urdf_filename

# BuildFromURDF 是一个工厂方法，它会处理模型和几何体的加载。
robot = RobotWrapper.BuildFromURDF(
    urdf_model_path, mesh_dir, pin.JointModelFreeFlyer()
)

# --- 使用 RobotWrapper ---
# 为方便起见，创建模型和数据的别名。
model = robot.model
data = robot.data

# 做任何你想做的事，例如，计算以世界坐标系表示的质心位置。
q0 = robot.q0  # RobotWrapper 会自动计算中性位姿 q0
com = robot.com(q0)

# 上一个命令类似于直接调用 pinocchio 函数：
com2 = pin.centerOfMass(model, data, q0)

# --- 可视化 ---
# 使用你选择的可视化工具显示模型。
if VISUALIZER:
    robot.setVisualizer(VISUALIZER())
    robot.initViewer()
    robot.loadViewerModel("pinocchio")
    robot.display(q0)
