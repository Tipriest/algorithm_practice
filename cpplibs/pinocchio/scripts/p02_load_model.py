# 导入 Path 用于处理文件路径，导入 sys 用于处理命令行参数。
from pathlib import Path
from sys import argv
 
# 导入 pinocchio 库
import pinocchio
 
# --- 路径设置 ---
# 定义包含 Pinocchio 模型文件的目录路径。
pinocchio_model_dir = Path("/opt/openrobots/share")
 
# 设置要加载的URDF文件的路径。
# 如果程序启动时没有提供命令行参数，则使用默认的UR5机器人URDF文件路径。
# 如果提供了命令行参数，则使用第一个参数作为URDF文件路径。
urdf_filename = (
    pinocchio_model_dir / "example-robot-data/robots/ur_description/urdf/ur5_robot.urdf"
    if len(argv) < 2
    else argv[1]
)
 
# --- 模型加载与数据创建 ---
# 从指定的URDF文件解析并构建机器人运动学/动力学模型。
model = pinocchio.buildModelFromUrdf(urdf_filename)
print("model name: " + model.name)
 
# 基于加载的模型，创建一个Data对象，用于存储算法计算的中间结果。
data = model.createData()
 
# --- 运动学计算 ---
# `randomConfiguration` 函数会根据模型中定义的关节限制生成一个随机的关节角度向量 `q`。
q = pinocchio.randomConfiguration(model)
print(f"q: {q.T}")
 
# `forwardKinematics` 函数会根据给定的关节配置 `q`，计算机器人模型中每个关节相对于世界坐标系的位姿。
# 计算结果会更新到 `data` 对象中。
pinocchio.forwardKinematics(model, data, q)
 
# --- 打印结果 ---
# 遍历模型中的所有关节，并打印它们的名称和在世界坐标系下的位置（平移向量）。
# `data.oMi` 存储了每个关节坐标系相对于世界坐标系（origin）的变换矩阵（SE3类型）。
for name, oMi in zip(model.names, data.oMi):
    print("{:<24} : {: .2f} {: .2f} {: .2f}".format(name, *oMi.translation.T.flat))