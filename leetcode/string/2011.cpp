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
  int finalValueAfterOperations(vector<string> &operations) {
   int res = 0;
   for(string operation : operations){
     if (operation[0] == '-' || operation[2] == '-'){
      res --;
     }else{
      res ++;
     }
   }
   return res;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<string> operations = {"--X", "X++", "X++"};
   int result = solution.finalValueAfterOperations(operations);
   std::cout << "result: " << result << std::endl;
}