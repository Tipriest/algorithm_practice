#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubstrings(string word) {
    int n = word.size();
    if (n < 4) {
      return 0;
    }
    vector<int> dp(n, 0);
    vector<vector<int>> recordCh(26, vector<int>());
    for (int i = 0; i < 3; i++) {
      recordCh[word[i] - 'a'].push_back(i);
    }
    for (int i = 3; i < n; i++) {
      recordCh[word[i] - 'a'].push_back(i);
      // 如果在i-3及之前有一样的字母，找到最新的一个
      int ch = word[i] - 'a';
      int m = recordCh[ch].size();
      int new_value = -1;
      while (m != 0) {
        if (recordCh[ch][m - 1] <= (i - 3)) {
          new_value = recordCh[ch][m - 1];
          break;
        } else {
          m--;
        }
      }
      if(new_value == -1){
        dp[i] = dp[i-1];
      }else{
        if(new_value == 0){
          dp[i] = max(dp[i - 1], 1);
        }else{
          dp[i] = max(dp[i - 1], dp[new_value-1]+1);
        }
      }
    }
    return dp[n-1];
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string s = "abcdeafdef";
  int result = solution.maxSubstrings(s);
  std::cout << "result: " << result << std::endl;
}