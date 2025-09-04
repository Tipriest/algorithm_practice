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
  // 二分查找法
  int mySqrt(int x) {
    int l = 0, r = x, mid = -1, ans = -1;
    while (l <= r) {
      mid = l + (r - l) / 2;
      if (x < (long)mid * mid) {
        r = mid - 1;
      } else if (x == (long)mid * mid) {
        return mid;
      } else {
        l = mid + 1;
        ans = mid;
      }
    }
    return ans;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.mySqrt(8);
  std::cout << "result: " << result << std::endl;
}