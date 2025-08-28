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
  int mySqrt(int x) {
   // 袖珍计算器法
   // sqrt(x) = exp(0.5*ln(x))
   if(0 == x){
      return 0;
   }
   int res = exp(0.5 * log(x));
   if(pow(res+1, 2)<= x){
      return res+1;
   }
   return res;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> nums = {7, 1, 5, 3, 6, 4};
   int result = solution.mySqrt(4);
   std::cout << "result: " << result << std::endl;
}