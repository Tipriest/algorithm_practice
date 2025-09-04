#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    if (sum % 2 != 0) {
      return false;
    }
    int n = nums.size();
    int contain_weight = sum / 2 + 1;
    vector<int> dp(contain_weight, 0);
    for (int j = nums[0]; j < contain_weight; j++) {
      dp[j] = nums[0];
    }
    for (int i = 1; i < n; i++) {
      for (int j = contain_weight-1; j >= nums[i]; j--) {
        if (j < nums[i]) {
          // dp[j]不变
          continue;
        }
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    if (dp[sum / 2] == sum / 2) {
      return true;
    }
    return false;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 5};
  int result = solution.canPartition(nums);
  std::cout << "result: " << result << std::endl;
}