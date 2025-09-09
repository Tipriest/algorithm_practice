from typing import List
from queue import Queue
class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        psum:list = [0] * 101
        n: int = len(logs)
        for i in range(n):
            psum[logs[i][0] - 1950]+=1
            psum[logs[i][1] - 1950]-=1
        max_v:int = -1
        max_y:int = -1
        tr:int = 0
        for i in range(len(psum)):
            tr += psum[i]
            if tr > max_v:
                max_v = tr
                max_y = i + 1950
        return max_y
        
if __name__ == "__main__":
    solution = Solution()
    nums:List[List[int]] = [[1950,1961],[1960,1971],[1970,1981]]
    result = solution.maximumPopulation(nums)
    print(f"result = {result}")
 