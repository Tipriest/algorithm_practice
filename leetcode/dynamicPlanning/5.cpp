#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int max_num = 0;
    string max_str = "";
    for (int i = n; i >= 1; i--) {
      for (int j = i; j <= n; j++) {
        if (s[i - 1] != s[j - 1]) {
          dp[i][j] = 0;
          continue;
        }
        if (i == j) {
          dp[i][j] = 1;
        } else if (1 == abs(i - j)) {
          dp[i][j] = 2;
        } else {
          if (dp[i + 1][j - 1] != 0) {
            dp[i][j] = dp[i + 1][j - 1] + 2;
          } else {
            dp[i][j] = 0;
          }
        }
        if (dp[i][j] > max_num) {
          max_num = dp[i][j];
          max_str = s.substr(i - 1, max_num);
        }
      }
    }
    return max_str;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string word1 = "babad";
  string result = solution.longestPalindrome(word1);
  std::cout << "result: " << result << std::endl;
}