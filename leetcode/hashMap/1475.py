from typing import List
from queue import Queue


class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        result = prices[:]
        n: int = len(result)
        for i in range(n - 1):
            for j in range(i + 1, n):
                if result[j] <= result[i]:
                    result[i] -= result[j]
                    break
        return result


if __name__ == "__main__":
    solution = Solution()
    nums = [8, 4, 6, 2, 3]
    result = solution.finalPrices(nums)
    print(f"result = {result}")
