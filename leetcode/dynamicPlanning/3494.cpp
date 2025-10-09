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
  long long minTime(vector<int> &skill, vector<int> &mana) {
    int n = skill.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++) {
      dp[i] = dp[i - 1] + (long)mana[0] * skill[i - 1];
    }
    for (int i = 1; i < mana.size(); i++) {
      dp[0] = dp[1];
      for (int j = 1; j < n + 1; j++) {
        dp[j] = (long)max(dp[j - 1], dp[j]) + (long)skill[j - 1] * mana[i];
      }
      for (int k = n - 1; k >= 0; k--) {
        dp[k] = (long)max(dp[k], dp[k + 1] - (long)mana[i] * skill[k]);
      }
    }
    return dp[n];
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string s = "azbk";
  vector<int> skill = {1, 5, 2, 4}, mana = {5, 1, 4, 2};
  long long result = solution.minTime(skill, mana);
  std::cout << "result: " << result << std::endl;
}