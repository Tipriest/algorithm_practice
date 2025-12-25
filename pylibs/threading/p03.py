import threading

counter = 0
lock = threading.Lock()


def safe_increment():
    global counter
    for _ in range(100000):
        with lock:  # 自动 acquire/release
            counter += 1


threads = []
for _ in range(5):
    t = threading.Thread(target=safe_increment)
    threads.append(t)
    t.start()

for t in threads:
    t.join()

print("counter =", counter)  # 结果正确
