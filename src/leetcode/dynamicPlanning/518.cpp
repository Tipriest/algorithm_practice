#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int j = 0; j <= amount; j++) {
      if (0 == amount % coins[0]) {
        dp[0][j] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= amount; j++) {
        if(j < coins[i]){
            dp[i][j] = dp[i-1][j];
            continue;
        }
        dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
      }
    }
    return dp[n - 1][amount];
  }
};

int main() {
    // 示例二叉树
    Solution solution;
    vector<int> nums = {2, 7, 13};
    int result = solution.change(500, nums);
    std::cout << "result: " << result << std::endl;
}