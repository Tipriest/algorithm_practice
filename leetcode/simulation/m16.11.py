from typing import List
from queue import Queue
class Solution:
    def divingBoard(self, shorter: int, longer: int, k: int) -> List[int]:
        if 0 == k:
            return []
        if shorter == longer:
            return [shorter*k]
        res:List[int] = []
        i:int = 0
        while i <= k:
            res.append(i * longer + (k-i)*shorter)
            i+=1
        return res
if __name__ == "__main__":
    solution = Solution()
    shorter:int = 2
    longer:int = 1118596
    k:int = 979
    result = solution.divingBoard(shorter, longer, k)
    print(f"result = {result}")
 