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
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 0; i <=m; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <=n; j++){
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j - 1] + 2,
                         min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
      }
    }
    return dp[m][n];
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string word1 = "sea";
  string word2 = "eat";
  int result = solution.minDistance(word1, word2);
  std::cout << "result: " << result << std::endl;
}