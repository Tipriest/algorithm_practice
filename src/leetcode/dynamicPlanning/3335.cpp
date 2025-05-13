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
  int lengthAfterTransformations(string s, int t) {
    int n = t+1;
    vector<vector<int>> dp(26, vector<int>(n, 0));
    int mod = 1e9 + 7;
    for (char ch : s) {
      dp[ch - 'a'][0]++;
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 26; j++) {
        if (j == 0) {
          dp[0][i] = dp[25][i - 1];
          continue;
        } else if (j == 1) {
          dp[1][i] = (dp[0][i - 1] + dp[25][i - 1]) % mod;
          continue;
        }
        dp[j][i] = dp[j - 1][i - 1];
      }
    }
    cout << 1 << endl;
    int result = 0;
    for (int i = 0; i < 26; i++) {
      result = (result + dp[i][n - 1]) % mod;
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "abcyy";
  int result = solution.lengthAfterTransformations(s, 2);
  std::cout << "result: " << result << std::endl;
}