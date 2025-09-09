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
  bool areNumbersAscending(string s) {
   int ans = -1;
   int n = s.size();
   for(int i = 0; i < n; i++){
      if (!isdigit(s[i])){
         continue;
      }
      int temp = 0;
      while (isdigit(s[i])) {
        temp = temp * 10 + s[i] - '0';
        i++;
        }
      if(temp <= ans){
         return false;
      }else{
         ans = temp;
      }
   }
   return true;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
  int result = solution.areNumbersAscending(s);
  std::cout << "result: " << result << std::endl;
}