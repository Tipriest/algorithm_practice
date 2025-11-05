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
  int findString(vector<string> &words, string s) {
   int l = 0, r = words.size()-1;
   while(l <= r){
      int m = l + (r - l)/2;
      int m_t = m;
      while(words[m] == "" && m < r){
         m++;
      }
      if(words[m] == ""){
         r = m_t -1;
         continue;
      }else{
         if(s == words[m]){
            return m;
         }else if(s < words[m]){
            r = m-1;
         }else{
            l = m+1;
         }
      }
   }
   return -1;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<string> nums = {"at",  "", "", "",    "ball", "", "",
                         "car", "", "", "dad", "",     ""};
  string s = "ta";
  int result = solution.findString(nums, s);
  std::cout << "result: " << result << std::endl;
}