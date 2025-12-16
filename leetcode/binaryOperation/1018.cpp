#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
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
  vector<bool> prefixesDivBy5(vector<int> &nums) {
    vector<bool> ans(nums.size());
    int x = 0;
    for (int i = 0; i < nums.size(); i++) {
      x = (x << 1 | nums[i]) % 5;
      ans[i] = (x == 0);
    }
    return ans;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {0, 1, 1};
  vector<bool> result = solution.prefixesDivBy5(nums);
//   std::cout << "result: " << result << std::endl;
}