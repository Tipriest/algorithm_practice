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

class TaskManager {
public:
  TaskManager(vector<vector<int>> &tasks) {
    for (vector<int> _task : tasks) {
      umap1[_task[1]] = pair<int, int>(_task[0], _task[2]);
      task cur(_task[0], _task[1], _task[2]);
      pque.push(cur);
    }
  }

  void add(int userId, int taskId, int priority) {
    umap1[taskId] = pair<int, int>(userId, priority);
    pque.push(task(userId, taskId, priority));
  }

  void edit(int taskId, int newPriority) {
    int userId = umap1[taskId].first;
    umap1[taskId] = pair<int, int>(userId, newPriority);
    pque.push(task(userId, taskId, newPriority));
  }

  void rmv(int taskId) { umap1.erase(taskId); }

  int execTop() {
    if (0 == pque.size()) {
      return -1;
    }
    task sel = pque.top();
    pque.pop();
    while (!umap1.count(sel.task_id) ||
           sel.priority != umap1[sel.task_id].second ||
           sel.user_id != umap1[sel.task_id].first) {
      if (0 == pque.size()) {
        return -1;
      }
      sel = pque.top();
      pque.pop();
    }
    umap1.erase(sel.task_id);
    return sel.user_id;
  }

private:
  unordered_map<int, pair<int, int>> umap1;
  priority_queue<task> pque;
};
int main() {
  // 示例二叉树
  vector<vector<int>> tasks = {{9, 1, 31}, {6, 8, 31}};
  TaskManager *obj = new TaskManager(tasks);
  obj->execTop();
  obj->rmv(1);
  obj->execTop();
  obj->add(0, 11, 0);
  obj->add(1, 9, 2);
  obj->rmv(11);
  obj->execTop();
  obj->add(3, 7, 2);
  obj->add(5, 3, 2);
  obj->execTop();
  obj->rmv(3);
  obj->execTop();
  obj->execTop();
  return 0;
}