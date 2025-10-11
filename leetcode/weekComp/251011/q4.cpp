#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>
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
  long long maxAlternatingSum(vector<int> &nums, vector<vector<int>> &swaps) {
    // 找连通域，然后把连通域的左右的值进行对调
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> swaps = {{0, 2}, {1, 2}};
  long long result = solution.maxAlternatingSum(nums, swaps);
  std::cout << "result: " << result << std::endl;
  return 0;
}