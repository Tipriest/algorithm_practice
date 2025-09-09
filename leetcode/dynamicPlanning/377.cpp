#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int j = 0; j <= target; j += nums[0]) {
      dp[0][j] = 1;
    }
    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;
    }

    for (int j = 1; j <= target; j++) {
      for (int i = 1; i < n; i++) {
        if (j < nums[i]) {
          dp[i][j] = dp[i - 1][j];
          continue;
        }
        dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i]];
      }
    }

    return dp[n - 1][target];
  }
};

int main() {
    // 示例二叉树
    Solution solution;
    vector<int> nums = {1, 2, 3};
    int result = solution.combinationSum4(nums, 4);
    std::cout << "result: " << result << std::endl;
}