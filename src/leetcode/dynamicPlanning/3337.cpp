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
  int lengthAfterTransformations(string s, int n, vector<int> &nums) {
    int mod = 1e9 + 7;
    int m = *max_element(nums.begin(), nums.end());
    vector<vector<int>> dp(m + 1, vector<int>(26, 0));
    for (int i = 0; i < 26; i++) {
      dp[0][i] = 1;
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 0; j < 26; j++) {
        int sum = 0;
        for (int k = 1; k <= nums[j]; k++) {
          sum = (sum + dp[i - 1][(j + k) % 26]) % mod;
        }
        dp[i][j] = sum;
      }
    }
    int result = 0;
    for (char ch : s) {
      result = (result + dp[m][ch - 'a']) % mod;
    }
    return result;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string s = "azbk";
  vector<int> nums = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                      2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  int result = solution.lengthAfterTransformations(s, 1, nums);
  std::cout << "result: " << result << std::endl;
}