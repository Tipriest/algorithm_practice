#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
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
  int maxDistinctElements(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    uset.insert(nums[0] - k);
    int cur_set_top = nums[0] - k;
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      int v = max(nums[i] - k, cur_set_top + 1);
      while (v <= nums[i] + k) {
        if (uset.count(v)) {
          v++;
        } else if (!uset.count(v)) {
          uset.insert(v);
          cur_set_top = v;
          v++;
          break;
        }
      }
    }
    return uset.size();
  }
  unordered_set<int> uset;
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 2, 3, 3, 4};
  int k = 2;
  int result = solution.maxDistinctElements(nums, k);
  std::cout << "result: " << result << std::endl;
}