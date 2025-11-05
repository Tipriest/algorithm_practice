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
  int maximumEnergy(vector<int> &energy, int k) {
    vector<int> res(k, 0);
    int n = energy.size();
    // 对于结尾之前k个东西，可选可不选
    for (int i = 0; i < n; i++) {
      if (i < n - k) {
        res[i % k] = max(0, res[i % k] + energy[i]);
      } else {
        res[i % k] += energy[i];
      }
    }
    return *max_element(res.begin(), res.end());
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> energy = {5, 2, -10, -5, 1};
  int result = solution.maximumEnergy(energy, 3);
  std::cout << "result: " << result << std::endl;
  return 0;
}