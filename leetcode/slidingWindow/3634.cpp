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
  int minRemoval(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0, r = 0;
    int max_len = 0;
    for (; l < n; l++) {
      int l_value = nums[l];
      for (; r < n; r++) {
        if (nums[r] <= (long)k * l_value) {
          continue;
        } else {
          max_len = max(max_len, r - l);
          break;
        }
      }
      if (n == r) {
        max_len = max(max_len, n - l);
        break;
      }
    }
    return n - max_len;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {2, 1, 5};
  int k = 2;
  int result = solution.minRemoval(nums, k);
  std::cout << "result: " << result << std::endl;
}