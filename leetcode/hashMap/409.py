from typing import List
from queue import Queue
from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        c = Counter(s)
        hasOdd = False
        result = 0
        for item in c:
            if 1 == c[item] % 2:
                result += c[item] - 1
                hasOdd = True
            else:
                result += c[item]
        return result+hasOdd
        
        
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.longestPalindrome("abccccdd")
    print(f"result = {result}")
 