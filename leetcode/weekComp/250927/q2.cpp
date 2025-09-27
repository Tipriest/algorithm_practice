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
  int climbStairs(int n, vector<int> &costs) {
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1 + costs[1-1];
    if(1 == n){
      return dp[1];
    }
    dp[2] = min(4+dp[0], 1+dp[1])+costs[2-1];
    for(int i = 3; i < n+1; i++){
      dp[i] = min(min(9+dp[i-3], 4+dp[i-2]), 1+dp[i-1])+costs[i-1];
    }
    return dp[n];
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {9};
  int result = solution.climbStairs(1, nums);
  std::cout << "result: " << result << std::endl;
  return 0;
}