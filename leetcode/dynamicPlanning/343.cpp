

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
      for (int j = i; j < i; j++) {
        dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
      }
    }
    return dp[n];
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  int result = solution.integerBreak(10);
  std::cout << "result: " << result << std::endl;
}