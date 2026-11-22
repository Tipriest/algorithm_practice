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
  int findSameSP(vector<int> &parent, string s, int id, char tc) {
    // 已经是根节点了
    if (-1 == parent[id]) {
      return -1;
    }
    // 对于不是根节点的，去找那个一样的s的祖先节点
    if (tc == s[parent[id]]) {
      return parent[id];
    } else {
      return findSameSP(parent, s, parent[id], tc);
    }
    return 0;
  };
  bool isParent(vector<int> &parent, int id, int i) {
    // id是不是i的父亲
    if (id == i) {
      return true;
    }
    if (-1 == i) {
      return false;
    }
    return isParent(parent, id, parent[i]);
  }
  int calSubTreeSize(vector<int> &parent, int id) {
    int n = parent.size();
    if (-1 == parent[id]) {
      return n;
    }
    int result = 0; //
    for (int i = 0; i < n; i++) {
      if (i == id) {
        result++;
      } else if (isParent(parent, id, i)) {
        result++;
      }
    }
    return result;
  };
  vector<int> findSubtreeSizes(vector<int> &parent, string s) {
    vector<int> parent_copy = parent;
    int n = parent.size();
    for (int i = 1; i < n; i++) {
      char tc = s[i];
      int res = findSameSP(parent_copy, s, i, tc);
      if (-1 == res) {
        continue;
      } else {
        parent[i] = res;
      }
    }
    vector<int> answer(n, 0);
    for (int i = 0; i < n; i++) {
      answer[i] = calSubTreeSize(parent, i);
    }
    return answer;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> parent = {-1, 0, 0, 1, 1, 1};
  string s = "abaabc";
  vector<int> result = solution.findSubtreeSizes(parent, s);
  //    std::cout << "result: " << result << std::endl;
  return 0;
}