from typing import List
from queue import Queue
from functools import cache
from collections import defaultdict
MX = 100_001
divisor_num = [0]*MX
divisor_sum = [0]*MX
for i in range(1, MX):
    for j in range(i, MX, i):
        divisor_num[j]+=1
        divisor_sum[j]+=i
class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for x in nums:
            if 4 == divisor_num[x]:
                ans += divisor_sum[x]
        return ans
if __name__ == "__main__":
    solution = Solution()
    nums = [21, 4, 7]
    result = solution.sumFourDivisors(nums)
    print(f"result = {result}")
