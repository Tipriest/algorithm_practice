#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    int n = nums.size();
    for (int num : nums) {
      sum += num;
    }
    if ((sum + target) & 1) {
      return 0;
    } else if (sum < abs(target)) {
      return 0;
    }
    int bagSize = (sum + target) / 2;
    vector<vector<int>> dp(n, vector<int>(bagSize + 1, 0));
    if (nums[0] <= bagSize) {
      dp[0][nums[0]] = 1;
    }
    int zeroNum = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0)
        zeroNum++;
      dp[i][0] = pow(2, zeroNum);
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= bagSize; j++) {
        if (nums[i] > j) {
          dp[i][j] = dp[i - 1][j];
          continue;
        }
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
      }
    }
    return dp[n - 1][bagSize];
  }
};

int main() {
    // 示例二叉树
    Solution solution;
    vector<int> nums = {100};
    int result = solution.findTargetSumWays(nums, -200);
    std::cout << "result: " << result << std::endl;
}