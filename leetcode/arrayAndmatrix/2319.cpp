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
  bool checkXMatrix(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j || i + j == n - 1) {
          if (0 == grid[i][j]) {
            return false;
          } else {
            continue;
          }
        } else {
          if (0 != grid[i][j]) {
            return false;
          } else {
            continue;
          }
        }
      }
    }
    return true;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> grids = {
      {2, 0, 0, 1}, {0, 3, 1, 0}, {0, 5, 2, 0}, {4, 0, 0, 2}};
  int result = solution.checkXMatrix(grids);
  std::cout << "result: " << result << std::endl;
}