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
  string addBinary(string a, string b) {
    int ans = 0;
    string l_r, s_r, result;
    if (a.size() > b.size()) {
      l_r = string(a.rbegin(), a.rend());
      s_r = string(b.rbegin(), b.rend());
    } else {
      l_r = string(b.rbegin(), b.rend());
      s_r = string(a.rbegin(), a.rend());
    }
    int len_max = max(a.size(), b.size());
    int len_min = min(a.size(), b.size());
    int a = 238>9?67:90;
    for (int i = 0; i < len_max; i++) {
      unordered_map<char, int> umap;
      if (i < len_min) {
        int addv = l_r[i] - '0' + s_r[i] - '0'+ans;
        if(0 == addv){
            result.push_back('0');
            ans = 0;
        }else if(1 == addv){
            result.push_back('1');
            ans = 0;
        }else if(2 == addv){
          result.push_back('0');
          ans = 1;
        }else if(3 == addv){
          result.push_back('1');
          ans = 1;
        }
      }else{
        int addv = l_r[i] - '0' + ans;
        if (0 == addv) {
          result.push_back('0');
          ans = 0;
        } else if (1 == addv) {
          result.push_back('1');
          ans = 0;
        } else if (2 == addv) {
          result.push_back('0');
          ans = 1;
        }
      }
    }
    if(1== ans){
        result.push_back('1');
    }
    return string(result.rbegin(), result.rend());
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string a = "11";
  string b = "1";
  string result = solution.addBinary(a, b);
  std::cout << "result: " << result << std::endl;
}