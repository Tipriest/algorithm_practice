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
  bool existZero(int n) {
    if (0 == n) {
      return true;
    }
    if (n < 0) {
      throw std::runtime_error("invalid input");
    }
    while (n > 0) {
      if (0 == n % 10) {
        return true;
      }
      n /= 10;
    }
    return false;
  }
  vector<int> getNoZeroIntegers(int n) {
   for(int i = 1; i < n; i++){
      if(existZero(i)){
         continue;
      }
      if(existZero(n-i)){
         continue;
      }else{
         return {i, n-i};
      }
   }
   throw std::runtime_error("invalid output");
   return {};
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  vector<int> result = solution.getNoZeroIntegers(1010);
  // std::cout << "result: " << result << std::endl;
  return 0;
}