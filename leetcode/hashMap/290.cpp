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
  bool wordPattern(string pattern, string s) {
    vector<string> vs;
    string word;
    for (char ch : s) {
      if (' ' == ch) {
        vs.push_back(word);
        word.clear();
      } else {
        word.push_back(ch);
      }
    }
    if(0 != word.size()){
      vs.push_back(word);
    }
    unordered_map<char, string> umap;
    if(pattern.size()!=vs.size()){
      return false;
    }
    unordered_set<char> uset1;
    unordered_set<string> uset2;
    for(char ch : pattern){
      uset1.insert(ch);
    }
    for(string _word : vs){
      uset2.insert(_word);
    }
    if(uset1.size()!=uset2.size()){
      return false;
    }

    for(int i = 0; i < vs.size(); i++){
      if (umap.find(pattern[i]) == umap.end()) {
        umap[pattern[i]] = vs[i];
      } else {
        if (umap[pattern[i]] != vs[i]) {
          return false;
        } else {
          continue;
        }
      }
    }
    return true;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string pattern = "abba";
  string s = "dog dog dog dog";
  int result = solution.wordPattern(pattern, s);
  std::cout << "result: " << result << std::endl;
}