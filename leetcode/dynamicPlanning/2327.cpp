#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
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
  const int mod = 1e9 + 7;
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i <= delay - 1; i++) {
      dp[i] = 0;
    }
    queue<long> qu;
    long sum = 0;
    for (int i = delay, j = 0; i < n; i++, j++) {
      if (qu.size() < (forget - delay)) {
        qu.push(dp[j]);
        sum += dp[j];
        sum %= mod;
      } else {
        sum -= qu.front();
        qu.pop();
        qu.push(dp[j]);
        sum += dp[j];
        sum %= mod;
      }
      dp[i] = sum;
    }
    long result = 0;
    for (int i = 1; i <= forget; i++) {
      result += dp[n - i];
      result %= mod;
    }
    while (result < 0) {
      result += mod;
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 3, 5, 2, 4, 8, 2, 2};
  int result = solution.peopleAwareOfSecret(289, 7, 23);
  std::cout << "result: " << result << std::endl;
}