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
  int countServers(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> x(m, 0), y(n, 0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        x[i] += grid[i][j];
      }
    }
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < m; i++) {
        y[j] += grid[i][j];
      }
    }
    int result = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if ((x[i] > 1 || y[j] > 1) && 1 == grid[i][j] ) {
          result++;
        }
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> nums = {
      {1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  int result = solution.countServers(nums);
  std::cout << "result: " << result << std::endl;
}