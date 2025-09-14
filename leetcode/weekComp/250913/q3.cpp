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
  vector<vector<int>> generateSchedule(int n) {
    
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 3, 9, 9, 7, 3, 5, 9, 7, 2, 6, 10, 9, 7, 9,
                      1, 3, 6, 2, 4, 6, 2, 6, 8, 4, 8, 2,  7, 5, 6};
  vector<vector<int>> results = solution.generateSchedule(5);
  // std::cout << "result: " << result << std::endl;
  for (vector<int> result : results) {
    std::cout << "[ " << result[0] << result[1] << "] " << std::endl;
  }
  return 0;
}