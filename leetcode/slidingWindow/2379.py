from typing import List
from queue import Queue
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        n:int = len(blocks)
        min_white:int = 0
        white_num:int = 0
        for i in range(k):
            if 'W' == blocks[i]:
                min_white+=1
                white_num+=1
        for i in range(1, n - k + 1):
            if 'W' == blocks[i-1]:
                white_num-=1
            if 'W' == blocks[i-1+k]:
                white_num+=1
            min_white = min(white_num, min_white)
        return min_white
if __name__ == "__main__":
    solution = Solution()
    blocks:str = "WBWBBBW"
    result = solution.minimumRecolors(blocks, 2)
    print(f"result = {result}")
 