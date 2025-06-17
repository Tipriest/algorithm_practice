#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i,
          int j) {
    static const int dirs[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 下、上、右、左
    int result = 0;
    int m = grid.size(), n = grid[0].size();
    // 边界和有效性检查
    if (i < 0 || i >= m || j < 0 || j >= n)
      return result;
    if (visited[i][j] || grid[i][j] != 1)
      return result;

    visited[i][j] = true;
    result++;
    for (int d = 0; d < 4; ++d) {
      int nextx = i + dirs[d][0];
      int nexty = j + dirs[d][1];
      result += dfs(grid, visited, nextx, nexty);
    }
    return result;
  }
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<int> pque;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          pque.push(dfs(grid, visited, i, j));
        }
      }
    }
    if (pque.size() == 0) {
      return 0;
    }
    return pque.top();
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  int result = solution.maxAreaOfIsland(grid);
  std::cout << "result: " << result << std::endl;
}
