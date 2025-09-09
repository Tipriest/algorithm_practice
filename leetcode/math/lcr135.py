from typing import List
from queue import Queue
class Solution:
    def countNumbers(self, cnt: int) -> List[int]:
        max:int = pow(10, cnt)-1
        return [i for i in range(1, max+1)]
        
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.countNumbers(2)
    print(f"result = {result}")