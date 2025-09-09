from typing import List
from queue import Queue
class Solution:
    def isCircularSentence(self, s: str) -> bool:
        n:int = len(s)
        if s[0] != s[-1]:
            return False
        for i in range(n):
            if " " == s[i]:
                if(s[i-1]!=s[i+1]):
                    return False
        return True
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.isCircularSentence("leetcode exercises sound delightful")
    print(f"result = {result}")
 