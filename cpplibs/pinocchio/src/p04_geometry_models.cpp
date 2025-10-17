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
#include "pinocchio/multibody/fcl.hpp"
#include "pinocchio/parsers/urdf.hpp"

#include "pinocchio/algorithm/geometry.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"

#include <iostream>

// PINOCCHIO_MODEL_DIR is defined by the CMake but you can define your own
// directory here.
#ifndef PINOCCHIO_MODEL_DIR
#define PINOCCHIO_MODEL_DIR "/opt/openrobots/share"
#endif

int main(int argc, char **argv) {
  using namespace pinocchio;

  const std::string model_path =
      (argc <= 1)
          ? PINOCCHIO_MODEL_DIR + std::string("/example-robot-data/robots")
          : argv[1];
  const std::string mesh_dir = (argc <= 1) ? PINOCCHIO_MODEL_DIR : argv[1];
  const std::string urdf_filename =
      model_path + "/ur_description/urdf/ur5_robot.urdf";

  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  GeometryModel collision_model;
  pinocchio::urdf::buildGeom(model, urdf_filename, COLLISION, collision_model,
                             mesh_dir);
  GeometryModel visual_model;
  pinocchio::urdf::buildGeom(model, urdf_filename, VISUAL, visual_model,
                             mesh_dir);
  std::cout << "model name: " << model.name << std::endl;

  // Create data required by the algorithms
  Data data(model);
  GeometryData collision_data(collision_model);
  GeometryData visual_data(visual_model);

  // Sample a random configuration
  Eigen::VectorXd q = randomConfiguration(model);
  std::cout << "q: " << q.transpose() << std::endl;

  // Perform the forward kinematics over the kinematic tree
  forwardKinematics(model, data, q);

  // Update Geometry models
  updateGeometryPlacements(model, data, collision_model, collision_data);
  updateGeometryPlacements(model, data, visual_model, visual_data);

  // Print out the placement of each joint of the kinematic tree
  std::cout << "\nJoint placements:" << std::endl;
  for (JointIndex joint_id = 0; joint_id < (JointIndex)model.njoints;
       ++joint_id)
    std::cout << std::setw(24) << std::left << model.names[joint_id] << ": "
              << std::fixed << std::setprecision(2)
              << data.oMi[joint_id].translation().transpose() << std::endl;

  // Print out the placement of each collision geometry object
  std::cout << "\nCollision object placements:" << std::endl;
  for (GeomIndex geom_id = 0; geom_id < (GeomIndex)collision_model.ngeoms;
       ++geom_id)
    std::cout << geom_id << ": " << std::fixed << std::setprecision(2)
              << collision_data.oMg[geom_id].translation().transpose()
              << std::endl;

  // Print out the placement of each visual geometry object
  std::cout << "\nVisual object placements:" << std::endl;
  for (GeomIndex geom_id = 0; geom_id < (GeomIndex)visual_model.ngeoms;
       ++geom_id)
    std::cout << geom_id << ": " << std::fixed << std::setprecision(2)
              << visual_data.oMg[geom_id].translation().transpose()
              << std::endl;
}