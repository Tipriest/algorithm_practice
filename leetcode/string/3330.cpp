#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
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
class Solution {
public:
  int possibleStringCount(string word) {
    stack<char> st;
    st.push(word[0]);
    int n = word.size();
    vector<int> segs;
    int temp_seg_num = 0;
    for(int i = 1; i < n; i++){
        if(word[i] == st.top()){
            temp_seg_num++;
        }else{
            st.push(word[i]);
            segs.push_back(temp_seg_num);
            temp_seg_num = 0;
        }
    }
    segs.push_back(temp_seg_num);
    int result = 1;
    for (int seg_num : segs) {
      result += seg_num;
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string word = "ere";
  int result = solution.possibleStringCount(word);
  std::cout << "result: " << result << std::endl;
}