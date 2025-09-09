#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
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
class Solution {
public:
  bool iszhishu(int num) {
    if (num <= 1) {
      return false;
    }
    int n = sqrt(num);
    for (int i = 2; i <= n; i++) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
  }
  bool checkPrimeFrequency(vector<int> &nums) {
    unordered_map<int, int> umap;
    for (int num : nums) {
      umap[num]++;
    }
    unordered_set<int> uset;
    for (auto cur : umap) {
      uset.insert(cur.second);
    }
    for (int num : uset) {
      if (iszhishu(num)) {
        return true;
      }
    }
    return false;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 3, 4, 5, 4};
  int result = solution.checkPrimeFrequency(nums);
  std::cout << "result: " << result << std::endl;
}