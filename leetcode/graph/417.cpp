#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// Custom hash function for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};
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
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> pacific_area;
    vector<vector<int>> atlantic_area;
    for (int i = 0; i < m; i++) {
      pacific_area.push_back({i, 0, heights[i][0]});
      atlantic_area.push_back({i, n - 1, heights[i][n - 1]});
    }
    unordered_set<pair<int, int>, pair_hash> result;
      pacific_area.push_back({0, j, heights[0][j]});
    }
    for (int j = 0; j < n - 1; j++) {
      atlantic_area.push_back({m - 1, j, heights[m - 1][j]});
    }
    sort(pacific_area.begin(), pacific_area.end(),
         [](vector<int> a, vector<int> b) { return a[2] < b[2]; });
    sort(atlantic_area.begin(), atlantic_area.end(),
         [](vector<int> a, vector<int> b) { return a[2] < b[2]; });
    unordered_set<pair<int, int>> result;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int cur_height = heights[i][j];
        bool have_path[2] = {false, false};
        for (int k = 0;
             k < pacific_area.size() && cur_height >= pacific_area[k][2]; k++) {
          if (dfs(i, j, pacific_area[k][0], pacific_area[k][1]) == true) {
            have_path[0] = true;
            break;
          }
        }
        if (have_path[0] == false) {
          continue;
        }
        for (int k = 0;
             k < atlantic_area.size() && cur_height >= atlantic_area[k][2];
             k++) {
          if (dfs(i, j, atlantic_area[k][0], atlantic_area[k][1]) == true) {
            have_path[1] = true;
            break;
          }
        }
        if (have_path[1] == false) {
          continue;
        }
      }
    }
    return {{}};
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> grid = {{1, 2, 2, 3, 5},
                              {3, 2, 3, 4, 4},
                              {2, 4, 5, 3, 1},
                              {6, 7, 1, 4, 5},
                              {5, 1, 1, 2, 4}};
  vector<vector<int>> result = solution.pacificAtlantic(grid);
  std::cout << "result size: " << result.size() << std::endl;
}
