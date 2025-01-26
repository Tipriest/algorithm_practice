from typing import List
from queue import Queue
class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        maxOneNum:int = 0
        maxZeroNum:int = 0
        n:int = len(s)
        count:int = 0
        if s[0] == '0':
            count += 1
            maxZeroNum = max(maxZeroNum, count)
        else:
            count += 1
            maxOneNum = max(maxOneNum, count)
        for i in range(1, n):
            if '0' == s[i] and '0' == s[i-1]:
                count += 1
                maxZeroNum = max(maxZeroNum, count)
            elif '0' == s[i] and '1' == s[i-1]:
                count = 1
                maxZeroNum = max(maxZeroNum, count)
            elif '1' == s[i] and '1' == s[i-1]:
                count += 1
                maxOneNum = max(maxOneNum, count)
            elif '1' == s[i] and '0' == s[i-1]:
                count = 1
                maxOneNum = max(maxOneNum, count)
        return maxOneNum > maxZeroNum

if __name__ == "__main__":
    solution = Solution()
    s:str = "1101"
    result = solution.checkZeroOnes(s)
    print(f"result = {result}")
 