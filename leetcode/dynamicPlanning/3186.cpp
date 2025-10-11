#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
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
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  long long maximumTotalDamage(vector<int> &powers) {
    sort(powers.begin(), powers.end());
    unordered_map<int, int> umap;
    for (int power : powers) {
      umap[power]++;
    }
    vector<int> spells_order;
    spells_order.push_back(powers[0]);
    for (auto power : powers) {
      if (power != spells_order[spells_order.size() - 1]) {
        spells_order.push_back(power);
      }
    }
    vector<vector<long long>> dp(umap.size(), vector<long long>(2, 0));
    int n = spells_order.size();
    dp[0][0] = 0;
    dp[0][1] = (long long)spells_order[0] * umap[spells_order[0]];
    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      int j = i - 1;
      while (j >= 0 && spells_order[i] - spells_order[j] <= 2) {
        j--;
      }
      //说明之前的情况都不能用
      if (j < 0) {
        dp[i][1] = (long long)spells_order[i] * umap[spells_order[i]];
      } else {
        dp[i][1] = max(dp[j][0], dp[j][1]) +
                   (long long)spells_order[i] * umap[spells_order[i]];
      }
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> power = {7, 1, 6, 6};
  long long result = solution.maximumTotalDamage(power);
  std::cout << "result: " << result << std::endl;
  return 0;
}