#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  long long maximumProfit(vector<int> &prices, int k) {
    int n = prices.size();
    k = k+1;
    vector<vector<vector<long long>>> dp(
        n, vector<vector<long long>>(k, vector<long long>(3, 0)));
    for (int j = 0; j < k; j++) {
      dp[0][j][0] = 0;
      dp[0][j][1] = -prices[0];
      dp[0][j][2] = prices[0];
    }
    for (int i = 0; i < n; i++) {
      dp[i][0][0] = 0;
      dp[i][0][1] = 0;
      dp[i][0][2] = 0;
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < k; j++) {
        dp[i][j][0] = max(dp[i - 1][j][0], max(dp[i - 1][j][2] - prices[i],
                                               dp[i - 1][j][1] + prices[i]));
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
        dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + prices[i]);
      }
    }
        long long result = 0;
    for(int j = 0; j < k; j++){
        result = result > dp[n-1][j][0] ? result : dp[n-1][j][0];
    }
    return result;


  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 7, 9, 8, 2};
  int result = solution.maximumProfit(nums, 2);
  std::cout << "result: " << result << std::endl;
}