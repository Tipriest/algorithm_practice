#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j - 1], dp[i][j - 1]);
        }
      }
    }
    if (dp[m][n] == m) {
      return true;
    }
    return false;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string s = "", t = "ahbgdc";
  bool result = solution.isSubsequence(s, t);
  std::cout << "result: " << result << std::endl;
}