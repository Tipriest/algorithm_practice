#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <map>
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
  int totalFruit(vector<int> &fruits) {
    int ans = 0, left = 0;
    unordered_map<int, int> umap;
    for(int right = 0; right <fruits.size(); right++){
        // 增加一个新的水果类型
        umap[fruits[right]]++;
        // 判断是否满足要求
        while(umap.size()>2){
            int out = fruits[left];
            umap[fruits[left]]--;
            if(0 == umap[fruits[left]]){
                umap.erase(fruits[left]);
            }
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> nums = {1, 2, 3, 2, 2};
   int result = solution.totalFruit(nums);
   std::cout << "result: " << result << std::endl;
}