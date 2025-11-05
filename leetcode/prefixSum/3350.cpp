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
  int maxIncreasingSubarrays(vector<int> &nums) {
    prefix.push_back(nums[0]);
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      prefix.push_back(nums[i] - nums[i - 1]);
    }
    int cons = 0;
    vector<int> ccs;
    for (int i = 0; i < n; i++) {
      if (prefix[i] > 0) {
        cons++;
      } else {
        ccs.push_back(cons);
        cons = 1;
      }
    }
    ccs.push_back(cons);
    int max_k = 1;
    max_k = max(max_k, ccs[0] / 2);
    for (int i = 1; i < ccs.size(); i++) {
      max_k = max(max_k, min(ccs[i - 1], ccs[i]));
      max_k = max(max_k, ccs[i] / 2);
    }
    return max_k;
  }
  vector<int> prefix;
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
  int result = solution.maxIncreasingSubarrays(nums);
  std::cout << "max_k: " << result << std::endl;
  return 0;
}