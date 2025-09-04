#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <queue>
#include <vector>
#include <functional> //包含std::greater 和 std::less
#include <math.h>
#include <limits.h>
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
  bool partitionArray(vector<int> &nums, int k) {
    int n = nums.size();
    if (0 != n % k) {
      return false;
    }
    int group_num = n / k;
    unordered_map<int, int> umap;
    for (int num : nums) {
      umap[num]++;
      if (umap[num] > group_num) {
        return false;
      }
    }
    return true;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 5, 2, 3};
  int k = 3;
  int result = solution.partitionArray(nums, k);
  std::cout << "result: " << result << std::endl;
}