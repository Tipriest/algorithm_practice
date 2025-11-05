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
  int countHillValley(vector<int> &nums) {
    vector<int> prefix_nums;
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      int diff = nums[i] - nums[i - 1];
      if (0 != diff) {
        prefix_nums.push_back(nums[i] - nums[i - 1]);
      }
    }
    if(0 == prefix_nums.size()){
        return 0;
    }
    int result = 0;
    int init_pos = prefix_nums[0] / abs(prefix_nums[0]);
    int m = prefix_nums.size();
    for (int i = 1; i < m; i++) {
      if (prefix_nums[i] * init_pos < 0) {
        result++;
        init_pos = -init_pos;
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 1, 1};
  int result = solution.countHillValley(nums);
  std::cout << "result: " << result << std::endl;
}