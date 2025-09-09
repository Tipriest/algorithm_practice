#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

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
  string reversePrefix(string word, char ch) {
    stack<char> st;
    string result;
    int n = word.size();
    int i = 0;
    bool meet = false;
    for (; i < n; i++) {
      if (ch != word[i]) {
        st.push(word[i]);
      } else {
        st.push(word[i]);
        i++;
        meet = true;
        break;
      }
    }
    if(meet){
      while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
      }
      for (; i < n; i++) {
        result.push_back(word[i]);
      }
      return result;
    }else{
      return word;
    }
    return word;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string word = "abcd";
  char ch = 'z';
  string result = solution.reversePrefix(word, ch);
  std::cout << "result: " << result << std::endl;
}