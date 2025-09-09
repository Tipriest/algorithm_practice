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
  string interpret(string command) {
    string pattern;
    string result;
    int n = command.size();
    for (int i = 0; i < n; i++) {
      pattern.push_back(command[i]);
      if (pattern == "G") {
        result.push_back('G');
      } else if (pattern == "()") {
        result.push_back('o');
      } else if (pattern == "(al)") {
        result.append("al");
      } else {
        continue;
      }
      pattern.clear();
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  string result = solution.interpret("(al)G(al)()()G");
  std::cout << "result: " << result << std::endl;
}