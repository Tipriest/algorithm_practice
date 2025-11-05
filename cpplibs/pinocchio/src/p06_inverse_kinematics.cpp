#include <iostream>

#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/multibody/sample-models.hpp"
#include "pinocchio/spatial/explog.hpp"

int main(int /* argc */, char ** /* argv */) {
  // 创建一个机械臂模型
  pinocchio::Model model;
  pinocchio::buildModels::manipulator(model);
  pinocchio::Data data(model);

  // 定义目标关节ID和目标位姿
  const int JOINT_ID = 6; // 目标关节的ID
  const pinocchio::SE3 oMdes(Eigen::Matrix3d::Identity(),
                             Eigen::Vector3d(1., 0., 1.)); // 目标位姿

  // 初始化关节配置为中性位姿
  Eigen::VectorXd q = pinocchio::neutral(model);

  // 定义迭代算法的参数
  const double eps = 1e-4;  // 收敛误差阈值
  const int IT_MAX = 1000;  // 最大迭代次数
  const double DT = 1e-1;   // 时间步长
  const double damp = 1e-6; // 阻尼系数

  // 初始化雅可比矩阵和误差向量
  pinocchio::Data::Matrix6x J(6, model.nv); // 6xnv的雅可比矩阵
  J.setZero();

  bool success = false; // 标记是否成功收敛
  typedef Eigen::Matrix<double, 6, 1> Vector6d;
  Vector6d err;                // 误差向量
  Eigen::VectorXd v(model.nv); // 关节速度向量

  // 迭代求解逆运动学
  for (int i = 0;; i++) {
    // 1. 正向运动学计算当前关节配置下的位姿
    pinocchio::forwardKinematics(model, data, q);

    // 2. 计算当前位姿与目标位姿之间的误差
    const pinocchio::SE3 iMd =
        data.oMi[JOINT_ID].actInv(oMdes); // 当前位姿到目标位姿的变换
    err = pinocchio::log6(iMd).toVector(); // 将变换转换为李代数向量形式

    // 3. 检查误差是否小于阈值
    if (err.norm() < eps) {
      success = true;
      break;
    }

    // 4. 如果超过最大迭代次数，退出循环
    if (i >= IT_MAX) {
      success = false;
      break;
    }

    // 5. 计算目标关节的雅可比矩阵
    pinocchio::computeJointJacobian(model, data, q, JOINT_ID, J);

    // 6. 计算误差的李代数雅可比矩阵并更新雅可比矩阵
    pinocchio::Data::Matrix6 Jlog;
    pinocchio::Jlog6(iMd.inverse(), Jlog);
    J = -Jlog * J;

    // 7. 使用阻尼最小二乘法计算关节速度
    pinocchio::Data::Matrix6 JJt;
    JJt.noalias() = J * J.transpose();                    // 计算J * J^T
    JJt.diagonal().array() += damp;                       // 添加阻尼项
    v.noalias() = -J.transpose() * JJt.ldlt().solve(err); // 计算关节速度

    // 8. 更新关节配置
    q = pinocchio::integrate(model, q, v * DT);

    // 每10次迭代打印一次误差
    if (!(i % 10))
      std::cout << i << ": error = " << err.transpose() << std::endl;
  }

  // 打印收敛结果
  if (success) {
    std::cout << "Convergence achieved!" << std::endl;
  } else {
    std::cout << "\nWarning: the iterative algorithm has not reached "
                 "convergence to the desired precision"
              << std::endl;
  }

  // 打印最终结果
  std::cout << "\nresult: " << q.transpose() << std::endl;
  std::cout << "\nfinal error: " << err.transpose() << std::endl;
}