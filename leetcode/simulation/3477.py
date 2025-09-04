from typing import List
from queue import Queue
class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        unpacked:int = len(fruits)
        for fruit in fruits:
            for basket in baskets:
                if fruit <= basket:
                    unpacked -= 1
                    baskets.remove(basket)
                    break
        return unpacked
if __name__ == "__main__":
    solution = Solution()
    fruits = [4, 2, 5]
    naskets = [3, 5, 4]
    result = solution.numOfUnplacedFruits(fruits, naskets)
    print(f"result = {result}")
 