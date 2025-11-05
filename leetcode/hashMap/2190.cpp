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
  int mostFrequent(vector<int> &nums, int key) {
   unordered_map<int, int> umap;
   int n = nums.size();
   for(int i = 0; i < n-1; i++){
      if(key == nums[i]){
         umap[nums[i+1]]++;
      }
   }
   int max_num = -1;
   int target = 0;
   for(auto iter : umap){
      if(iter.second>max_num){
         target = iter.first;
         max_num = iter.second;
      }
   }
   return target;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> nums = {1, 100, 200, 1, 100};
   int key = 1;
   int result = solution.mostFrequent(nums, key);
   std::cout << "result: " << result << std::endl;
}