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

// 自定义pair<int, int>的哈希函数
struct hash_pair {
  template <class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
    auto h1 = hash<T1>{}(p.first);
    auto h2 = hash<T2>{}(p.second);
    return h1 ^ (h2 << 1);
  }
};

struct entryClass {
  entryClass(int a, int b, int c) {
    shop = a;
    movie = b;
    price = c;
  }
  int shop;
  int movie;
  int price;
  bool operator<(const entryClass &other) const {
    if (price != other.price) {
      return price < other.price;
    }
    if (shop != other.shop) {
      return shop < other.shop;
    }
    return movie < other.movie;
  }
  bool operator>(const entryClass &other) const { return !operator<(other); }
  bool operator==(const entryClass &other) const {
    return shop == other.shop && movie == other.movie;
  }
};
struct entryClassHash {
  std::size_t operator()(const entryClass &entry) const {
    std::size_t h1 = std::hash<int>{}(entry.shop);
    std::size_t h2 = std::hash<int>{}(entry.movie);
    std::size_t h3 = std::hash<int>{}(entry.price);

    // 组合hash values
    return h1 ^ (h2 << 1) ^ (h3 << 2);
  }
};
class MovieRentingSystem {
public:
  MovieRentingSystem(int n, vector<vector<int>> &entries) {
    for (vector<int> entry : entries) {
      umap1[entry[0]].insert(entryClass(entry[0], entry[1], entry[2]));
      umap2[entry[1]].insert(entryClass(entry[0], entry[1], entry[2]));
      umap3[pair(entry[0], entry[1])] = entry[2];
    }
  }
  void rent(int shop, int movie) {
    pset.insert(entryClass(shop, movie, umap3[pair(shop, movie)]));
  }
  void drop(int shop, int movie) {
    pset.erase(entryClass(shop, movie, umap3[pair(shop, movie)]));
  }

  vector<int> search(int movie) {
    vector<int> res;
    for (auto it : umap2[movie]) {
      // 已经借出的情况
      if (pset.count(entryClass(it.shop, it.movie,
                                umap3[pair<int, int>(it.shop, it.movie)]))) {
        continue;
      } else { //还没有借出的情况
        res.push_back(it.shop);
      }
      if (5 == res.size()) {
        break;
      }
    }
    return res;
  }

  vector<vector<int>> report() {
    vector<vector<int>> res;
    for (auto it : pset) {
      res.push_back({it.shop, it.movie});
      if (5 == res.size()) {
        // 保存指定商店和电影的价格
        break;
      }
    }
    return res;
  }

private:
  // 每个商店有的电影set
  unordered_map<int, set<entryClass>> umap1;
  // 有指定电影的商店set
  unordered_map<int, set<entryClass>> umap2;
  // 保存指定商店和电影的价格
  unordered_map<pair<int, int>, int, hash_pair> umap3;
  // 已经借出的电影的pset
  set<entryClass> pset;
};
int main() {
  // 示例二叉树
  vector<vector<int>> entries = {{0, 1, 5}, {0, 2, 6}, {0, 3, 7},
                                 {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};
  MovieRentingSystem *obj = new MovieRentingSystem(3, entries);
  vector<int> param_1 = obj->search(1);
  obj->rent(0, 1);
  obj->rent(1, 2);
  obj->report();
  obj->drop(1, 2);
  obj->search(2);
  return 0;
}