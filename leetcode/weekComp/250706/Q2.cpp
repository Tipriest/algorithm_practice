#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
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
  class UnionFindBasic {
  private:
    std::vector<int> parent;
    int count;

  public:
    UnionFindBasic(int n) {
      count = n;
      parent.resize(n);
      std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
      if (parent[x] != x) {
        parent[x] = find(parent[x]); // 路径压缩
      }
      return parent[x];
    }

    void unite(int x, int y) {
      int rootX = find(x);
      int rootY = find(y);
      if (rootX != rootY) {
        parent[rootX] = rootY; // 简单合并
        count--;
      }
    }

    int getCount() const { return count; }
  };
  vector<int> processQueries(int c, vector<vector<int>> &connections,
                             vector<vector<int>> &queries) {
    int n = connections.size();
    UnionFindBasic uf(c);
    for (vector<int> connection : connections) {
      uf.unite(connection[0], connection[1]);
    }
    vector<set<int>> vp(uf.getCount());
    unordered_set<int> meetid_uset;
    unordered_map<int, int> meetid_map;
    for (int i = 0; i < n; i++) {
      if (meetid_uset.find(uf.find(i)) == meetid_uset.end()) {
        meetid_uset.insert(uf.find(i));
        meetid_map[uf.find(i)] = meetid_uset.size()-1;
      }
      vp[meetid_map[uf.find(i)]].insert(i);
    }
    vector<int> result;
    int m = queries.size();
    for (int i = 0; i < m; i++) {
      if (queries[i][0] == 2) {
        vp[meetid_map[uf.find(queries[i][1])]].erase(queries[i][1]);
      } else if (queries[i][0] == 1) {
        if (vp[meetid_map[uf.find(queries[i][1])]].find(
                uf.find(queries[i][1])) !=
            vp[meetid_map[uf.find(queries[i][1])]].end()) {
          result.push_back(queries[i][1]);
        } else {
          result.push_back(*vp[meetid_map[uf.find(queries[i][1])]].begin());
        }
      }
    }
    return result;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> connections = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  vector<vector<int>> queries = {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}};
  vector<int> result = solution.processQueries(5, connections, queries);
  //   std::cout << "result: " << result << std::endl;
}