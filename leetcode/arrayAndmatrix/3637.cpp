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
  bool isTrionic(vector<int> &nums) {
    vector<int> prefix_sum;
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      if (nums[i] - nums[i - 1] > 0) {
        prefix_sum.push_back(1);
      } else if (nums[i] - nums[i - 1] == 0) {
        return false;
      } else if (nums[i] - nums[i - 1] < 0) {
        prefix_sum.push_back(-1);
      }
    }
    vector<int> prefix_sum2;
    n = prefix_sum.size();
    prefix_sum2.push_back(prefix_sum[0]);
    for (int i = 1; i < n; i++) {
      if (prefix_sum[i] == prefix_sum[i - 1]) {
        continue;
      } else {
        prefix_sum2.push_back(prefix_sum[i]);
      }
    }
    if (3 != prefix_sum2.size()) {
      return false;
    }
    if (1 != prefix_sum2[0] || -1 != prefix_sum2[1] || 1 != prefix_sum2[2]) {
      return false;
    }
    return true;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {2, 1, 3};
  int result = solution.isTrionic(nums);
  std::cout << "result: " << result << std::endl;
}