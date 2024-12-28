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
  int dominantIndex(vector<int> &nums) {
   priority_queue<int, vector<int>, greater<int>> pq;
   for(int num : nums){
      if(pq.size()<2){
         pq.push(num);
      }else{
         if(num > pq.top()){
            pq.push(num);
            pq.pop();
         }
      }
   }
   int a = pq.top();
   pq.pop();
   int b = pq.top();
   return b >= 2 * a ? std::distance(nums.begin(), std::find(nums.begin(), nums.end(), b)) : -1;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> nums = {3, 6, 1, 0};
   int result = solution.dominantIndex(nums);
   std::cout << "result: " << result << std::endl;
}