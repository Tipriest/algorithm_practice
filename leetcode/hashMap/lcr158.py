from typing import List
from queue import Queue
from collections import Counter


class Solution:
    def inventoryManagement(self, stock: List[int]) -> int:
        c = Counter(stock)
        n = len(stock)
        for item in c:
            if c[item] > n / 2:
                return item
        return -1


if __name__ == "__main__":
    solution = Solution()
    stock = [6, 1, 3, 1, 1, 1]
    result = solution.inventoryManagement(stock)
    print(f"result = {result}")
