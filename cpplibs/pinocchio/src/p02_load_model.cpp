// 引入Pinocchio库中用于解析URDF文件的头文件。
#include "pinocchio/parsers/urdf.hpp"

// 引入Pinocchio库中用于处理关节配置的头文件，例如生成随机位姿。
#include "pinocchio/algorithm/joint-configuration.hpp"
// 引入Pinocchio库中用于运动学计算的头文件，例如正向运动学。
#include "pinocchio/algorithm/kinematics.hpp"

// 引入C++标准库中的输入输出流，用于在控制台打印信息。
#include <iostream>

// PINOCCHIO_MODEL_DIR
// 是一个宏，通常由CMake在编译时定义，指向存放模型文件的目录。
// 如果CMake没有定义这个宏，这里提供一个默认路径。
// 您可以根据自己的模型文件存放位置修改此路径。
#ifndef PINOCCHIO_MODEL_DIR
#define PINOCCHIO_MODEL_DIR "/opt/openrobots/share"
#endif

int main(int argc, char **argv) {
  // 使用pinocchio命名空间，这样就不需要在每次调用Pinocchio函数时都写
  // `pinocchio::` 前缀。
  using namespace pinocchio;

  // 设置要加载的URDF文件的路径。
  // 如果程序启动时没有提供命令行参数（argc <=
  // 1），则使用默认的UR5机器人URDF文件路径。
  // 如果提供了命令行参数，则使用第一个参数作为URDF文件路径。
  const std::string urdf_filename =
      (argc <= 1) ? PINOCCHIO_MODEL_DIR +
                        std::string("/example-robot-data/robots/ur_description/"
                                    "urdf/ur5_robot.urdf")
                  : argv[1];

  // 1. 从URDF文件加载模型
  // 创建一个空的模型对象。
  Model model;
  // 调用 `buildModel` 函数，从指定的URDF文件解析并构建机器人模型。
  pinocchio::urdf::buildModel(urdf_filename, model, true);
  // 打印加载的模型的名称。
  std::cout << "model name: " << model.name << std::endl;

  // 2. 创建算法所需的数据结构
  // 基于加载的模型，创建一个Data对象。这个对象将用于存储所有算法计算的中间结果，
  // 如关节的位姿、速度、雅可比矩阵等，以避免重复计算。
  Data data(model);

  // 3. 生成一个随机的关节配置
  // `randomConfiguration`
  // 函数会根据模型中定义的关节限制（最小值和最大值）生成一个随机的关节角度向量
  // `q`。
  Eigen::VectorXd q = randomConfiguration(model);
  std::cout << "q: " << q.transpose() << std::endl;

  // 4. 执行正向运动学计算
  // `forwardKinematics` 函数会根据给定的关节配置
  // `q`，计算机器人模型中每个关节相对于世界坐标系的位姿（位置和姿态）。
  // 计算结果会更新到 `data` 对象中。
  forwardKinematics(model, data, q);

  // 5. 打印每个关节的位置
  // 遍历模型中的所有关节。
  for (JointIndex joint_id = 0; joint_id < (JointIndex)model.njoints;
       ++joint_id)
    // 打印关节的名称和其在世界坐标系下的位置（平移向量）。
    // `data.oMi[joint_id]` 存储了第 `joint_id`
    // 个关节坐标系相对于世界坐标系（origin）的变换矩阵（SE3类型）。
    // `.translation()` 获取该变换的平移部分。
    std::cout << std::setw(24) << std::left << model.names[joint_id] << ": "
              << std::fixed << std::setprecision(2)
              << data.oMi[joint_id].translation().transpose() << std::endl;
}