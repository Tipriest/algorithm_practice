#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <set>
#include <numeric>
#include <map>
#include <unordered_map>
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
  int largestAltitude(vector<int> &gain) {
    int highest = gain[0];
    int curVal = gain[0];
    int n = gain.size();
    for(int i = 1; i < n; i++){
        curVal += gain[i];
        if(curVal > highest){
            highest = curVal;
        }
    }
    return highest;
  }
};


int main() {
   // 示例二叉树
   Solution solution;
   vector<int> gain = {7, 1, 5, 3, 6, 4};
   int result = solution.largestAltitude(gain);
   std::cout << "result: " << result << std::endl;
}