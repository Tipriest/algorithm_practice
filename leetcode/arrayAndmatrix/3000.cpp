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
  int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
    int max_square_bound = 0;
    int max_area = 0;
    for (vector<int> dimension : dimensions) {
      int temp = pow(dimension[0], 2) + pow(dimension[1], 2);
      if (temp == max_square_bound) {
      //   max_square_bound = temp;
        max_area = max(max_area, dimension[0] * dimension[1]);
      } else if (temp > max_square_bound){
        max_square_bound = temp;
        max_area = dimension[0] * dimension[1];
      }
    }
    return max_area;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> nums = {{2, 6}, {5, 1}, {3, 10}, {8, 4}};
  int result = solution.areaOfMaxDiagonal(nums);
  std::cout << "result: " << result << std::endl;
}