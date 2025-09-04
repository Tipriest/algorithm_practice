#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited,
           int startx, int starty) {
    static const int dirs[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 下、上、右、左
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> que;
    que.push({startx, starty});
    visited[startx][starty] = true;

    while (!que.empty()) {
      auto [curx, cury] = que.front();
      que.pop();
      for (int d = 0; d < 4; ++d) {
        int nextx = curx + dirs[d][0];
        int nexty = cury + dirs[d][1];
        // 边界检查
        if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n)
          continue;
        // 只访问未访问过的陆地
        if (!visited[nextx][nexty] && grid[nextx][nexty] == '1') {
          que.push({nextx, nexty});
          visited[nextx][nexty] = true; // 在入队的时候就要标记访问
        }
      }
    }
  }
  void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i,
           int j) {
    static const int dirs[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 下、上、右、左
    int m = grid.size(), n = grid[0].size();
    // 边界和有效性检查
    if (i < 0 || i >= m || j < 0 || j >= n)
      return;
    if (visited[i][j] || grid[i][j] != '1')
      return;

    visited[i][j] = true;
    for (int d = 0; d < 4; ++d) {
      int nextx = i + dirs[d][0];
      int nexty = j + dirs[d][1];
      dfs(grid, visited, nextx, nexty);
    }
  }
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int result = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1' && visited[i][j] == false) {
          result++;
          dfs(grid, visited, i, j);
        }
      }
    }
    return result;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '1', '0', '0'},
                               {'0', '0', '0', '1', '1'}};
  int result = solution.numIslands(grid);
  std::cout << "result: " << result << std::endl;
}
