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
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
   unordered_set<int>  uset;
   for(int num: nums1){
      uset.insert(num);
   }
   for(int num : nums2){
      if(uset.find(num) != uset.end()){
         return num;
      }
   }
   return -1;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> nums1 = {1, 2, 3, 6};
   vector<int> nums2 = {2, 3, 4, 5};
   int result = solution.getCommon(nums1, nums2);
   std::cout << "result: " << result << std::endl;
}