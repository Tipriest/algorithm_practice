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
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> dp(m + 1, 0);
    int result = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = m; j >= 1; j--) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[j] = dp[j - 1] + 1;
        }
        if (dp[j] > result) {
          result = dp[j];
        }
      }
    }
    return result;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums1 = {1, 0, 0, 0, 1};
  vector<int> nums2 = {1, 0, 0, 1, 1};
  int result = solution.findLength(nums1, nums2);
  std::cout << "result: " << result << std::endl;
}