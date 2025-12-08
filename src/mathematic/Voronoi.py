import numpy as np
import matplotlib as mpl

mpl.get_cachedir()
import matplotlib.pyplot as plt
from scipy.spatial import Voronoi, voronoi_plot_2d

plt.rcParams["font.sans-serif"] = ["SimHei"]
plt.rcParams["axes.unicode_minus"] = False

# 随机生成一些点（可代表障碍物或参考点）
points = np.array([[1, 1], [2, 4], [5, 3], [7, 5], [8, 2]])

# 计算 Voronoi 图
vor = Voronoi(points)

# 绘制 Voronoi 图
fig, ax = plt.subplots(figsize=(6, 6))
voronoi_plot_2d(
    vor, ax=ax, show_points=True, show_vertices=False, line_colors="skyblue"
)

# 绘制障碍物点
ax.plot(
    points[:, 0],
    points[:, 1],
    "ko",
    markersize=8,
    label="generated point(obstacle center)",
)

# # 模拟路径搜索的结果（在骨架上选一条路径）
# # 这里用一条简化的路径作示意
# path = np.array([[0.5, 0.5], [2, 2], [4, 3], [6, 4], [9, 3]])
# ax.plot(path[:, 0], path[:, 1], "r-", linewidth=2, label="path search result")

# 格式设置
ax.set_xlim(0, 10)
ax.set_ylim(0, 6)
ax.set_title("Voronoi graph", fontsize=14)
ax.legend()
ax.grid(True)

plt.show()
