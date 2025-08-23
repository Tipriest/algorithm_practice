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
  int maxScore(string s) {
    int zero_num = 0, one_num = 0;
    for (char ch : s) {
      if ('0' == ch) {
        zero_num++;
      }
    }
    one_num = s.size() - zero_num;
    int left_score = 0;
    int right_score = one_num;
    int total_score = -1;
    int n = s.size();
    for (int i = 0; i < n-1; i++) {
      if ('0' == s[i]) {
        left_score++;
      } else {
        right_score--;
      }
      total_score = max(total_score, left_score + right_score);
    }
    return total_score;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "011101";
  int result = solution.maxScore(s);
  std::cout << "result: " << result << std::endl;
}