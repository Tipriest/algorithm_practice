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
  string sortString(string s) {
    map<char, int> map;
    for (char ch : s) {
      map[ch]++;
    }
    string result;
    while (0 != map.size()) {
      // 正序遍历
      for (auto iter = map.begin(); iter != map.end(); iter++) {
        if (iter->second > 0) {
          result.push_back(iter->first);
          iter->second--;
        }
      }
      // 反序遍历
      for (auto iter = map.rbegin(); iter != map.rend(); iter++) {
        if (iter->second > 0) {
          result.push_back(iter->first);
          iter->second--;
        }
      }
      // 清除为0的元素
      for (auto iter = map.begin(); iter != map.end();) {
        if (0 == iter->second) {
          iter = map.erase(iter);
        } else {
          iter++;
        }
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "aaaabbbbcccc";
  string result = solution.sortString(s);
  std::cout << "result: " << result << std::endl;
}