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
  int minimumRecolors(string blocks, int k) {
    int n = blocks.size();
    int min_white = 0;
    int white_num = 0;
    for (int i = 0; i < k; i++) {
      if ('W' == blocks[i]) {
        min_white++;
        white_num++;
      }
    }
    for (int i = 1; i < n - k + 1; i++) {
      if ('W' == blocks[i - 1]) {
        white_num--;
      }
      if ('W' == blocks[i - 1 + k]) {
        white_num++;
      }
      min_white = min(min_white, white_num);
    }
    return min_white;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string blocks = "WBWBBBW";
  int result = solution.minimumRecolors(blocks, 2);
  std::cout << "result: " << result << std::endl;
}