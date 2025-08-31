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
  void addVs(int n, unordered_map<int, int> &umap) {
    while (0 != n) {
      int temp = n % 10;
      n /= 10;
      umap[temp]++;
    }
  }
  bool isFascinating(int n) {
    unordered_map<int, int> umap;
    addVs(n, umap);
    addVs(2 * n, umap);
    addVs(3 * n, umap);
    if (0 != umap[0]) {
      return false;
    }
    for (int i = 1; i <= 9; i++) {
      if (1 != umap[i]) {
        return false;
      }
    }
    return true;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.isFascinating(192);
  std::cout << "result: " << result << std::endl;
}