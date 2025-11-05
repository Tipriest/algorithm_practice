from typing import List
from queue import Queue
class Solution:
    def twoSum(self, prices: List[int], target: int) -> List[int]:
        s = set()
        for price in prices:
            if target - price in s:
                return [price, target - price]
            else:
                s.add(price)
        return []
if __name__ == "__main__":
    solution = Solution()
    prices = [3, 9, 12, 15]
    result = solution.twoSum(prices, 18)
    print(f"result = {result}")
 