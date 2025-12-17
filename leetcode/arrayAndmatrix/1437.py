from typing import List
from queue import Queue


class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        consecutive: int = 0
        ini: bool = False
        for num in nums:
            if 0 == num:
                consecutive += 1
            else:
                if ini and consecutive < k:
                    return False
                ini = True
                consecutive = 0
        return True


if __name__ == "__main__":
    solution = Solution()
    grid = [1, 0, 0, 1, 0, 1]
    result = solution.kLengthApart(grid, 2)
    print(f"result = {result}")
