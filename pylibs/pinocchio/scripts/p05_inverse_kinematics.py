# 导入 numpy 用于数值计算
import numpy as np

# 导入 pinocchio 库
import pinocchio

# 从 numpy.linalg 导入 norm (计算范数) 和 solve (解线性方程组)
from numpy.linalg import norm, solve

# --- 模型和数据设置 ---
# 创建一个简单的机械臂示例模型
model = pinocchio.buildSampleModelManipulator()
data = model.createData()

# --- 逆运动学（IK）参数设置 ---
JOINT_ID = 6  # 目标关节（末端执行器）的ID
# 定义末端执行器的目标位姿 (旋转矩阵 + 位置向量)
oMdes = pinocchio.SE3(np.eye(3), np.array([1.0, 0.0, 1.0]))

# --- 迭代算法参数 ---
q = pinocchio.neutral(model)  # 初始关节角度设置为中性位姿
eps = 1e-4  # 收敛的误差阈值
IT_MAX = 1000  # 最大迭代次数
DT = 1e-1  # 积分步长
damp = 1e-12  # 阻尼系数，用于防止雅可比矩阵奇异

i = 0
while True:
    # 1. 正向运动学：根据当前关节角度 q 计算所有关节的位姿
    pinocchio.forwardKinematics(model, data, q)

    # 2. 计算误差：
    # iMd 是从当前位姿到目标位姿的变换
    iMd = data.oMi[JOINT_ID].actInv(oMdes)
    # err 是该变换在李代数空间中的向量表示，代表了位姿误差
    err = pinocchio.log(iMd).vector

    # 3. 检查收敛条件
    if norm(err) < eps:
        success = True
        break
    if i >= IT_MAX:
        success = False
        break

    # 4. 计算雅可比矩阵
    # J 是目标关节在关节坐标系下的雅可比矩阵
    J = pinocchio.computeJointJacobian(model, data, q, JOINT_ID)

    # 5. 计算关节速度
    # Jlog6 用于将关节坐标系下的雅可比矩阵转换到误差所在的李代数空间
    J = -np.dot(pinocchio.Jlog6(iMd.inverse()), J)
    # 使用阻尼最小二乘法求解关节速度 v = -J_pinv * err
    # J_pinv = J.T * (J * J.T + damp * I)^-1
    v = -J.T.dot(solve(J.dot(J.T) + damp * np.eye(6), err))

    # 6. 更新关节角度
    # 使用 integrate 函数沿计算出的关节速度方向更新关节角度
    q = pinocchio.integrate(model, q, v * DT)

    if not i % 10:
        print(f"{i}: error = {err.T}")
    i += 1

# --- 打印结果 ---
if success:
    print("Convergence achieved!")
else:
    print(
        "\n"
        "Warning: the iterative algorithm has not reached convergence "
        "to the desired precision"
    )

print(f"\nresult: {q.flatten().tolist()}")
print(f"\nfinal error: {err.T}")
