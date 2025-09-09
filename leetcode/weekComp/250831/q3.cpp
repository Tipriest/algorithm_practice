#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
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
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  const int mod = 1e9 + 7;
  int uniquePaths(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<long>>> dp(
        m, vector<vector<long>>(n, vector<long>(2, 0)));
    // 0是从上面进
    // 1是从左边进
    for (int i = 0; i < m; i++) {
      if (1 == grid[i][0]) {
        dp[i][0][0] = 1;
        break;
      } else {
        dp[i][0][0] = 1;
      }
    }
    for (int j = 0; j < n; j++) {
      if (1 == grid[0][j]) {
        dp[0][j][1] = 1;
        break;
      } else {
        dp[0][j][1] = 1;
      }
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (1 == grid[i - 1][j]) {
          dp[i][j][0] = dp[i - 1][j][1];
        } else {
          dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
        }
        if (1 == grid[i][j - 1]) {
          dp[i][j][1] = dp[i][j - 1][0];
        } else {
          dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % mod;
        }
      }
    }
    return int((dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % mod);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> grid = {{0, 1, 1}, {1, 1, 0}};
  int result = solution.uniquePaths(grid);
  std::cout << "result: " << result << std::endl;
}