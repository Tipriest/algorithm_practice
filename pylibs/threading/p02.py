import threading
counter = 0  # 全局变量
def test():
    def increment():
        global counter
        for _ in range(1000):
            counter += 1  # 多线程这里可能会出错(但是3.10不会出错)

    threads = []
    for _ in range(50):
        t = threading.Thread(target=increment)
        threads.append(t)
        t.start()

    for t in threads:
        t.join()

    print("counter =", counter)

if __name__ =="__main__":
    for i in range(100):
        test()
