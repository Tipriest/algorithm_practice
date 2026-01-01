"""_summary_"""

import threading
import time


def worker(name):
    print(f"线程 {name} 开始工作: {time.time()}")
    time.sleep(1)
    print(f"线程 {name} 工作结束: {time.time()}")


# 创建线程对象
t1 = threading.Thread(target=worker, args=("A",))
t2 = threading.Thread(target=worker, args=("B",))

# 启动线程
t1.start()
t2.start()

# 等待线程结束
t1.join()
t2.join()

print("所有线程执行完毕")
