#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    int result = 0;
    for (int i = n; i >= 1; i--) {
      for (int j = i; j <= n; j++) {
        if (s[i - 1] != s[j - 1]) {
          continue;
        }
        if (i == j) {
          dp[i][j] = true;
        } else if (i - j == 1 || j - i == 1) {
          dp[i][j] = true;
        } else {
          dp[i][j] = dp[i + 1][j - 1];
        }
        if (dp[i][j]) {
          result++;
        }
      }
    }
    return result;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string word1 = "aaa";
  int result = solution.countSubstrings(word1);
  std::cout << "result: " << result << std::endl;
}