from typing import List
from queue import Queue


class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        prefix_sum: List[int] = []
        n: int = len(nums)
        for i in range(1, n):
            if nums[i] - nums[i - 1] > 0:
                prefix_sum.append(1)
            elif nums[i] - nums[i - 1] == 0:
                return False
            elif nums[i] - nums[i - 1] < 0:
                prefix_sum.append(-1)
        prefix_sum2: List[int] = []
        n = len(prefix_sum)
        prefix_sum2.append(prefix_sum[0])
        for i in range(1, n):
            if prefix_sum[i] == prefix_sum[i - 1]:
                continue
            else:
                prefix_sum2.append(prefix_sum[i])
        if 3 != len(prefix_sum2):
            return False
        if 1 != prefix_sum2[0] or -1 != prefix_sum2[1] or 1 != prefix_sum2[2]:
            return False
        return True


if __name__ == "__main__":
    solution = Solution()
    nums: List[int] = [1, 3, 5, 4, 2, 6]
    result = solution.isTrionic(nums)
    print(f"result = {result}")
