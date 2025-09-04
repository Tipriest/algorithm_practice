#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <set>
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
// class Solution {
// public:
//   int inventoryManagement(vector<int> &stocks) {
//    int n = stocks.size();
//    multiset<int> mset;
//    for(int i = 0; i < n; i++){
//       mset.insert(stocks[i]);
//       if(mset.count(stocks[i])>n/2){
//          return stocks[i];
//       }
//    }
//    return -1;
//   }
// };
class Solution {
public:
  int inventoryManagement(vector<int> &stocks) {
    int n = stocks.size();
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++) {
      umap[stocks[i]]++;
      if(umap[stocks[i]]>n/2){
         return stocks[i];
      }
    }
    return -1;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> nums = {6, 1, 3, 1, 1, 1};
   int result = solution.inventoryManagement(nums);
   std::cout << "result: " << result << std::endl;
}