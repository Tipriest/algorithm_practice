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
  string pathEncryption(string path) {
    int n = path.size();
    for (int i = 0; i < n; i++) {
      if ('.' == path[i]) {
        path[i] = ' ';
      }
    }
    return path;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string path = "a.aef.qerf.bb";
  string result = solution.pathEncryption(path);
  std::cout << "result: " << result << std::endl;
}