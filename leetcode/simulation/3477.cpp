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
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    vector<bool> used(baskets.size(), false);
    int unpacked = fruits.size();
    for(int fruit : fruits){
        for(int j = 0; j < baskets.size(); j++){
            if(false == used[j] && fruit <= baskets[j]){
                used[j] = true;
                unpacked --;
                break;
            }
        }
    }
    return unpacked;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> fruits = {4, 2, 5}, baskets = {3, 5, 4};
   int result = solution.numOfUnplacedFruits(fruits, baskets);
   std::cout << "result: " << result << std::endl;
}