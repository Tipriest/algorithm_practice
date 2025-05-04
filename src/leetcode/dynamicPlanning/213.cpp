#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int a = robRange(nums, 1, 0);
    int b = robRange(nums, 0, 1);
    return max(robRange(nums, 1, 0), robRange(nums, 0, 1));
  }
  int robRange(vector<int> nums, int preExclude, int endExclude) {
    for (int i = 0; i < preExclude; i++) {
      nums.erase(nums.begin());
    }
    for (int i = 0; i < endExclude; i++) {
      nums.erase(nums.end() - 1);
    }
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    if (1 == n) {
      return nums[0];
    }
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return nums[n - 1];
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 3, 1};
  int result = solution.rob(nums);
  std::cout << "result: " << result << std::endl;
}