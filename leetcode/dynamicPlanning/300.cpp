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
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
      int maxBeforeNum = dp[i];
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i] && dp[j] >= maxBeforeNum) {
          dp[i] = dp[j] + 1;
          maxBeforeNum = dp[j];
        }
      }
    }
    return dp[n - 1];
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
  int result = solution.lengthOfLIS(nums);
  std::cout << "result: " << result << std::endl;
}