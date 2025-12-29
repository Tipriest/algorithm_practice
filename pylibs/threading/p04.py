from concurrent.futures import ThreadPoolExecutor


def task(name):
    print(f"{name} 开始")
    return f"{name} 完成"


with ThreadPoolExecutor(max_workers=3) as executor:
    futures = [executor.submit(task, f"任务{i}") for i in range(5)]
    for future in futures:
        print(future.result())
