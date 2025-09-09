#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> preprocess(vector<vector<int>> &edges) {
    for (vector<int> edge : edges) {
      edge[0] -= 1;
      edge[1] -= 1;
    }
  }
  int assignEdgeWeights(vector<vector<int>> &edges) {
    preprocess(edges);
    int n = edges.size();
    vector<vector<int>> tree;
    unordered_set<int> uset;
    uset.insert(0);
    vector<int> temp;
    vector<int> temp2;
    temp.push_back(0);
    tree.push_back(temp);
    for (int i : temp) {
      temp2.clear();
      for (int j = 0; j < n; j++) {
        if (uset.find(j) == uset.end() && edges[i][j] == 1) {
          temp2.push_back(j);
          uset.insert(j);
        }
      }
      temp = temp2;
      tree.push_back(temp);
    }
    int depth = tree.size();
    return depth;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
  int result = solution.assignEdgeWeights(edges);
  std::cout << "result: " << result << std::endl;
}