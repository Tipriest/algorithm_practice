import threading
import queue
import time


def producer(q, n):
    for i in range(n):
        print(f"Producing {i}")
        q.put(i)
        time.sleep(1)


def consumer(q):
    while True:
        item = q.get()
        if item is None:
            break
        print(f"Consuming {item}")
        q.task_done()


q = queue.Queue()
num_items = 50

producer_thread = threading.Thread(target=producer, args=(q, num_items))
consumer_thread = threading.Thread(target=consumer, args=(q,))

producer_thread.start()
consumer_thread.start()

producer_thread.join()
q.put(None)  # Signal the consumer to exit
consumer_thread.join()
