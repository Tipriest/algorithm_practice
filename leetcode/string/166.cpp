#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>
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
  string fractionToDecimal(int _np, int _dp) {
    long _n = _np, _d = _dp;
    if (0 == _n) {
      return "0";
    }
    int sign = (_n > 0 && _d > 0) || (_n < 0 && _d < 0);
    long part1 = _n / _d;
    _n = _n % _d;
    vector<int> vpp;
    long cur_beichushu = _n * 10;
    int index = 0;
    while (0 != cur_beichushu && !umap.count(cur_beichushu)) {
      // 小数部分，已经不区分正负了
      vpp.push_back(abs(cur_beichushu / _d));
      umap[cur_beichushu] = index;
      cur_beichushu = (cur_beichushu % _d) * 10;
      index++;
    }
    string res;
    if (0 == sign) {
      res += '-';
    }
    res += std::to_string(abs(part1));
    if (0 == _n) {
      return res;
    }
    res += '.';
    if (0 == cur_beichushu) {
      for (int vp : vpp) {
        res += std::to_string(vp);
      }
      return res;
    } else {
      int n = vpp.size();
      for (int i = 0; i < n; i++) {
        if ((umap[cur_beichushu]) == i) {
          res += '(';
        }
        res += std::to_string(vpp[i]);
      }
      res += ')';
    }
    return res;
  }
  unordered_map<int, int> umap;
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int a = -2147483648, b = 1;
  string result = solution.fractionToDecimal(a, b);
  std::cout << "result: " << result << std::endl;
  return 0;
}