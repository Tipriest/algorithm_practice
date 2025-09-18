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
struct task {
  task(int a, int b, int c) {
    user_id = a;
    task_id = b;
    priority = c;
  }
  int task_id;
  int user_id;
  int priority;
  bool operator<(const task &other) const {
    if (priority == other.priority) {
      return task_id < other.task_id;
    }
    return priority < other.priority;
  }
};

class MyHashSet {
public:
  MyHashSet() {}

  void add(int key) {}

  void remove(int key) {}

  bool contains(int key) {}
};
int main() {
  // 示例二叉树
  vector<vector<int>> tasks = {{9, 1, 31}, {6, 8, 31}};
  MyHashSet* obj = new MyHashSet();
  obj->add(1);
  obj->add(2);
  obj->add(3);
  obj->contains(4);
  obj->remove(5);

  return 0;
}