/**
 * @file main.cpp
 * @brief 计算机器人动力学的简单程序
 * @date 2025-10-16
 */
// 引入Pinocchio库中用于处理关节配置的头文件，例如计算中性位姿。
#include "pinocchio/algorithm/joint-configuration.hpp"
// 引入C++标准库中的输入输出流，用于在控制台打印信息。
#include <iostream>
// 引入Pinocchio库中实现递归牛顿-欧拉算法（Recursive Newton-Euler Algorithm,
// RNEA）的头文件。
#include <pinocchio/algorithm/rnea.hpp>
// 引入Pinocchio库中用于构建示例模型的头文件，方便快速测试。
#include <pinocchio/multibody/sample-models.hpp>

int main() {
  // 1. 模型构建
  // 创建一个空的Pinocchio模型对象。Model对象存储了机器人的运动学和动力学参数，如连杆、关节、惯性等。
  pinocchio::Model model;
  // 使用Pinocchio提供的示例模型构建函数，创建一个简单的机械臂模型。
  pinocchio::buildModels::manipulator(model);
  // 基于创建的模型，实例化一个Data对象。Data对象用于存储RNEA等算法计算过程中的中间变量和结果，以提高计算效率。
  pinocchio::Data data(model);

  // 2. 设置机器人状态
  // 获取模型的中性位姿（通常是所有关节角度为0的位置）作为当前关节位置q。
  Eigen::VectorXd q = pinocchio::neutral(model);
  std::cout << "模型的中性位姿(通常是所有关节角度为0的位置)" << q.transpose()
            << std::endl;
  // 创建一个维度与模型速度自由度(nv)相同的零向量，作为当前关节速度v。
  Eigen::VectorXd v = Eigen::VectorXd::Zero(model.nv);
  // 创建一个维度与模型加速度自由度(nv)相同的零向量，作为当前关节加速度a。
  Eigen::VectorXd a = Eigen::VectorXd::Zero(model.nv);

  // 3. 动力学计算
  // 调用rnea函数，使用递归牛顿-欧拉算法计算逆动力学。
  // 该函数根据给定的模型(model)、关节位置(q)、速度(v)和加速度(a)，计算出驱动机器人产生该运动所需的关节力矩(tau)。
  // 计算结果存储在data对象中，并由函数返回一个常量引用。
  const Eigen::VectorXd &tau = pinocchio::rnea(model, data, q, v, a);

  // 4. 输出结果
  // 将计算得到的关节力矩向量打印到标准输出流（控制台）。
  // .transpose() 是为了方便在单行中显示向量。
  std::cout << "tau = " << tau.transpose() << std::endl;
}