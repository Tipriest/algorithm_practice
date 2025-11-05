#include "pinocchio/parsers/srdf.hpp"
#include "pinocchio/parsers/urdf.hpp"

#include "pinocchio/algorithm/geometry.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/collision/collision.hpp"

#include <iostream>

// PINOCCHIO_MODEL_DIR
// 是一个宏，通常由CMake在编译时定义，指向存放模型文件的目录。
// 如果CMake没有定义这个宏，这里提供一个默认路径。
// 您可以根据自己的模型文件存放位置修改此路径。
#ifndef PINOCCHIO_MODEL_DIR
#define PINOCCHIO_MODEL_DIR "/opt/openrobots/share"
#endif

int main(int /*argc*/, char ** /*argv*/) {
  using namespace pinocchio;

  // 定义机器人模型和几何文件的路径
  const std::string robots_model_path = PINOCCHIO_MODEL_DIR;

  // 设置URDF文件路径
  const std::string urdf_filename =
      robots_model_path +
      std::string(
          "/example-robot-data/robots/talos_data/robots/talos_reduced.urdf");

  // 设置SRDF文件路径
  const std::string srdf_filename =
      robots_model_path +
      std::string("/example-robot-data/robots/talos_data/srdf/talos.srdf");

  // --- 加载URDF模型 ---
  // 创建一个空的运动学和动力学模型对象
  Model model;
  // 从URDF文件中解析并构建模型
  pinocchio::urdf::buildModel(urdf_filename, model);

  // 创建与模型相关联的数据对象，用于存储算法的中间结果
  Data data(model);

  // --- 加载几何模型 ---
  // 创建一个空的几何模型对象
  GeometryModel geom_model;
  // 从URDF文件中加载碰撞几何信息
  pinocchio::urdf::buildGeom(model, urdf_filename, pinocchio::COLLISION,
                             geom_model, robots_model_path);

  // 添加所有可能的碰撞对，并从SRDF文件中移除不需要检测的碰撞对
  geom_model.addAllCollisionPairs();
  pinocchio::srdf::removeCollisionPairs(model, geom_model, srdf_filename);

  // 创建与几何模型相关联的数据对象，用于存储几何计算的中间结果
  GeometryData geom_data(geom_model);

  // --- 加载参考配置 ---
  // 从SRDF文件中加载参考配置（通常是无碰撞的配置）
  pinocchio::srdf::loadReferenceConfigurations(
      model, srdf_filename); // 加载的参考配置名为 "half_sitting"

  // 获取参考配置 "half_sitting"
  const Model::ConfigVectorType &q =
      model.referenceConfigurations["half_sitting"];

  // --- 碰撞检测 ---
  // 计算所有碰撞对的碰撞状态
  bool res = computeCollisions(model, data, geom_model, geom_data, q);

  // 打印所有碰撞对的状态
  for (size_t k = 0; k < geom_model.collisionPairs.size(); ++k) {
    const CollisionPair &cp = geom_model.collisionPairs[k]; // 碰撞对
    const hpp::fcl::CollisionResult &cr =
        geom_data.collisionResults[k]; // 碰撞结果

    std::cout << "collision pair: " << cp.first << " , " << cp.second
              << " - collision: ";
    std::cout << (cr.isCollision() ? "yes" : "no") << std::endl;
  }

  // 如果希望在检测到第一个碰撞时停止，可以将最后一个参数设置为 true
  computeCollisions(model, data, geom_model, geom_data, q, true);

  // --- 检测单个碰撞对 ---
  // 例如，检测第三个碰撞对在中性配置下的碰撞状态
  const PairIndex pair_id = 2; // 第三个碰撞对的索引
  const Model::ConfigVectorType q_neutral = neutral(model); // 中性配置
  updateGeometryPlacements(model, data, geom_model, geom_data,
                           q_neutral); // 更新几何体在世界坐标系中的位置
  computeCollision(geom_model, geom_data, pair_id); // 检测指定碰撞对的碰撞状态

  return 0;
}
