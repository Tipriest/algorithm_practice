#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
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
  int ten_to_bin_bit(int a) {
    int result = 1;
    while (a > 1) {
      a /= 2;
      result++;
    }
    return result;
  }
  int string_to_num(string a) {
    int result = 0;
    for (char ch : a) {
      result = result * 2 + ch - '0';
    }
    return result;
  }
  int longestSubsequence(string s, int k) {
    int num = ten_to_bin_bit(k);
    int n = s.size();
    if(n < num){
        return n;
    }
    string back_num_of_s(s.end() - num, s.end());
    int back_num = string_to_num(back_num_of_s);
    int result = 0;
    if(back_num > k){
        result += num -1;
    }else{
        result += num;
    }
    
    for(int i = 0; i <n - num; i++){
        if(s[i] == '0'){
            result ++;
        }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "0";
  int result = solution.longestSubsequence(s, 583196182);
  std::cout << "result: " << result << std::endl;
}