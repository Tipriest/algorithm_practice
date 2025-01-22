#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>
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

class Solution {
public:
  string removeDuplicates(string s) {
    stack<char> st;
    for(char ch : s){
        if(!st.empty() && ch == st.top()){
            st.pop();
        }else{
            st.push(ch);
        }
    }
    string result;
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return string(result.rbegin(), result.rend());
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   string s = "azxxzy";
   int result = solution.maxProfit(nums);
   std::cout << "result: " << result << std::endl;
}