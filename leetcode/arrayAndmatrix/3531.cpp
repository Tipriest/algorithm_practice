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
  int countCoveredBuildings(int n, vector<vector<int>> &buildings) {
    vector<int> row_min(n + 1, INT32_MAX);
    vector<int> row_max(n + 1);
    vector<int> col_min(n + 1, INT32_MAX);
    vector<int> col_max(n + 1);
    for (auto &building : buildings) {
      int row = building[0];
      int col = building[1];
      row_min[row] = min(row_min[row], col);
      row_max[row] = max(row_max[row], col);
      col_min[col] = min(col_min[col], row);
      col_max[col] = max(col_max[col], row);
    }
    int res = 0;
    for (auto &building : buildings) {
      int row = building[0], col = building[1];
      if (row > col_min[col] && row < col_max[col] && col > row_min[row] &&
          col < row_max[row]) {
        res++;
      }
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  int n = 4;
  vector<vector<int>> buildings = {{2, 4}, {1, 2}, {3, 1}, {1, 4},
                                   {2, 3}, {3, 3}, {2, 2}, {1, 3}};
  int result = solution.countCoveredBuildings(n, buildings);
  std::cout << "result: " << result << std::endl;
}