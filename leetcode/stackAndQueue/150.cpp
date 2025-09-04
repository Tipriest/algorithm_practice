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
  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    for(string token : tokens){
      if (token == "+" || token == "-" || token == "*" || token == "/"){
        int b = st.top();
        st.pop();
        int a = st.top();
        st.pop();
        if (token == "+"){
            st.push(a+b);
        } else if (token == "-") {
          st.push(a - b);
        } else if (token == "*") {
          st.push(a * b);
        } else if (token == "/") {
          st.push(a / b);
        }
      }else{
        st.push(stoll(token));
      }
    }
    return st.top();

  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<string> tokens = {"2", "1", "+", "3", "*"};
   int result = solution.evalRPN(tokens);
   std::cout << "result: " << result << std::endl;
}