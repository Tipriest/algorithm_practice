#include <algorithm>
#include <deque>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
const int MOD = 1000000007;
class Solution {
public:
  bool cal(vector<int> &val, int k) {
    int min_val = val[0], max_val = val[0];
    int n = val.size();
    for (int i = 1; i < n; i++) {
      min_val = min(min_val, val[i]);
      max_val = max(max_val, val[i]);
      if (max_val - min_val > k) {
        return false;
      }
    }

    return true;
  }
  int countPartitions(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
      int result = dp[i - 1]; //独立地放着
      vector<int> val;
      val.push_back(nums[i]);
      for (int j = 1; i - j >= 0; j++) {
        val.push_back(nums[i - j]);
        if (cal(val, k)) {
          if (i - j - 1 < 0) {
            result++;
          } else {
            result += dp[i - j - 1];
          }

          result = result % MOD;
        } else {
          val.clear();
          break;
        }
      }
      dp[i] = result;
    }
    return dp[n - 1];
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {3, 3, 4};
  int result = solution.countPartitions(nums, 0);
  std::cout << "result: " << result << std::endl;
}