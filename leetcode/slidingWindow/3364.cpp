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
  int minimumSumSubarray(vector<int> &nums, int l, int r) {
    int n = nums.size();
    // 不算我自己的前面的数的和
    vector<int> prefixArray(n + 1, 0);
    for (int i = 0; i < n; i++) {
      prefixArray[i + 1] = prefixArray[i] + nums[i];
    }
    int min_sum = INT32_MAX;
    for (int i = 0; i <= n; i++) {
      // i是左上限, 然后下面计算右上限 j
      for (int k = l; k <= r; k++) {
        int j = i + k;
        if (j <= n) {
          int v = prefixArray[j] - prefixArray[i];
          if (v > 0 && v < min_sum) {
            min_sum = v;
          }
        }
      }
    }
    return min_sum == INT_MAX ? -1 : min_sum;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7,3};
  int l = 2, r = 2;
  int result = solution.minimumSumSubarray(nums, l, r);
  std::cout << "result: " << result << std::endl;
}