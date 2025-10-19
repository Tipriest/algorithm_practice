# 导入 Path 用于处理文件路径，导入 sys 用于处理命令行参数。
from pathlib import Path
from sys import argv
 
# 导入 pinocchio 库
import pinocchio
 
# --- 路径设置 ---
# 定义包含 Pinocchio 模型文件的目录路径。
pinocchio_model_dir = Path("/opt/openrobots/share") 
# 如果没有通过命令行参数提供路径，则使用默认路径。
model_path = Path(
    (pinocchio_model_dir / "example-robot-data/robots") if len(argv) < 2 else argv[1]
)
# mesh_dir 指向包含模型网格文件（如.stl, .dae）的根目录。
mesh_dir = pinocchio_model_dir
# urdf_filename 是完整的URDF文件路径。
urdf_model_path = model_path / "ur_description/urdf/ur5_robot.urdf"
 
# --- 模型加载 ---
# 从URDF文件加载运动学/动力学模型(model)、碰撞模型(collision_model)和可视化模型(visual_model)。
model, collision_model, visual_model = pinocchio.buildModelsFromUrdf(
    urdf_model_path, mesh_dir
)
print("model name: " + model.name)
 
# --- 创建数据结构 ---
# 为三种模型创建对应的Data对象，用于存储算法计算的中间结果。
data, collision_data, visual_data = pinocchio.createDatas(
    model, collision_model, visual_model
)
 
# --- 运动学计算 ---
# 生成一个随机的关节配置q。
q = pinocchio.randomConfiguration(model)
print(f"q: {q.T}")
 
# 执行正向运动学，计算每个关节的位姿。结果存储在`data`中。
pinocchio.forwardKinematics(model, data, q)
 
# --- 更新几何模型 ---
# 这个函数利用`forwardKinematics`计算出的关节位姿来更新每个碰撞体和可视化物体在世界坐标系中的位姿。
pinocchio.updateGeometryPlacements(model, data, collision_model, collision_data)
pinocchio.updateGeometryPlacements(model, data, visual_model, visual_data)
 
# --- 打印结果 ---
# 打印每个关节的位姿。
print("\nJoint placements:")
for name, oMi in zip(model.names, data.oMi):
    print("{:<24} : {: .2f} {: .2f} {: .2f}".format(name, *oMi.translation.T.flat))
 
# 打印每个碰撞几何体的位置。
print("\nCollision object placements:")
for k, oMg in enumerate(collision_data.oMg):
    print("{:d} : {: .2f} {: .2f} {: .2f}".format(k, *oMg.translation.T.flat))
 
# 打印每个可视化几何体的位置。
print("\nVisual object placements:")
for k, oMg in enumerate(visual_data.oMg):
    print("{:d} : {: .2f} {: .2f} {: .2f}".format(k, *oMg.translation.T.flat))
