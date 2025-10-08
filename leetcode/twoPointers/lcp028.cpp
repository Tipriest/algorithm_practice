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
  const int mod = 1e9 + 7;
  int purchasePlans(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0, r = n - 1;
    long res = 0;
    while (l < r) {
      if (nums[l] + nums[r] > target) {
        r--;
      } else {
        res += r - l;
        res %= mod;
        l++;
      }
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {2, 5, 3, 5};
  int result = solution.purchasePlans(nums, 6);
  std::cout << "result: " << result << std::endl;
}