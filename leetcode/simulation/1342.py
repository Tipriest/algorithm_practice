from typing import List
from queue import Queue


class Solution:
    def numberOfSteps(self, num: int) -> int:
        order: int = 0
        while 0 != num:
            if 0 == num % 2:
                num = int(num / 2)
            else:
                num -= 1
            order += 1
        return order


if __name__ == "__main__":
    solution = Solution()
    num: int = 123
    result = solution.numberOfSteps(num)
    print(f"result = {result}")
