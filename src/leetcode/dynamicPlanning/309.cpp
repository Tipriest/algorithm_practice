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
    vector<int> dp(4, 0);
    dp[0] = -prices[0];
    for (int i = 1; i < n; i++) {
      dp[0] = max(dp[0], max(dp[1] - prices[i], dp[3] - prices[i]));
      dp[1] = max(dp[1], dp[3]);
      dp[2] = dp[0] + prices[i];
      dp[3] = dp[2];
    }
    return max(dp[1], max(dp[2], dp[3]));
  }
};

int main() {
    // 示例二叉树
    Solution solution;
    vector<int> nums = {1,2,3,0,2};
    int result = solution.maxProfit(nums);
    std::cout << "result: " << result << std::endl;
}