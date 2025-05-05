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
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<int> dp(n + 1, 0);
    int result = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = n; j >= 1; j--) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[j] = dp[j - 1] + 1;
          for (int k = j + 1; k <= n; k++) {
            if (dp[j] > dp[k]) {
              dp[k] = dp[j];
            } else {
              break;
            }
          }
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
  string text1 = "abcba";
  string text2 = "abcbcba";
  int result = solution.longestCommonSubsequence(text1, text2);
  std::cout << "result: " << result << std::endl;
}