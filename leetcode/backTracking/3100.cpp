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
  int maxArea(vector<int> &heights) {
    int l = 0, r = heights.size() - 1;
    int res = min(heights[l], heights[r]) * (r - l);
    while (l < r) {
      int h = min(heights[l], heights[r]);
      if (heights[l] < heights[r]) {
        while (l < r && heights[l] <= h) {
          l++;
        }
      } else {
        while (l < r && heights[r] <= h) {
          r--;
        }
      }
      if(l >= r){
        break;
      }
      res = max(res, min(heights[l], heights[r]) * (r - l));
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int result = solution.maxArea(nums);
  std::cout << "result: " << result << std::endl;
  return 0;
}