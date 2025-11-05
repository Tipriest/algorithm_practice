#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
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
  int minOperations(string s, int k) {
    int one_num = 0, zero_num = 0;
    for (char ch : s) {
      if ('0' == ch) {
        zero_num++;
      } else {
        one_num++;
      }
    }
    int ops = zero_num / k;
    int zero_num_last = zero_num % k;
    if (0 == zero_num_last) {
      return ops;
    }
    one_num += (zero_num - zero_num_last);
    zero_num = zero_num_last;
    vector<int> pro;
    for (int i = 1; i <= zero_num; i++) {
      if (k - 1 >= one_num) {
        continue;
      } else {
        pro.push_back(zero_num - i + k - i);
      }
    }
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> grid = {{0, 1, 1}, {1, 1, 0}};
  int result = solution.uniquePaths(grid);
  std::cout << "result: " << result << std::endl;
}