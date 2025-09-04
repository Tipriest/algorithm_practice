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
  pair<int, int> convert_num_to_i_j(int num, int n) {
    num = num - 1;
    int i = n - 1 - num / n;
    int j;
    if (num / n % 2 == 0) {
      j = num % n;
    } else {
      j = n - 1 - num % n;
    }
    return {i, j};
  }
  int bfs(vector<vector<int>> &grid, vector<bool> &visited, int start) {
    // 从1一直到n**2
    int n = grid.size();
    queue<int> que;
    que.push(start);
    visited[start] = true;
    int result = 0;
    while (!que.empty()) {
      int m = que.size();
      for (int i = 0; i < m; i++) {
        int cur = que.front();
        que.pop();
        if (cur == n * n) {
          return result;
        }
        visited[cur] = true;
        // 添加下一层
        for (int rand = 1; rand < 7 && cur + rand <= pow(n, 2); rand++) {
          auto _i_j = convert_num_to_i_j(cur + rand, n);
          int next_value = cur + rand;
          if (grid[_i_j.first][_i_j.second] != -1) {
            next_value = grid[_i_j.first][_i_j.second];
          }
          if (!visited[next_value]) {
            que.push(next_value);
          }
        }
      }
      // 过了这一层都没找到，需要看下一层了
      result++;
    }
    return -1;
  }
  int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();
    vector<bool> visited(n * n + 1, false);
    return bfs(board, visited, 1);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> nums = {{1, 1, -1}, {1, 1, 1}, {-1, 1, 1}};
  int result = solution.snakesAndLadders(nums);
  std::cout << "result: " << result << std::endl;
}
