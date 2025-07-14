#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
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
class MyStack {
public:
  queue<int> qu1, qu2;
  MyStack() {}

  void push(int x) { qu1.push(x); }

  int pop() {
    while (qu1.size() > 1) {
      qu2.push(qu1.front());
      qu1.pop();
    }
    int result = qu1.front();
    qu1.pop();
    while (!qu2.empty()) {
      qu1.push(qu2.front());
      qu2.pop();
    }
    return result;
  }

  int top() {
    while (qu1.size() > 1) {
      qu2.push(qu1.front());
      qu1.pop();
    }
    int result = qu1.front();
    qu2.push(result);
    qu1.pop();
    while (!qu2.empty()) {
      qu1.push(qu2.front());
      qu2.pop();
    }
    return result;
  }

  bool empty() {
    return qu1.empty();
  }
};

int main() {
  // 示例二叉树
  MyStack *obj = new MyStack();
  obj->push(1);
  obj->push(2);
  int param_2 = obj->top();
  int param_3 = obj->pop();
  bool param_4 = obj->empty();
}