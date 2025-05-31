from typing import List
from queue import Queue


class Solution:
    def numIslands(self, input_grid: List[List[str]]) -> int:
        m = len(input_grid)
        n = len(input_grid[0])
        visited = [[False for i in range(n)] for j in range(m)]
        island_count = 0
        def bfs(_grid: List[List[str]], _visited: List[List[bool]], _i: int, _j: int):
            dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
            que = Queue(0) # 0意味着初始化无线长度的queue
            que.put([_i, _j])
            _visited[_i][_j] = True
            while not que.empty():
                cur = que.get()
                curx = cur[0]
                cury = cur[1]
                for n in range(4):
                    nextx = curx+dirs[n][0]
                    nexty = cury+dirs[n][1]
                    if(nextx < 0 or nextx >= len(_grid) or
                       nexty < 0 or nexty >= len(_grid[0])):
                        continue
                    if(_visited[nextx][nexty] is False and _grid[nextx][nexty] == '1'):
                        que.put([nextx, nexty])
                        _visited[nextx][nexty] = True
            
        for i in range(m):
            for j in range(n):
                if(visited[i][j] is False and input_grid[i][j] == '1'):
                    bfs(input_grid, visited, i, j)
                    island_count += 1
        return island_count
        
        
if __name__ == "__main__":
    solution = Solution()
    grid = [["1","1","0","0","0"],
            ["1","1","0","0","0"],
            ["0","0","1","0","0"],
            ["0","0","0","1","1"]]
    result = solution.numIslands(grid)
    print(f"result = {result}")

