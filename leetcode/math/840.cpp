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
  bool checkisagicSquares(vector<vector<int>> &grid, int i, int j) {
    unordered_set<int> uset;
    for (int m = 0; m < 3; m++) {
      for (int n = 0; n < 3; n++) {
        if (grid[i + m][j + n] < 1 || grid[i + m][j + n] > 9) {
          return false;
        }
        if (uset.find(grid[i + m][j + n]) != uset.end()) {
          return false;
        }
        uset.insert(grid[i + m][j + n]);
      }
    }
    int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
    for (int m = 0; m < 3; m++) {
      if (sum != grid[i + m][j] + grid[i + m][j + 1] + grid[i + m][j + 2]) {
        return false;
      }
    }
    for (int n = 0; n < 3; n++) {
      if (sum != grid[i][j + n] + grid[i + 1][j + n] + grid[i + 2][j + n]) {
        return false;
      }
    }
    if (sum != grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2]) {
      return false;
    }
    if (sum != grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j]) {
      return false;
    }
    return true;
  }
  int numMagicSquaresInside(vector<vector<int>> &grid) {
    if (grid.size() < 3 || grid[0].size() < 3) {
      return 0;
    }
    // 行或者列肯定有一个是3的
    int res = 0;
    // 如果行是3行

    for (int i = 0; i <= grid.size() - 3; i++) {
      for (int j = 0; j <= grid[0].size() - 3; j++) {
        res += checkisagicSquares(grid, i, j);
      }
    }

    return res;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> nums = {{4, 3, 8, 40}, {9, 5, 1, 9}, {2, 7, 6, 2}};
  int result = solution.numMagicSquaresInside(nums);
  std::cout << "result: " << result << std::endl;
}