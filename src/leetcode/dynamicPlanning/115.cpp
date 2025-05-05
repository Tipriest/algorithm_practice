#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int numDistinct(string t, string s) {
    int m = s.size();
    int n = t.size();
    vector<vector<unsigned long long>> dp(m + 1,
                                          vector<unsigned long long>(n + 1, 0));
    for (int i = 0; i <= n; i++) {
      dp[0][i] = 1;
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
          continue;
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    return dp[m][n];
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string s = "babgbag", t = "bag";
  bool result = solution.numDistinct(s, t);
  std::cout << "result: " << result << std::endl;
}