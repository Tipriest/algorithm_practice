#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  int calMeathodNum(int n, vector<int> &nums) {
    if (nums.size() == 0) {
      cout << "error1" << endl;
      return -1;
    }
    int m = nums.size();
    vector<vector<int>> dp(m, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
      dp[i][0] = 1;
    }
    for (int i = 0; i < n + 1; i++) {
      if (i % nums[0] == 0) {
        dp[0][i] = 1;
      }
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n + 1; j++) {
        if (j < nums[i]) {
          dp[i][j] = dp[i - 1][j];
          continue;
        } else {
          dp[i][j] = dp[i][j - nums[i]] + dp[i - 1][j];
        }
      }
    }
    return dp[m - 1][n];
  }
  vector<int> findCoins(vector<int> &numWays) {
    int len = numWays.size();
    vector<int> coinTypes;
    for (int i = 0; i < len; i++) {
      int curMethod = calMeathodNum(i + 1, coinTypes);
      if (curMethod > numWays[i]) {
        return {};
      } else if (curMethod == numWays[i]) {
        continue;
      }
      if (0 == numWays[i]) {
        continue;
      } else if (1 == numWays[i]) {
        coinTypes.push_back(i + 1);
      } else if (curMethod + 1 == numWays[i]) {
        coinTypes.push_back(i + 1);
      }else {
        return {};
      }
    }
    return coinTypes;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 0};
  vector<int> result = solution.findCoins(nums);
  //   std::cout << "result: " << result << std::endl;
}