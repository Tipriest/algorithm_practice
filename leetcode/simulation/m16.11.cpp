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
  vector<int> divingBoard(int shorter, int longer, int k) {
    if (0 == k) {
      return {};
    }
    if (shorter == longer) {
      return {shorter * k};
    }
    vector<int> res;
    int i = 0;
    while (i <= k) {
      res.push_back(i * longer + (k - i) * shorter);
      i++;
    }
    return res;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   int shorter = 2;
   int longer = 1118596;
   int k = 979;
   vector<int> result = solution.divingBoard(shorter, longer, k);
   // std::cout << "result: " << result << std::endl;
   return 1;
}