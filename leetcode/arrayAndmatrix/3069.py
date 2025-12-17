from typing import List
from queue import Queue


class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        a = nums[:1]
        b = nums[1:2]
        for x in nums[2:]:
            if a[-1] > b[-1]:
                a.append(x)
            else:
                b.append(x)
        return a + b


if __name__ == "__main__":
    solution = Solution()
    grid = [2, 1, 3]
    result = solution.resultArray(grid)
    print(f"result = {result}")
