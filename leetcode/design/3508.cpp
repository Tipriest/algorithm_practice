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

void printPackQueue(queue<Pack> pque) {
  while (!pque.empty()) {
    cout << "timestamp: " << pque.front().timestamp
         << "source: " << pque.front().source
         << "destination: " << pque.front().destination << endl;
    pque.pop();
  }
  cout << endl;
}
struct Pack {
  Pack(int a, int b, int c) { source = a, destination = b, timestamp = c; }
  int timestamp;
  int source;
  int destination;
  bool operator==(const Pack &other) const {
    return timestamp == other.timestamp && source == other.source &&
           destination == other.destination;
  }
};

struct Packhash {
  std::size_t operator()(const Pack &pack) const {
    std::size_t h1 = std::hash<int>{}(pack.source);
    std::size_t h2 = std::hash<int>{}(pack.destination);
    std::size_t h3 = std::hash<int>{}(pack.timestamp);

    // 组合hash values
    return h1 ^ (h2 << 1) ^ (h3 << 2);
  }
};

class Router {
public:
  Router(int memoryLimit) { this->memory_limit = memoryLimit; }

  bool addPacket(int source, int destination, int timestamp) {
    // 用uset判断是不是重合的
    Pack p = Pack(source, destination, timestamp);
    if (uset.find(p) != uset.end()) {
      return false;
    }

    // 拿一个队列向里面填东西
    // 队列里现在不够memory_limit，可以直接填
    if (uset.size() < memory_limit) {
      que.push(p);
      uset.insert(p);
      umap[p.destination].push_back(p);
      return true;
    }
    // 够memory_limit，需要先推一个出来
    while (uset.find(que.front()) == uset.end()) {
      que.pop();
    }
    uset.erase(que.front());
    que.pop();
    que.push(p);
    uset.insert(p);
    umap[p.destination].push_back(p);
    return true;
  }

  vector<int> forwardPacket() {
    if (0 == que.size()) {
      return {};
    }
    // 够memory_limit，需要先推一个出来
    while (uset.find(que.front()) == uset.end()) {
      que.pop();
    }
    Pack p = que.front();
    que.pop();
    uset.erase(p);
    umap[p.destination].push_back(p);
    return {p.source, p.destination, p.timestamp};
  }

  int getCount(int destination, int startTime, int endTime) {
    int result = 0;
    for (const Pack &p : umap[destination]) {
      if (uset.find(p) == uset.end()) {
        continue;
      }
      if (p.timestamp >= startTime && p.timestamp <= endTime) {
        result++;
      }
    }
    return result;
  }

  int memory_limit = 0;
  queue<Pack> que;
  unordered_set<Pack, Packhash> uset;
  unordered_map<int, vector<Pack>> umap;
};
int main() {
  // 示例二叉树
  Router *obj = new Router(2);
  obj->addPacket(7, 4, 90);
  printPackQueue(obj->que);
  obj->addPacket(2, 5, 90);
  printPackQueue(obj->que);
  obj->addPacket(1, 4, 90);
  printPackQueue(obj->que);
  obj->addPacket(3, 5, 95);
  printPackQueue(obj->que);
  obj->addPacket(4, 5, 105);
  printPackQueue(obj->que);
  vector<int> res = obj->forwardPacket();
  printPackQueue(obj->que);
  obj->addPacket(5, 2, 110);
  printPackQueue(obj->que);
  obj->getCount(5, 100, 110);
  printPackQueue(obj->que);
  return 0;
}