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
  string removeDigit(string number, char digit) {
    int n = number.size();
    string result;
    bool removed = false;
    for(int i = n-1; i >= 0; i--){
        if(!removed && number[i] == digit){
            removed = true;
            continue;
        }else{
            result += number[i];
        }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   string number = "123";
   char digit = '3';
   string result = solution.removeDigit(number, digit);
   std::cout << "result: " << result << std::endl;
}