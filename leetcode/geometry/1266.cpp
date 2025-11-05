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
  int calSteps(const vector<int> &p1, const vector<int> &p2) {
    int dx = abs(p1[0] - p2[0]), dy = abs(p1[1] - p2[1]);
    return min(dx, dy) + abs(dx - dy);
  }
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
   int n = points.size();
   int res = 0;
   for(int i = 0; i < n-1; i++){
      res+= calSteps(points[i], points[i+1]);
   }
   return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> points = {{1,1}, {3,4}, {-1, 0}};
  int result = solution.minTimeToVisitAllPoints(points);
  std::cout << "result: " << result << std::endl;
  return 0;
}