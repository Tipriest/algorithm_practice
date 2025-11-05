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
  int triangularSum(vector<int> &nums) {
    int n = nums.size();
    int k = n - 1;
    while(k){
      for (int i = 0; i < k; i++) {
        nums[i] = (nums[i] + nums[i + 1]) % 10;
      }
      k--;
    }
    return nums[0];
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 3, 4, 5};
  int result = solution.triangularSum(nums);
  std::cout << "result: " << result << std::endl;
  return 0;
}