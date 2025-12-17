import numpy as np
import matplotlib.pyplot as plt

# from mpl_toolkits.mplot3d import Axes3D
from matplotlib import animation


def rodrigues_rotate(_v, _k, theta):
    """
    使用罗德里格斯公式将向量v绕单位向量k旋转theta弧度
    :param v: 需要旋转的向量，shape=(3,)
    :param k: 旋转轴单位向量，shape=(3,)
    :param theta: 旋转角度（弧度）
    :return: 旋转后的向量，shape=(3,)
    """
    _v = np.asarray(_v)
    _v = _v / np.linalg.norm(_v)  # 先归一化输入向量
    _k = np.asarray(_k)
    _k = _k / np.linalg.norm(_k)
    v_rot = (
        _v * np.cos(theta)
        + np.cross(_k, _v) * np.sin(theta)
        + _k * np.dot(_k, _v) * (1 - np.cos(theta))
    )
    return v_rot


def animate_rodrigues_rotation(
    _v,
    _k,
    _total_theta=np.pi,
    _frames=100,
    save_gif=True,
    gif_path="rodrigues_rotation.gif",
):
    """
    绘制向量v绕轴k旋转的动图，并保存为gif
    :param v: 初始向量
    :param k: 旋转轴
    :param total_theta: 总旋转角度（弧度）
    :param frames: 动画帧数
    :param save_gif: 是否保存为gif
    :param gif_path: gif保存路径
    """
    _v = np.asarray(_v)
    _v = _v / np.linalg.norm(_v)  # 先归一化输入向量
    _k = np.asarray(_k)
    _k = _k / np.linalg.norm(_k)
    thetas = np.linspace(0, _total_theta, _frames)
    vectors = np.array([rodrigues_rotate(_v, _k, theta) for theta in thetas])

    fig = plt.figure()
    ax = fig.add_subplot(111, projection="3d")
    # 自动根据向量和旋转轴范围设置合适的坐标轴范围
    all_points = np.vstack(([_v], [vectors[-1]], [_k]))
    max_range = np.max(np.abs(all_points)) * 1.3  # 适当放大
    for axis in [ax.set_xlim, ax.set_ylim, ax.set_zlim]:
        axis([-max_range, max_range])
    ax.set_xlabel("X")
    ax.set_ylabel("Y")
    ax.set_zlabel("Z")
    ax.quiver(
        0,
        0,
        0,
        _k[0],
        _k[1],
        _k[2],
        color="g",
        length=1.2,
        linewidth=2,
        label="Axis k",
    )
    ax.quiver(
        0,
        0,
        0,
        _v[0],
        _v[1],
        _v[2],
        color="r",
        length=1.2,
        linewidth=2,
        label="start vec",
    )
    ax.quiver(
        0,
        0,
        0,
        vectors[-1][0],
        vectors[-1][1],
        vectors[-1][2],
        color="y",
        length=1.2,
        linewidth=2,
        label="end vec",
    )
    vec_quiv = ax.quiver(
        0,
        0,
        0,
        _v[0],
        _v[1],
        _v[2],
        color="b",
        length=1.0,
        linewidth=2,
        label="Rotating v",
    )
    ax.legend()

    # 用于保存quiver对象
    quivers = [vec_quiv]

    def update(num):
        # 移除上一帧的向量
        quivers[0].remove()
        new_v = vectors[num]
        quivers[0] = ax.quiver(
            0,
            0,
            0,
            new_v[0],
            new_v[1],
            new_v[2],
            color="b",
            length=1.0,
            linewidth=2,
        )
        return (quivers[0],)

    # 5秒，interval=50ms，则frames=100
    ani = animation.FuncAnimation(
        fig, update, frames=_frames, interval=5000 // _frames, blit=True
    )

    if save_gif:
        ani.save(gif_path, writer="pillow", fps=_frames // 5)
        print(f"GIF已保存到: {gif_path}")

    plt.show()


if __name__ == "__main__":
    # 示例：将向量 v [3, 4, 5] 绕 k轴 [1, 1, 1] 旋转 180°
    v = np.array([3, 4, -5])
    k = np.array([1, 1, 1])
    animate_rodrigues_rotation(
        v,
        k,
        _total_theta=np.pi / 180 * 120,
        _frames=100,
        save_gif=True,
        gif_path="rodrigues_rotation.gif",
    )
