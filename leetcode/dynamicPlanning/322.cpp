#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
    for (int i = 0; i < n; i++) {
      dp[i][0] = 0;
    }
    for (int j = 0; j <= amount; j += coins[0]) {
      dp[0][j] = j / coins[0];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= amount; j++) {
        if (j < coins[i]) {
          dp[i][j] = dp[i - 1][j];
        }
        dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
      }
    }
    if (dp[n - 1][amount] != INT_MAX) {
      return dp[n - 1][amount];
    }
    return -1;
  }
};

int main() {
    // 示例二叉树
    Solution solution;
    vector<int> nums = {1, 2, 5};

    int result = solution.coinChange(nums, 11);
    std::cout << "result: " << result << std::endl;
}