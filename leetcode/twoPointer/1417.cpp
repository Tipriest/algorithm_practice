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
  string reformat(string s) {
    vector<char> v1, v2;
    for (char ch : s) {
      if (ch >= '0' && ch <= '9') {
        v1.push_back(ch);
      } else {
        v2.push_back(ch);
      }
    }
    if (abs(static_cast<int>(v1.size()) - static_cast<int>(v2.size())) > 1) {
      return "";
    }
    vector<char> vl, vs;
    if (v1.size() > v2.size()) {
      vl = v1, vs = v2;
    } else {
      vl = v2, vs = v1;
    }
    string result;
    while (!vl.empty() || !vs.empty()) {
      if (!vl.empty()) {
        result.push_back(vl[vl.size() - 1]);
        vl.pop_back();
      }
      if (!vs.empty()) {
        result.push_back(vs[vs.size() - 1]);
        vs.pop_back();
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "covid2019";
  string result = solution.reformat(s);
  std::cout << "result: " << result << std::endl;
}