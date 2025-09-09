from typing import List
from queue import Queue
class Solution:
    def maxScore(self, s: str) -> int:
        zero_num:int = 0
        one_num:int = 0
        for ch in s:
            if '0' == ch:
                zero_num+=1
        one_num = len(s) - zero_num
        left_score:int = 0
        right_score:int = one_num
        total_score:int = -1
        n:int = len(s)
        for i in range(n-1):
            if '0' == s[i]:
                left_score+=1
            else:
                right_score-=1
            total_score = max(total_score, left_score+right_score)
        return total_score
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.maxScore("011101")
    print(f"result = {result}")
 