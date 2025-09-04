#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int n = stones.size();
    int sum = 0, maxWeigt = 0;
    for (int i = 0; i < n; i++) {
      sum += stones[i];
      maxWeigt = max(maxWeigt, stones[i]);
    }
    if (maxWeigt > sum / 2) {
      return 2 * (maxWeigt - sum / 2);
    }
    int contain = sum / 2;
    vector<int> dp(contain + 1, 0);
    for (int i = stones[0]; i <= contain; i++) {
      dp[i] = stones[0];
    }
    for (int i = 1; i < n; i++) {
      for (int j = contain; j >= stones[i]; j--) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }
    return 2 * (sum / 2 - dp[contain]);
  }
};

int main() {
    // 示例二叉树
    Solution solution;
    vector<int> nums = {2, 1};
    int result = solution.lastStoneWeightII(nums);
    std::cout << "result: " << result << std::endl;
}