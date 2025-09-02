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
  bool checkRegion(const vector<vector<int>> &points, int l, int r) {
    int n = points.size();
    int lx = points[l][0], ly = points[l][1], rx = points[r][0],
        ry = points[r][1];
    // 组成的是一个点
    if (lx == rx && ly == ry) {
      return false;
    }

    if ((lx - rx) * (ly - ry) <= 0) {
      return true;
    }
    return false;
  }
  bool checkAABB(const vector<vector<int>> &points, int l, int r) {
    int n = points.size();
    int lx = min(points[l][0], points[r][0]),
        rx = max(points[l][0], points[r][0]);
    int ly = max(points[l][1], points[r][1]),
        ry = min(points[l][1], points[r][1]);
    for (int i = 0; i < n; i++) {
      if (i == l || i == r) {
        continue;
      }
      int _tx = points[i][0], _ty = points[i][1];
      if (_tx >= lx && _tx <= rx && _ty <= ly && _ty >= ry) {
        return false;
      }
    }
    return true;
  }
  int numberOfPairs(vector<vector<int>> &points) {
    int n = points.size();
    int res = 0;
    for (int l = 0; l < n - 1; l++) {
      for (int r = l + 1; r < n; r++) {
        if (checkRegion(points, l, r) && checkAABB(points, l, r)) {
          res++;
        }
      }
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> points = {{3, 1}, {1, 3}, {1, 1}};
  int result = solution.numberOfPairs(points);
  std::cout << "result: " << result << std::endl;
}