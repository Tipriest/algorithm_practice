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
  vector<int> splits(string a) {
    int l = -1, r = 0;
    int n = a.size();
    vector<int> res;
    while (r < n) {
      if ('.' == a[r]) {
        res.push_back(stoi(a.substr(l + 1, r - l - 1)));
        l = r;
      }
      r++;
    }
    res.push_back(stoi(a.substr(l + 1, r - l - 1)));
    return res;
  }
  int compareVersion(string version1, string version2) {
    vector<int> a1 = splits(version1);
    vector<int> a2 = splits(version2);
    while (a1.size() < a2.size()) {
      a1.push_back(0);
    }
    while (a2.size() < a1.size()) {
      a2.push_back(0);
    }
    int n = a1.size();
    for (int i = 0; i < n; i++) {
      if (a1[i] < a2[i]) {
        return -1;
      } else if (a1[i] > a2[i]) {
        return 1;
      }
    }
    return 0;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.compareVersion("1.0.1", "1");
  std::cout << "result: " << result << std::endl;
  return 0;
}