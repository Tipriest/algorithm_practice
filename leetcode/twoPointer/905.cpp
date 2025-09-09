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
  vector<int> sortArrayByParity(vector<int> &nums) {
    int j = 1;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      // 如果nums[i]是奇数
      if (1 == nums[i] % 2) {
        j = i + 1;
        while (j < n && 1 == nums[j] % 2) {
          j++;
        }
        if (n == j) {
          return nums;
        }
        swap(nums[i], nums[j]);
      }
    }
    return nums;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {3, 1, 2, 4};
  vector<int> result = solution.sortArrayByParity(nums);
  // std::cout << "result: " << result << std::endl;
  return 0;
}