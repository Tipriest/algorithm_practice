/**
 * @file main.cpp
 * @brief 计算机器人动力学的简单程序
 * @date 2025-10-16
 */
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <iostream>
#include <pinocchio/algorithm/rnea.hpp>
#include <pinocchio/multibody/sample-models.hpp>

int main() {
  pinocchio::Model model;
  pinocchio::buildModels::manipulator(model);
  pinocchio::Data data(model);

  Eigen::VectorXd q = pinocchio::neutral(model);
  Eigen::VectorXd v = Eigen::VectorXd::Zero(model.nv);
  Eigen::VectorXd a = Eigen::VectorXd::Zero(model.nv);

  const Eigen::VectorXd &tau = pinocchio::rnea(model, data, q, v, a);
  std::cout << "tau = " << tau.transpose() << std::endl;
}