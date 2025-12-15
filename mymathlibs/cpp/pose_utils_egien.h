#pragma once

#include <Eigen/Core>
#include <Eigen/Geometry>

// 约定：
// - 欧拉角顺序 Z-Y-X：R = Rz(yaw) * Ry(pitch) * Rx(roll)
// - 欧拉角单位：弧度
// - 四元数接口形式： (w, x, y, z)
// - 旋转矩阵 R: 3x3, v_world = R * v_body
// - 齐次变换 T: 4x4 = [R t; 0 1]

// -----------------------------
// 基本类型别名
// -----------------------------

using Vec3 = Eigen::Vector3d;
using Mat3 = Eigen::Matrix3d;
using Mat4 = Eigen::Matrix4d;
using Quat = Eigen::Quaterniond; // 内部存 (x, y, z, w)

// =============================
// R <-> 欧拉角
// =============================

// 欧拉角 -> 旋转矩阵
// 输入: roll, pitch, yaw (rad)
// 输出: R = Rz(yaw) * Ry(pitch) * Rx(roll)
inline Mat3 euler_to_rot(double roll, double pitch, double yaw) {
  Mat3 R;
  R = Eigen::AngleAxisd(yaw, Vec3::UnitZ()) *
      Eigen::AngleAxisd(pitch, Vec3::UnitY()) *
      Eigen::AngleAxisd(roll, Vec3::UnitX());
  return R;
}

// 旋转矩阵 -> 欧拉角
// 返回: (roll, pitch, yaw)
inline Eigen::Vector3d rot_to_euler(const Mat3 &R) {
  // eulerAngles(2,1,0) -> [yaw, pitch, roll] for ZYX
  Eigen::Vector3d euler = R.eulerAngles(2, 1, 0);
  double yaw = euler[0];
  double pitch = euler[1];
  double roll = euler[2];
  return Eigen::Vector3d(roll, pitch, yaw);
}

// =============================
// R <-> 四元数
// =============================

// 四元数(qw,qx,qy,qz) -> 旋转矩阵
inline Mat3 quat_to_rot(double w, double x, double y, double z) {
  Quat q(x, y, z, w); // Eigen 构造: (x, y, z, w)
  q.normalize();
  return q.toRotationMatrix();
}

// 旋转矩阵 -> 四元数(qw,qx,qy,qz)
inline Eigen::Vector4d rot_to_quat(const Mat3 &R) {
  Quat q(R);
  q.normalize();
  return Eigen::Vector4d(q.w(), q.x(), q.y(), q.z());
}

// =============================
// 欧拉角 <-> 四元数
// =============================

// 欧拉角 -> 四元数(qw,qx,qy,qz)
inline Eigen::Vector4d euler_to_quat(double roll, double pitch, double yaw) {
  Mat3 R = euler_to_rot(roll, pitch, yaw);
  return rot_to_quat(R);
}

// 四元数(qw,qx,qy,qz) -> 欧拉角(roll,pitch,yaw)
inline Eigen::Vector3d quat_to_euler(double w, double x, double y, double z) {
  Mat3 R = quat_to_rot(w, x, y, z);
  return rot_to_euler(R);
}

// =============================
// 齐次变换 T <-> (R, t)
// =============================

// (R, t) -> 齐次变换矩阵 T
// T = [R t; 0 1]
inline Mat4 rt_to_T(const Mat3 &R, const Vec3 &t) {
  Mat4 T = Mat4::Identity();
  T.topLeftCorner<3, 3>() = R;
  T.topRightCorner<3, 1>() = t;
  return T;
}

// 齐次变换矩阵 T -> (R, t)
inline void T_to_rt(const Mat4 &T, Mat3 &R, Vec3 &t) {
  R = T.topLeftCorner<3, 3>();
  t = T.topRightCorner<3, 1>();
}

// =============================
// T <-> (欧拉角, t)
// =============================

// (欧拉角, t) -> T
inline Mat4 euler_t_to_T(double roll, double pitch, double yaw, double tx,
                         double ty, double tz) {
  Mat3 R = euler_to_rot(roll, pitch, yaw);
  Vec3 t(tx, ty, tz);
  return rt_to_T(R, t);
}

// T -> (欧拉角, t)
// 输出: roll,pitch,yaw 与 tx,ty,tz
inline void T_to_euler_t(const Mat4 &T, double &roll, double &pitch,
                         double &yaw, double &tx, double &ty, double &tz) {
  Mat3 R;
  Vec3 t;
  T_to_rt(T, R, t);
  Eigen::Vector3d rpy = rot_to_euler(R);
  roll = rpy[0];
  pitch = rpy[1];
  yaw = rpy[2];
  tx = t[0];
  ty = t[1];
  tz = t[2];
}

// =============================
// T <-> (四元数, t)
// =============================

// (四元数, t) -> T
inline Mat4 quat_t_to_T(double w, double x, double y, double z, double tx,
                        double ty, double tz) {
  Mat3 R = quat_to_rot(w, x, y, z);
  Vec3 t(tx, ty, tz);
  return rt_to_T(R, t);
}

// T -> (四元数, t)
inline void T_to_quat_t(const Mat4 &T, double &w, double &x, double &y,
                        double &z, double &tx, double &ty, double &tz) {
  Mat3 R;
  Vec3 t;
  T_to_rt(T, R, t);
  Eigen::Vector4d q = rot_to_quat(R);
  w = q[0];
  x = q[1];
  y = q[2];
  z = q[3];
  tx = t[0];
  ty = t[1];
  tz = t[2];
}