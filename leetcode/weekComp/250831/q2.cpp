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
  vector<vector<int>> paths;
  void minDifference(int n, int k, vector<int> &vp) {
    if (1 == k) {
      vp.push_back(n);
      paths.push_back(vp);
      vp.pop_back();
      return;
    }
    for (int i = 1; i <= sqrt(n); i++) {
      if (0 == n % i) {
        vp.push_back(i);
        minDifference(n / i, k - 1, vp);
      }
      vp.pop_back();
    }
  }
  vector<int> minDifference(int n, int k) {
    for (int i = 1; i <= sqrt(n); i++) {
      if (0 == n % i) {
        vector<int> vp;
        vp.push_back(i);
        minDifference(n / i, k - 1, vp);
      }
    }
    vector<int> result;
    int min_diff = 1e6;
    for (vector<int> path : paths) {
      if (k == path.size()) {
        if (*max_element(path.begin(), path.end()) -
                *min_element(path.begin(), path.end()) <
            min_diff) {
          result = path;
          min_diff = *max_element(path.begin(), path.end()) -
                *min_element(path.begin(), path.end());
        }
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> result = solution.minDifference(44, 3);
  // std::cout << "result: " << result << std::endl;
  std::cout << 1 << std::endl;
}