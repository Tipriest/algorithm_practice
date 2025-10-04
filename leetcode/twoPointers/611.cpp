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
  int triangleNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int res = 0;
    for (int i = n - 1; i > 1; i--) {
      int l = 0, r = i - 1;
      //  如果两边之和小于第三边
      while (l < r) {
        if (nums[l] + nums[r] <= nums[i]) {
          l++;
        } else {
          res += r - l;
          r--;
        }
      }
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {2, 2, 3, 4};
  int result = solution.triangleNumber(nums);
  std::cout << "result: " << result << std::endl;
  return 0;
}