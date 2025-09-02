from typing import List
from queue import Queue
class Solution:
    def checkRegion(self, points: List[List[int]], l:int, r:int)->bool:
        n:int = len(points)
        lx:int = points[l][0]
        ly:int = points[l][1]
        rx:int = points[r][0]
        ry:int = points[r][1]
        if lx == rx and ly == ry:
            return False
        if (lx-rx)*(ly-ry)<=0:
            return True
        return False
    def checkAABB(self, points: List[List[int]], l:int, r:int)->bool:
        n:int = len(points)
        lx:int = min(points[l][0], points[r][0])
        rx:int = max(points[l][0], points[r][0])
        ly:int = max(points[l][1], points[r][1])
        ry:int = min(points[l][1], points[r][1])
        for i in range(n):
            if l == i or r == i:
                continue
            _tx:int = points[i][0]
            _ty:int = points[i][1]
            if _tx >= lx and _tx <= rx and _ty <= ly and _ty >= ry:
                return False
        return True

    def numberOfPairs(self, points: List[List[int]]) -> int:
        n:int = len(points)
        res:int = 0
        for l in range(n-1):
            for r in range(l+1, n):
                if self.checkRegion(points, l, r) and self.checkAABB(points, l, r):
                    res+=1
        return res
        
if __name__ == "__main__":
    solution = Solution()
    points = [[3,1],[1,3],[1,1]]
    result = solution.numberOfPairs(points)
    print(f"result = {result}")
 