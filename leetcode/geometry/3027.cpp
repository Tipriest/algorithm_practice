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
  bool checkAABB(const vector<vector<int>> &points, int l, int r) {
    int ly = points[l][1], ry = points[r][1];
    for (int i = l + 1; i < r; i++) {
      int _ty = points[i][1];
      if (_ty <= ly && _ty >= ry) {
        return false;
      }
    }
    return true;
  }
  int numberOfPairs(vector<vector<int>> &points) {
    ranges::sort(points, {}, [](auto &p) { return pair(p[0], -p[1]); });
    int n = points.size();
    int res = 0;
    for (int l = 0; l < n - 1; l++) {
      for (int r = l + 1; r < n; r++) {
        if (points[l][1] - points[r][1] < 0) {
          continue;
        } else {
          if (checkAABB(points, l, r)) {
            res++;
          }
        }
      }
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> points = {{6, 2}, {4, 4}, {2, 6}};
  int result = solution.numberOfPairs(points);
  std::cout << "result: " << result << std::endl;
}