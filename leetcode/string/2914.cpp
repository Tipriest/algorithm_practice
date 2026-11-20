#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
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
  int minChanges(string s) {
    int n = s.size();
    int result = 0;
    for (int i = 0; i < n; i += 2) {
      if (!(s[i] == '0' && s[i + 1] == '0') &&
          !(s[i] == '1' && s[i + 1] == '1')) {
        result++;
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "0000";
  int result = solution.minChanges(s);
  std::cout << "result: " << result << std::endl;
}