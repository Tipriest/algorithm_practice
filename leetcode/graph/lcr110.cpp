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
  void bfs(vector<vector<int>> &graph, int cur, int n) {
    // 队列存储 pair<当前节点, 当前路径>
    queue<pair<int, vector<int>>> qu;
    qu.push({cur, {cur}});
    while (!qu.empty()) {
      auto [node, curPath] = qu.front();
      qu.pop();
      if (node == n) {
        paths.push_back(curPath);
        continue;
      }
      for (int nextp : graph[node]) {
        vector<int> nextPath = curPath;
        nextPath.push_back(nextp);
        qu.push({nextp, nextPath});
      }
    }
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    int n = graph.size();
    // dfs(graph, 0, n - 1);
    bfs(graph, 0, n - 1);
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