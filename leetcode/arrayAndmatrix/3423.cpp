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
class Solution {
public:
  int maxAdjacentDistance(vector<int> &nums) {
    nums.push_back(nums[0]);
    vector<int> prefix_nums;
    int n = nums.size();
    int max_diff = -1;
    for (int i = 1; i < n; i++) {
      prefix_nums.push_back(nums[i] - nums[i - 1]);
      max_diff = max(max_diff, abs(nums[i] - nums[i - 1]));
    }
    return max_diff;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 4};
  int result = solution.maxAdjacentDistance(nums);
  std::cout << "result: " << result << std::endl;
}