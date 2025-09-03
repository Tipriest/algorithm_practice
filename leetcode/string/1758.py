from typing import List
from queue import Queue
class Solution:
    def minOperations(self, s: str) -> int:
        ra:int = 0
        rb:int = 0
        ba:bool = True
        for ch in s:
            ra += ba ^ int(ch)
            rb += (not ba) ^ int(ch)
            ba = not ba
        return min(ra, rb)
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.minOperations("0100")
    print(f"result = {result}")
 