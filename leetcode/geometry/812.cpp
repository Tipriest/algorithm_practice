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
  double calArea(vector<vector<int>> &points) {
    if (3 != points.size()) {
      throw std::runtime_error("invaild input");
      return 0;
    }
    int x1 = points[0][0], y1 = points[0][1], x2 = points[1][0],
        y2 = points[1][1], x3 = points[2][0], y3 = points[2][1];
    return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
  }
  double largestTriangleArea(vector<vector<int>> &points) {
    int n = points.size();
    double res = 0;
    for(int a = 0; a < n; a ++){
      for(int b = a+1; b < n; b++){
        for(int c = b+1; c < n; c++){
          vector<vector<int>> selpoints = {points[a], points[b], points[c]};
          res = max(res, calArea(selpoints));
        }
      }
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0}, {2, 0}, {0, 2}};
  int result = solution.largestTriangleArea(points);
  std::cout << "result: " << result << std::endl;
  return 0;
}