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
  TreeNode *make(vector<int> &nums, int l, int r) {
    if(l > r){
      return nullptr;
    }
    int mid = (l+r)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = make(nums, l, mid-1);
    root->right = make(nums, mid + 1, r);
    return root;
  }
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int n = nums.size();
    return make(nums, 0, n-1);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {-10, -3, 0, 5, 9};
  TreeNode *result = solution.sortedArrayToBST(nums);
  std::cout << "result: " << result << std::endl;
  return 0;
}