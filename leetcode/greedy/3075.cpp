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
  long long maximumHappinessSum(vector<int> &happiness, int k) {
    sort(happiness.begin(), happiness.end(), std::greater());
    long long res = 0;
    for (int i = 0; i < k; i++) {
      res += (happiness[i] - i) >= 0 ? happiness[i] - i : 0;
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {12, 1, 42};
  int k = 2;
  int result = solution.maximumHappinessSum(nums, k);
  std::cout << "result: " << result << std::endl;
}