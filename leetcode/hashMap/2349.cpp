#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>
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
class NumberContainers {
public:
  NumberContainers() {}

  void change(int index, int number) {
    if (!umap2.count(index)) {
      umap2[index] = number;
      umap1[number].insert(index);
    } else {
      // 说明这个index之前有东西
      int last_value = umap2[index];
      umap1[last_value].erase(index);
      umap2[index] = number;
      umap1[number].insert(index);
    }
  }

  int find(int number) {
    if (umap1[number].empty()) {
      return -1;
    } else {
      return *umap1[number].begin();
    }
  }

private:
  unordered_map<int, set<int>> umap1;
  unordered_map<int, int> umap2;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
int main() {
  // 示例二叉树
  NumberContainers nc;
  nc.change(1, 1);
  nc.find(1);
  return 0;
}