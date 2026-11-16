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
  string addSum(string s, int k) {
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
      res += s[i] - '0';
    }
    return std::to_string(res);
  }
  string digitSum(string s, int k) {
    int n = s.size();
    if (n <= k) {
      return s;
    }
    string s_changed = "";
    for (int i = 0; i < n; i += k) {
      int end = i + k - 1 > n ? n : i + k - 1;
      string sub = s.substr(i, end - i + 1);
      s_changed.append(addSum(sub, k));
    }
    return digitSum(s_changed, k);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "11111222223";
  int k = 3;
  string result = solution.digitSum(s, k);
  std::cout << "result: " << result << std::endl;
  return 0;
}