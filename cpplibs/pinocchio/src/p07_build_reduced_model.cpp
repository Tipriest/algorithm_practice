/**
 * @file p07_build_reduced_model.cpp
 * @brief 模型的一些关节锁住了，这个文件用于构建指定关节锁住了的情况
 * @author Tipriest (a1503741059@163.com)
 * @date 2025-10-18
 * 
 * @copyright Copyright (C) 2025, Tipriest, all rights reserved.
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Author  <th>Description
 * <tr><td>2025-10-18 <td>Tipriest  <td>
 * </table>
 */
#include "pinocchio/parsers/urdf.hpp"

#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/model.hpp"

#include <algorithm>
#include <iostream>

// PINOCCHIO_MODEL_DIR
// 是一个宏，通常由CMake在编译时定义，指向存放模型文件的目录。
// 如果CMake没有定义这个宏，这里提供一个默认路径。
// 您可以根据自己的模型文件存放位置修改此路径。
#ifndef PINOCCHIO_MODEL_DIR
#define PINOCCHIO_MODEL_DIR "/opt/openrobots/share"
#endif

// 定义一个模板函数，用于检查元素是否在向量中
template <typename T>
bool is_in_vector(const std::vector<T> &vector, const T &elt) {
  return vector.end() != std::find(vector.begin(), vector.end(), elt);
}

int main(int argc, char **argv) {
  using namespace pinocchio;

  // 设置URDF文件路径
  const std::string urdf_filename =
      (argc <= 1) ? PINOCCHIO_MODEL_DIR +
                        std::string("/example-robot-data/robots/ur_description/"
                                    "urdf/ur5_robot.urdf")
                  : argv[1];

  // --- 加载URDF模型 ---
  // 创建一个空的运动学和动力学模型对象
  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);

  // --- 定义需要锁定的关节列表 ---
  // 使用关节名称定义需要锁定的关节
  std::vector<std::string> list_of_joints_to_lock_by_name;
  list_of_joints_to_lock_by_name.push_back("elbow_joint");
  list_of_joints_to_lock_by_name.push_back("wrist_3_joint"); // 顺序可以任意
  list_of_joints_to_lock_by_name.push_back("wrist_2_joint");
  list_of_joints_to_lock_by_name.push_back("blabla"); // 不存在的关节

  // 打印需要锁定的关节，并获取其对应的关节ID
  std::vector<JointIndex> list_of_joints_to_lock_by_id;
  for (const auto &joint_name : list_of_joints_to_lock_by_name) {
    if (model.existJointName(joint_name)) {
      // 如果关节存在于模型中，获取其ID
      list_of_joints_to_lock_by_id.push_back(model.getJointId(joint_name));
    } else {
      // 如果关节不存在，打印警告信息
      std::cout << "joint: " << joint_name << " does not belong to the model"
                << std::endl;
    }
  }

  // --- 随机生成一个关节配置 ---
  Eigen::VectorXd q_rand = randomConfiguration(model); // 随机配置
  Eigen::VectorXd q_neutral = neutral(model);          // 中性配置
  PINOCCHIO_UNUSED_VARIABLE(q_neutral);                // 避免未使用警告

  // --- 第一种情况：从锁定关节列表构建简化模型 ---
  std::cout << "\n\n第一种情况: 从锁定关节列表构建简化模型" << std::endl;
  // 根据锁定关节列表构建简化模型
  Model reduced_model =
      buildReducedModel(model, list_of_joints_to_lock_by_id, q_rand);

  // 打印原始模型中的关节列表
  std::cout << "原始模型中的关节列表:" << std::endl;
  for (JointIndex joint_id = 1; joint_id < model.joints.size(); ++joint_id)
    std::cout << "\t- " << model.names[joint_id] << std::endl;

  // 打印简化模型中的关节列表
  std::cout << "简化模型中的关节列表:" << std::endl;
  for (JointIndex joint_id = 1; joint_id < reduced_model.joints.size();
       ++joint_id)
    std::cout << "\t- " << reduced_model.names[joint_id] << std::endl;

  // --- 第二种情况：从未锁定关节列表构建简化模型 ---
  std::cout << "\n\n第二种情况: 从未锁定关节列表构建简化模型" << std::endl;
  // 使用关节名称定义需要保持未锁定的关节
  std::vector<std::string> list_of_joints_to_keep_unlocked_by_name;
  list_of_joints_to_keep_unlocked_by_name.push_back("shoulder_pan_joint");
  list_of_joints_to_keep_unlocked_by_name.push_back("shoulder_lift_joint");
  list_of_joints_to_keep_unlocked_by_name.push_back("wrist_1_joint");

  // 获取未锁定关节的ID
  std::vector<JointIndex> list_of_joints_to_keep_unlocked_by_id;
  for (const auto &joint_name : list_of_joints_to_keep_unlocked_by_name) {
    if (model.existJointName(joint_name)) {
      list_of_joints_to_keep_unlocked_by_id.push_back(
          model.getJointId(joint_name));
    } else {
      std::cout << "joint: " << joint_name << " does not belong to the model";
    }
  }

  // 将未锁定关节列表转换为锁定关节列表
  list_of_joints_to_lock_by_id.clear();
  for (JointIndex joint_id = 1; joint_id < model.joints.size(); ++joint_id) {
    const std::string joint_name = model.names[joint_id];
    if (is_in_vector(list_of_joints_to_keep_unlocked_by_name, joint_name))
      continue; // 如果关节在未锁定列表中，则跳过
    else {
      list_of_joints_to_lock_by_id.push_back(joint_id); // 否则加入锁定列表
    }
  }

  // 根据锁定关节列表构建简化模型
  Model reduced_model2 =
      buildReducedModel(model, list_of_joints_to_lock_by_id, q_rand);

  // 打印第二个简化模型中的关节列表
  std::cout << "List of joints in the second reduced model:" << std::endl;
  for (JointIndex joint_id = 1; joint_id < reduced_model2.joints.size();
       ++joint_id)
    std::cout << "\t- " << reduced_model2.names[joint_id] << std::endl;
}