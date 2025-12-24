#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
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
  int missingNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      // 等于的话说明不存在的数在这个数的右边
      if (nums[mid] == mid) {
        left = mid + 1;
      } else if (nums[mid] == mid + 1) {
        right = mid - 1;
      }
    }
    return left;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {3, 0, 1};
  int result = solution.missingNumber(nums);
  std::cout << "result: " << result << std::endl;
}