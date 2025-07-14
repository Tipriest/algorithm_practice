#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
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

class MyQueue {
public:
  stack<int> ins, outs;
  MyQueue() {}

  void push(int x) { ins.push(x); }

  int pop() {
    while (!ins.empty()) {
      outs.push(ins.top());
      ins.pop();
    }
    int result = outs.top();
    outs.pop();
    while (!outs.empty()) {
      ins.push(outs.top());
      outs.pop();
    }
    return result;
  }

  int peek() {
    while (!ins.empty()) {
      outs.push(ins.top());
      ins.pop();
    }
    int result = outs.top();
    while (!outs.empty()) {
      ins.push(outs.top());
      outs.pop();
    }
    return result;
  }

  bool empty() { return ins.empty(); }
};

int main() {
   // 示例二叉树
   MyQueue *obj = new MyQueue();
   obj->push(1);
   obj->push(2);
   int param_2 = obj->peek();
   int param_3 = obj->pop();
   bool param_4 = obj->empty();
}