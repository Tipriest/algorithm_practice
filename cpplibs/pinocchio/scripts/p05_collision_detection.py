# 导入 Path 用于处理文件路径。
from pathlib import Path

# 导入 pinocchio 库
import pinocchio as pin

# --- 路径设置 ---
pinocchio_model_dir = Path("/opt/openrobots/share")

model_path = pinocchio_model_dir / "example-robot-data/robots"
mesh_dir = pinocchio_model_dir
urdf_filename = "romeo_small.urdf"
urdf_model_path = model_path / "romeo_description/urdf" / urdf_filename

# --- 模型加载 ---
# 从URDF加载运动学模型，并指定基座为自由浮动关节。
model = pin.buildModelFromUrdf(urdf_model_path, pin.JointModelFreeFlyer())

# 从URDF加载碰撞几何模型。
geom_model = pin.buildGeomFromUrdf(
    model, urdf_model_path, pin.GeometryType.COLLISION, mesh_dir
)

# --- 配置碰撞对 ---
# 添加所有可能的碰撞对。
geom_model.addAllCollisionPairs()
print("num collision pairs - initial:", len(geom_model.collisionPairs))

# 从SRDF（Semantic Robot Description Format）文件中读取信息，并移除不需要检测的碰撞对（例如，相邻连杆）。
srdf_filename = "romeo.srdf"
srdf_model_path = model_path / "romeo_description/srdf" / srdf_filename

pin.removeCollisionPairs(model, geom_model, srdf_model_path)
print(
    "num collision pairs - after removing useless collision pairs:",
    len(geom_model.collisionPairs),
)

# --- 加载参考配置 ---
# 从SRDF文件加载预定义的参考配置。
pin.loadReferenceConfigurations(model, srdf_model_path)

# 从模型中获取名为 "half_sitting" 的参考配置。
q = model.referenceConfigurations["half_sitting"]

# --- 创建数据结构 ---
data = model.createData()
geom_data = pin.GeometryData(geom_model)


# --- 碰撞检测 ---
# 计算所有已定义的碰撞对的碰撞状态。
# 最后一个参数 `False` 表示即使检测到碰撞也继续检查所有其他对。
pin.computeCollisions(model, data, geom_model, geom_data, q, False)

# 遍历所有碰撞对并打印其状态。
for k in range(len(geom_model.collisionPairs)):
    cr = geom_data.collisionResults[k]  # 碰撞结果
    cp = geom_model.collisionPairs[k]  # 碰撞对
    print(
        "collision pair:",
        cp.first,
        ",",
        cp.second,
        "- collision:",
        "Yes" if cr.isCollision() else "No",
    )

# --- 单独检测一个碰撞对 ---
# 首先更新所有几何体的位置。
pin.updateGeometryPlacements(model, data, geom_model, geom_data, q)
# 然后只计算索引为0的碰撞对。
pin.computeCollision(geom_model, geom_data, 0)
