#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
#include <limits.h>
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
  int profitableSchemes(int n, int minProfit, vector<int> &group,
                        vector<int> &profit) {
    int m = profit.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int result = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (j < group[i - 1]) {
          dp[i][j] = dp[i - 1][j];

        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - group[i - 1]] + profit[i - 1]);
        }
        if (dp[i][j] >= minProfit) {
          result = ++result % (int)(pow(10, 9) + 7);
        }
      }
    }
    return result;
  }
};

int main() {
    // 示例二叉树
    Solution solution;
    vector<int> group = {2, 2};
    vector<int> profit = {2, 3};
    int result = solution.profitableSchemes(5, 3, group, profit);
    std::cout << "result: " << result << std::endl;
}