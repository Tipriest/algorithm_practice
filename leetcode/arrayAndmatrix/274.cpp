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
  int hIndex(vector<int> &citations) {
    sort(citations.begin(), citations.end(),
         [](int a, int b) { return a > b; });
    int n = citations.size();
    if (1 == n || citations[0] < 1) {
      return min(citations[0], 1);
    }
    for (int i = 0; i < n; i++) {
      if (i + 1 > citations[i]) {
        return min(citations[i - 1], i);
      }
    }
    cout << "error occured" << endl;
    return 0;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> citations = {11, 15};
  int result = solution.hIndex(citations);
  std::cout << "result: " << result << std::endl;
}