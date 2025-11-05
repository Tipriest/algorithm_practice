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
  int maxFrequencyElements(vector<int> &nums) {
   unordered_map<int, int> umap;
   for(int num : nums){
      umap[num]++;
   }
   priority_queue<int> pque;
   for(auto iter :umap){
      pque.push(iter.second);
   }
   int mv = pque.top();
   int res = 0;
   while(!pque.empty()){
      if(mv == pque.top()){
         res += mv;
         pque.pop();
      }else{
         break;
      }
   }
   return res;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> nums = {7, 1, 5, 3, 6, 4};
   int result = solution.maxFrequencyElements(nums);
   std::cout << "result: " << result << std::endl;
   return 0;
}