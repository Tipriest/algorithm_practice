#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
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
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> umap;
    for (char ch : text) {
      umap[ch]++;
    }
    priority_queue<int, vector<int>, greater<int>> result;
    result.push(umap['b'] / 1);
    result.push(umap['a'] / 1);
    result.push(umap['l'] / 2);
    result.push(umap['o'] / 2);
    result.push(umap['n'] / 1);
    return result.top();
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string text = "lloo";
  int result = solution.maxNumberOfBalloons(text);
  std::cout << "result: " << result << std::endl;
}