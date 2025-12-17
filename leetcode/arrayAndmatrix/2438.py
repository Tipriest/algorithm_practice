from typing import List
from queue import Queue


class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        result = 0
        consecutive = 0

        def addfrom1tonum(consecutive):
            return (1 + consecutive) * consecutive / 2

        for num in nums:
            if 0 == num:
                consecutive += 1
            else:
                result += addfrom1tonum(consecutive)
                consecutive = 0
        result += addfrom1tonum(consecutive)
        return int(result)


if __name__ == "__main__":
    solution = Solution()
    nums = [1, 3, 0, 0, 2, 0, 0, 4]
    result = solution.zeroFilledSubarray(nums)
    print(f"result = {result}")
