#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <numeric>
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
  int lengthAfterTransformations(string s, int t) {
    int n = t + 1;
    vector<int> dp(26, 0);
    int mod = 1e9 + 7;
    for (char ch : s) {
      dp[ch - 'a']++;
    }
    for (int i = 1; i < n; i++) {
      int last_z = dp[25];
      for (int j = 25; j >= 0; j--) {
        if (j == 0) {
          dp[j] = last_z;
        } else if (j == 1) {
          dp[j] = (dp[0] + last_z) % mod;
        } else {
          dp[j] = dp[j - 1];
        }
      }
    }
    // cout<<1<<endl;
    return accumulate(dp.begin(), dp.end(), 0);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "abcyy";
  int result = solution.lengthAfterTransformations(s, 2);
  std::cout << "result: " << result << std::endl;
}