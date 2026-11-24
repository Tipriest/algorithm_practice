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
  int maxLength(vector<int> &nums) {
    int n = nums.size();
    int max_len = 0;
    for (int i = 0; i < n; i++) {
      long long prodVal = nums[i];
      long long gcdVal = nums[i];
      long long lcmVal = nums[i];
      for (int j = i + 1; j < n; j++) {
        prodVal *= nums[j];
        gcdVal = gcd(gcdVal, nums[j]);
        lcmVal = lcm(lcmVal, nums[j]);
        if (prodVal == gcdVal * lcmVal) {
          max_len = max(max_len, j - i + 1);
        } else if (prodVal > gcdVal * lcmVal) {
          break;
        }
      }
    }
    return max_len;
  };
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 1, 2, 1, 1, 1};
  int result = solution.maxLength(nums);
  std::cout << "result: " << result << std::endl;
}