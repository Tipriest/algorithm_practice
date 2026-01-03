import rerun as rr
import numpy as np


def main():
    # 启动 Rerun，"coordinate_axes" 是这个记录会话的名字
    rr.init("coordinate_axes", spawn=True)

    # 日志记录到一个名为 "world" 的实体路径下
    entity = "world/origin_axes"

    # 使用 LineStrips3D 绘制三条线段
    rr.log(
        entity,
        rr.LineStrips3D(
            [
                [
                    [0, 0, 0],
                    [1, 0, 0],
                ],
                [
                    [0, 0, 0],
                    [0, 1, 0],
                ],
                [
                    [0, 0, 0],
                    [0, 0, 1],
                ],
            ],
            colors=[[255, 0, 0], [0, 255, 0], [0, 0, 255]],
            radii=[0.02, 0.02, 0.02],
        ),
    )

    # 为了在视图中更直观，可以加个原点的小球
    rr.log(
        entity + "/origin_point",
        rr.Points3D(
            positions=[0, 0, 0],
            colors=[255, 255, 255],
            radii=0.05,
        ),
    )


if __name__ == "__main__":
    main()
