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
  vector<int> plusOne(vector<int> &digits) {
    vector<int> digits_v = vector(digits.rbegin(), digits.rend());
    int ans = 0;
    int n = digits_v.size();
    for (int i = 0; i < n; i++) {
      if (0 == i) {
        if (digits_v[0] + 1 < 10) {
          digits_v[0] = digits_v[0] + 1;
          break;
        } else {
          digits_v[0] = 0;
          ans = 1;
        }
      } else {
        if (digits_v[i] + ans < 10) {
          digits_v[i] = digits_v[i] + ans;
          ans = 0;
        } else {
          digits_v[i] = 0;
          ans = 1;
        }
      }
    }
    if (ans != 0) {
      digits_v.push_back(ans);
    }
    return vector(digits_v.rbegin(), digits_v.rend());
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {9, 9, 9};
  vector<int> result = solution.plusOne(nums);
  //    std::cout << "result: " << result << std::endl;
  return 0;
}