#!/usr/bin/env python
#
# Copyright (C) 2023 Inria
 
import numpy as np
 
try:
    # 尝试从 robot_descriptions 库加载机器人描述
    from robot_descriptions.loaders.pinocchio import load_robot_description
except ModuleNotFoundError:
    print("This example loads robot descriptions from robot_descriptions.py:")
    print("\n\tpip install robot_descriptions")
 
print("Goal: load a legged robot from its URDF, then modify leg lengths")
 
print("Loading robot description from URDF...")
# 加载 Upkie 机器人描述
robot = load_robot_description("upkie_description")
model = robot.model
 
# 关节位置相对于腿部长度的已知偏移量
# 我们从机器人描述中知道，这些偏移量都是沿着局部y轴的
known_offsets = {"knee": 0.072, "wheel": 0.065}
 
 
def check_limb_lengths(limb_length: float) -> bool:
    """
    检查腿部长度是否符合预期。
    """
    print(f"Checking that limbs are {limb_length} m long... ", end="")
    for side in ("left", "right"):
        for joint in ("knee", "wheel"):
            joint_id = model.getJointId(f"{side}_{joint}")
            # 检查关节的y轴平移是否与预期值匹配
            if not np.allclose(
                model.jointPlacements[joint_id].translation[1],
                limb_length - known_offsets[joint],
            ):
                print("{side}_{joint} placement is wrong!")
                return False
    return True
 
 
# 我们从描述中知道，腿长应该是24厘米
if check_limb_lengths(0.24):
    print("OK, the model is as we expect it")
 
 
def update_limb_lengths(length: float) -> None:
    """
    在机器人模型中更新股骨和胫骨的长度。
 
    Args:
        length: 新的股骨和胫骨长度，单位为米。
    """
    for side in ("left", "right"):
        for joint in ("knee", "wheel"):
            joint_id = model.getJointId(f"{side}_{joint}")
            # 直接修改模型中关节的放置（placement）信息来改变连杆长度
            model.jointPlacements[joint_id].translation[1] = (
                length - known_offsets[joint]
            )
 
 
update_limb_lengths(0.3)  # 将股骨和胫骨更新到30厘米
if check_limb_lengths(0.3):
    print("OK, the update worked!")