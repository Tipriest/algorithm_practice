#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> uset;
    for (string word : wordDict) {
      uset.insert(word);
    }
    int n = s.size();
    int m = wordDict.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int j = 1; j <= n; j++) {
      for (int i = 0; i < j; i++) {
        string word = s.substr(i, j - i);
        bool in = (uset.find(word) != uset.end());
        if (dp[i] && in) {
          dp[j] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string s = "leetcode";
  vector<string> wordDict = {"leet", "code"};
  int result = solution.wordBreak(s, wordDict);
  std::cout << "result: " << result << std::endl;
}