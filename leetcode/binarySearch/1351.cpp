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
  int countNegatives(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int last_col = n;
    int res = m * n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < last_col; j++) {
        if (grid[i][j] >= 0) {
          res--;
        } else {
          last_col = j;
          break;
        }
      }
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> grid = {
      {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
  int result = solution.countNegatives(grid);
  std::cout << "result: " << result << std::endl;
}