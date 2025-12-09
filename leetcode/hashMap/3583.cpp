#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
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
  const int mod = 1e9 + 7;
  int specialTriplets(vector<int> &nums) {
    long res = 0;
    unordered_map<int, int> umap;
    int n = nums.size();
    for (int i = 2; i < n; i++) {
      umap[nums[i]]++;
    }
    unordered_map<int, int> umap_front;
    umap_front[nums[0]]++;
    for (int i = 1; i < n - 1; i++) {
      res = (res + umap_front[nums[i] * 2] * umap[nums[i] * 2]) % mod;
      umap_front[nums[i]]++;
      umap[nums[i + 1]]--;
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {84, 2, 93, 1, 2, 2, 26};
  int result = solution.specialTriplets(nums);
  std::cout << "result: " << result << std::endl;
}