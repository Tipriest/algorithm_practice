from typing import List
from queue import Queue
from functools import cache
class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        total_apple = sum(apple)
        capacity = sorted(capacity, reverse=True)
        res = 0
        for cap in capacity:
            total_apple -= cap
            res += 1
            if total_apple <= 0:
                return res
        return res

if __name__ == "__main__":
    solution = Solution()
    apple = [1,3,2]
    capacity = [4,3,1,5,2]
    result = solution.minimumBoxes(apple, capacity)
    print(f"result = {result}")
