from typing import List
from queue import Queue
from functools import cache
from collections import defaultdict
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits)-1, -1, -1):
            if digits[i]<9:
                digits[i]+=1
                return digits
            else:
                digits[i]=0
        return [1]+digits
if __name__ == "__main__":
    solution = Solution()
    digits:List[int] = [9, 9, 9]
    result = solution.plusOne(digits)
    print(f"result = {result}")
