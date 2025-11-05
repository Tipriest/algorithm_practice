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
  int canBeTypedWords(string text, string brokenLetters) {
   unordered_set<char> uset(brokenLetters.begin(), brokenLetters.end());
   int result = 0;
   bool temp_ok = true;
   for(char ch : text){
      if(' ' == ch){
         result+=temp_ok;
         temp_ok = true;
      }else if(uset.count(ch)){
         temp_ok = false;
      }
   }
   result += temp_ok;
   return result;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> nums = {7, 1, 5, 3, 6, 4};
   int result = solution.canBeTypedWords("leet code", "lt");
   std::cout << "result: " << result << std::endl;
   return 0;
}