# 导入 pinocchio 库
import pinocchio
 
# 1. 模型构建
# 使用 pinocchio 内置的函数创建一个简单的机械臂示例模型。
model = pinocchio.buildSampleModelManipulator()
# 基于创建的模型，实例化一个 Data 对象。
# Data 对象用于存储算法计算过程中的中间变量和结果，以提高计算效率。
data = model.createData()
 
# 2. 设置机器人状态
# 获取模型的中性位姿（通常是所有关节角度为0的位置）作为当前关节位置 q。
q = pinocchio.neutral(model)
# 创建一个维度与模型速度自由度(nv)相同的零向量，作为当前关节速度 v。
v = pinocchio.utils.zero(model.nv)
# 创建一个维度与模型加速度自由度(nv)相同的零向量，作为当前关节加速度 a。
a = pinocchio.utils.zero(model.nv)
 
# 3. 动力学计算
# 调用 rnea 函数，使用递归牛顿-欧拉算法（Recursive Newton-Euler Algorithm, RNEA）计算逆动力学。
# 该函数根据给定的模型、数据、关节位置(q)、速度(v)和加速度(a)，计算出驱动机器人产生该运动所需的关节力矩(tau)。
tau = pinocchio.rnea(model, data, q, v, a)

# 4. 输出结果
# 将计算得到的关节力矩向量打印到控制台。
print("tau = ", tau.T)