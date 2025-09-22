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

struct PackHash {
  std::size_t operator()(const Pack &pack) const {
    std::size_t h1 = std::hash<int>{}(pack.source);
    std::size_t h2 = std::hash<int>{}(pack.destination);
    std::size_t h3 = std::hash<int>{}(pack.timestamp);

    // 组合hash values
    return h1 ^ (h2 << 1) ^ (h3 << 2);
  }
};
struct PackHash2 {
  template <typename T> static void hash_combine(size_t &seed, const T &v) {
    // 参考boost::hash_combine
    seed ^= hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }
  std::size_t operator()(const Pack &pack) const {
    size_t seed = 0;
    hash_combine(seed, pack.timestamp);
    hash_combine(seed, pack.source);
    hash_combine(seed, pack.destination);
    // 组合hash values
    return seed;
  }
};
// void printPackQueue(queue<Pack> pque) {
//   while (!pque.empty()) {
//     cout << "timestamp: " << pque.front().timestamp
//          << "source: " << pque.front().source
//          << "destination: " << pque.front().destination << endl;
//     pque.pop();
//   }
//   cout << endl;
// }
class Router {
public:
  Router(int memoryLimit) { this->memory_limit = memoryLimit; }

  bool addPacket(int source, int destination, int timestamp) {
    // 用uset判断是不是重合的
    Pack p = Pack(source, destination, timestamp);
    if (!uset.insert(p).second) {
      return false;
    }

    // 拿一个队列向里面填东西
    // 队列的东西太多了
    // 吐一个出来
    if (memory_limit == que.size()) {
      forwardPacket();
    }
    que.push(p);
    umap[p.destination].push_back(p);
    return true;
  }

  vector<int> forwardPacket() {
    if (que.empty()) {
      return {};
    }
    Pack p = que.front();
    que.pop();
    uset.erase(p);
    umap[p.destination].pop_front();
    return {p.source, p.destination, p.timestamp};
  }
  int dichotomyL(const deque<Pack> &packs, int startTime, int endTime) {
    int l = 0;
    int r = packs.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (packs[mid].timestamp < startTime) {
        l = mid + 1;
      } else if (packs[mid].timestamp >= startTime) {
        if (0 == mid) {
          return 0;
        } else {
          if (packs[mid - 1].timestamp < startTime) {
            return mid;
          } else {
            r = mid - 1;
          }
        }
      }
    }
    // didn't find, return -1
    return -1;
  }
  int dichotomyR(const deque<Pack> &packs, int startTime, int endTime) {
    int l = 0;
    int r = packs.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (packs[mid].timestamp > endTime) {
        r = mid - 1;
      } else if (packs[mid].timestamp <= endTime) {
        if (packs.size() - 1 == mid) {
          return mid;
        } else {
          if (packs[mid + 1].timestamp > endTime) {
            return mid;
          } else {
            l = mid + 1;
          }
        }
      }
    }
    // didn't find, return -1
    return -1;
  }
  int getCount(int destination, int startTime, int endTime) {
    int result = 0;
    int l = dichotomyL(umap[destination], startTime, endTime);
    int r = dichotomyR(umap[destination], startTime, endTime);
    if (-1 == l || -1 == r) {
      return 0;
    }
    return r - l + 1;
    
  }

  int memory_limit = 0;
  queue<Pack> que;
  unordered_set<Pack, PackHash2> uset;
  unordered_map<int, deque<Pack>> umap;
  
};
int main() {
  // 示例二叉树
  Router *obj = new Router(4);
  obj->addPacket(4, 2, 1);
  // printPackQueue(obj->que);
  obj->addPacket(3, 2, 1);
  // printPackQueue(obj->que);
  obj->getCount(2, 1, 1);
  // printPackQueue(obj->que);
  return 0;
}