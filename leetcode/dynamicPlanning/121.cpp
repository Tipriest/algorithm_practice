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
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][0], -prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[n - 1][1];
  }
};

int main() {
    // 示例二叉树
    Solution solution;
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    int result = solution.maxProfit(nums);
    std::cout << "result: " << result << std::endl;
}