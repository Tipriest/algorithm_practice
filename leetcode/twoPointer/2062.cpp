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
  int countVowelSubstrings(string word) {
   unordered_map<char, int> umap;
   int l = 0, r = 0;
   int n = word.size();
   int result = 0;
   unordered_set<char> uset = {'a', 'e', 'i', 'o', 'u'};
   for(int l = 0; l < n; l++){
      umap.clear();
      for(int r = l; r < n; r++){
         if(uset.find(word[r]) == uset.end()){
            break;
         }else{
            umap[word[r]]++;
            if (umap['a'] && umap['e'] && umap['i'] && umap['o'] && umap['u']) {
              result++;
            } else {
               continue;
            }
         }
      }
   }
   return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "aeiouu";
  int result = solution.countVowelSubstrings(s);
  std::cout << "result: " << result << std::endl;
}