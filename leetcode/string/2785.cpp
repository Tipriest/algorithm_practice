#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
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
  string sortVowels(string s) {
    map<char, int> map;
    unordered_set<char> uset(
        {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
    for (char ch : s) {
      if (uset.find(ch) != uset.end()) {
        map[ch]++;
      }
    }
    queue<char> qu;
    for (auto iter : map) {
      for (int i = 0; i < iter.second; i++) {
        qu.push(iter.first);
      }
    }
    for (char &ch : s) {
      if (uset.find(ch) != uset.end()) {
        ch = qu.front();
        qu.pop();
      }
    }
    return s;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  string result = solution.sortVowels("lEetcOde");
  std::cout << "result: " << result << std::endl;
  return 0;
}