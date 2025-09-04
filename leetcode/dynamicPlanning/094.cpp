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
  int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    for (int i = n; i >= 1; i--) {
      for (int j = i; j <= n; j++) {
        if (s[i-1] != s[j-1]) {
          continue;
        } else {
          if (i == j || abs(i - j) == 1) {
            dp[i][j] = true;
          } else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }
      }
    }
    vector<int> dp2(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (dp[1][i] == true) {
        dp2[i] = 0;
      } else {
        int min_sum = INT32_MAX;
        for (int j = 1; j <= i; j++) {
          if (dp[j][i] == true) {
            min_sum = min(min_sum, dp2[j - 1] + 1);
          }
        }
      }
    }

    return dp2[n];
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string s = "aab";
  int result = solution.minCut(s);
  std::cout << "result: " << result << std::endl;
}