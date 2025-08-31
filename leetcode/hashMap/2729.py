from typing import List
from queue import Queue
from collections import Counter
class Solution:
    def isFascinating(self, n: int) -> bool:
        ls = "".join([str(n), str(2*n), str(3*n)])
        c = Counter(ls)
        if c["0"] != 0:
            return False
        for i in range(1, 10):
            if c[str(i)] != 1:
                return False
        return True
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.isFascinating(192)
    print(f"result = {result}")
 