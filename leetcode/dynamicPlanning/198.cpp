#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    vector<int> dp(n, 0);
    dp[0] = nums[0];
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