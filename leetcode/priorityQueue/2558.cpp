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
  long long pickGifts(vector<int> &gifts, int k) {
   priority_queue<int, vector<int>, less<int>> pq;
   for(int gift : gifts){
      pq.push(gift);
   }
   while(k>0){
      pq.push(sqrt(pq.top()));
      pq.pop();
      k--;
   }
   long long res = 0;
   while(pq.size()){
      res+=pq.top();
      pq.pop();
   }
   return res;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> nums = {25, 64, 9, 4, 100};
   long long result = solution.pickGifts(nums, 4);
   std::cout << "result: " << result << std::endl;
   return 0;
}