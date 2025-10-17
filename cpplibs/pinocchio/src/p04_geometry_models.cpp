/**
 * @file p04_geometry_models.cpp
 * @brief
 * 这个代码目前没办法直接通过F5进行一键编译&调试，因为直接使用F5键带有preLaunchTask的话，
 * 是需要调用tasks.json中的compile_with_pinocchio方法使用g++进行编译的，
 * 但是使用g++编译需要自己手动指定过程的-I -L
 * -l等编译参数，目前直接编译会出现一个与urdf解析
 * 相关的函数链接不到的问题，我推测是与hpp-fcl改名为coal有关的一个问题，
 * 但是尝试了一些办法还没有解决
 * 虽然使用g++编译有问题，但是使用CMake的方法是没有问题的，因此可以使用CMake生成可执行文件后，
 * 放置在该源文件路径下使用F5进行调试(需要按照launch.json文件中的说明将preLaunchTask注释掉)，
 * 然后就可以正常进行调试了
 * @date 2025-10-17
 *
 * @copyright Copyright (C) 2025, Tipriest, all rights reserved.
 *
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Author  <th>Description
 * <tr><td>2025-10-17 <td>Tipriest  <td>
 * </table>
 */
// 引入Pinocchio与FCL（Flexible Collision
// Library）集成的相关头文件，用于处理碰撞几何体。
#include "pinocchio/multibody/fcl.hpp"
// 引入Pinocchio库中用于解析URDF文件的头文件。
#include "pinocchio/parsers/urdf.hpp"

// 引入Pinocchio库中用于几何计算的头文件，例如更新几何体的位置。
#include "pinocchio/algorithm/geometry.hpp"
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

  // --- 设置路径 ---
  // 如果没有通过命令行参数提供路径，则使用默认路径。
  // model_path 指向包含机器人描述文件的目录。
  const std::string model_path =
      (argc <= 1)
          ? PINOCCHIO_MODEL_DIR + std::string("/example-robot-data/robots")
          : argv[1];
  // mesh_dir 指向包含模型网格文件（如.stl, .dae）的根目录。
  const std::string mesh_dir = (argc <= 1) ? PINOCCHIO_MODEL_DIR : argv[1];
  // urdf_filename 是完整的URDF文件路径。
  const std::string urdf_filename =
      model_path + "/ur_description/urdf/ur5_robot.urdf";

  // --- 加载模型 ---
  // 1. 加载运动学和动力学模型
  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);

  // 2. 加载碰撞模型
  // GeometryModel 用于存储机器人的几何信息，如碰撞体或可视化形状。
  GeometryModel collision_model;
  // 从URDF文件加载碰撞几何信息。`COLLISION`参数指定只加载<collision>标签下的几何体。
  // mesh_dir 用于解析URDF中以 "package://" 开头的网格文件路径。
  pinocchio::urdf::buildGeom(model, urdf_filename, COLLISION, collision_model,
                             mesh_dir);

  // 3. 加载可视化模型
  GeometryModel visual_model;
  // 从URDF文件加载可视化几何信息。`VISUAL`参数指定只加载<visual>标签下的几何体。
  pinocchio::urdf::buildGeom(model, urdf_filename, VISUAL, visual_model,
                             mesh_dir);
  std::cout << "model name: " << model.name << std::endl;

  // --- 创建数据结构 ---
  // 为运动学/动力学算法创建Data对象。
  Data data(model);
  // 为碰撞几何模型创建GeometryData对象，用于存储碰撞计算的中间结果。
  GeometryData collision_data(collision_model);
  // 为可视化几何模型创建GeometryData对象。
  GeometryData visual_data(visual_model);

  // --- 运动学计算 ---
  // 生成一个随机的关节配置q。
  Eigen::VectorXd q = randomConfiguration(model);
  std::cout << "q: " << q.transpose() << std::endl;

  // 执行正向运动学，计算每个关节的位姿。结果存储在`data`中。
  forwardKinematics(model, data, q);

  // 更新几何模型中所有几何体的位置。
  // 这个函数利用`forwardKinematics`计算出的关节位姿来更新每个碰撞体和可视化物体在世界坐标系中的位姿。
  updateGeometryPlacements(model, data, collision_model, collision_data);
  updateGeometryPlacements(model, data, visual_model, visual_data);

  // --- 打印结果 ---
  // 打印每个关节的位姿。
  std::cout << "\nJoint placements:" << std::endl;
  for (JointIndex joint_id = 0; joint_id < (JointIndex)model.njoints;
       ++joint_id)
    std::cout << std::setw(24) << std::left << model.names[joint_id] << ": "
              << std::fixed
              << std::setprecision(2)
              // data.oMi[joint_id] 存储了关节坐标系相对于世界坐标系的变换。
              << data.oMi[joint_id].translation().transpose() << std::endl;

  // 打印每个碰撞几何体的位置。
  std::cout << "\nCollision object placements:" << std::endl;
  for (GeomIndex geom_id = 0; geom_id < (GeomIndex)collision_model.ngeoms;
       ++geom_id)
    std::cout << geom_id << ": " << std::fixed
              << std::setprecision(2)
              // collision_data.oMg[geom_id]
              // 存储了碰撞体坐标系相对于世界坐标系的变换。
              << collision_data.oMg[geom_id].translation().transpose()
              << std::endl;

  // 打印每个可视化几何体的位置。
  std::cout << "\nVisual object placements:" << std::endl;
  for (GeomIndex geom_id = 0; geom_id < (GeomIndex)visual_model.ngeoms;
       ++geom_id)
    std::cout << geom_id << ": " << std::fixed
              << std::setprecision(2)
              // visual_data.oMg[geom_id]
              // 存储了可视化物体坐标系相对于世界坐标系的变换。
              << visual_data.oMg[geom_id].translation().transpose()
              << std::endl;
}