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
  int findNextNum(const vector<int> &nums, int _i, bool isEven) const {
    int n = nums.size();
    for (int i = _i + 1; i < n; i++) {
      if (isEven && 0 == nums[i] % 2) {
        return i;
      } else if (!isEven && 1 == nums[i] % 2) {
        return i;
      }
    }
    throw std::runtime_error("falsed return");
    return 0;
  }
  vector<int> sortArrayByParityII(vector<int> &nums) {
    bool isEven = true;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      if (isEven && 0 == nums[i] % 2) {
      } else if (!isEven && 1 == nums[i] % 2) {
      } else {
        swap(nums[i], nums[findNextNum(nums, i, isEven)]);
      }
      isEven = !isEven;
    }
    return nums;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {3, 1, 4, 2};
  vector<int> result = solution.sortArrayByParityII(nums);
  return 0;
  //   std::cout << "result: " << result << std::endl;
}