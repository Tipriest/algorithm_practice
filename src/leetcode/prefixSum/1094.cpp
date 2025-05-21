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
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    vector<int> temp =
        *max_element(trips.begin(), trips.end(),
                     [](vector<int> a, vector<int> b) { return a[2] < b[2]; });
    int maxValue = temp[2];
    vector<int> result(maxValue + 1, 0);
    for (vector<int> trip : trips) {
      for (int i = trip[1]; i < trip[2]; i++) {
        result[i] += trip[0];
      }
    }
    for (int i = 0; i < maxValue + 1; i++) {
      if (result[i] > capacity) {
        return false;
      }
    }
    return true;
  }
};
int main() {
//   // 示例二叉树
//   Solution solution;
//   vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
//   int capacity = 4;
//   bool result = solution.carPooling(trips, capacity);
//   std::cout << "result: " << result << std::endl;
    int a = -3/2;
    int b = 0;
}