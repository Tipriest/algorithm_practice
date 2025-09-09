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
  vector<vector<int>> paths;
  vector<int> path;
  void dfs(vector<vector<int>> &graph, int cur, int n) {
    if (n == cur) {
      path.push_back(cur);
      paths.push_back(path);
      return;
    }
    path.push_back(cur);
    for (int nextp : graph[cur]) {
      dfs(graph, nextp, n);
      path.pop_back();
    }
    return;
  }
  void bfs(vector<vector<int>> &graph, int cur, int n) {}
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    int n = graph.size();
    dfs(graph, 0, n-1);
    return paths;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
  vector<vector<int>> result = solution.allPathsSourceTarget(graph);
  // std::cout << "result: " << result << std::endl;
  return 0;
}