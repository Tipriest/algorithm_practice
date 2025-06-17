#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
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
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == 0) {
          dp[i][j] = dp[i - 1][j] + triangle[i][j];
        } else if (j == i) {
          dp[i][j] = dp[i - 1][j-1] + triangle[i][j];
        } else {
          dp[i][j] = min(dp[i - 1][j] + triangle[i][j],
                         dp[i - 1][j - 1] + triangle[i][j]);
        }
      }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  int result = solution.minimumTotal(triangle);
  std::cout << "result: " << result << std::endl;
}