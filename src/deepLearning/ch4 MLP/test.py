import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# 准备数据
x = np.linspace(0, 2 * np.pi, 100)
y = np.sin(x)
# 创建图形和坐标轴
fig, ax = plt.subplots()
(line,) = ax.plot(x, y)


# 更新图形
def update(frame):
    y = np.sin(x + 2 * np.pi * frame / 100)  # 更新y值
    line.set_ydata(y)  # 更新线条数据
    return (line,)


# 创建动画
ani = FuncAnimation(fig, update, frames=100, interval=20, blit=True)
# 显示图形
plt.show()


# 所以Pyplot确实是阻塞的，所以需要
print("yes! has do this!")
