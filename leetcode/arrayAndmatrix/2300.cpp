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
class Solution {
public:
  int dichotomy(long long spell, long long success) {
    // 返回的是恰好能够满足spell*potion >=
    // success的id,如果都不能满足要求，返回-1
    int n = potions.size();
    // 如果没有满足要求的药
    if (spell * potions[n - 1] < success) {
      return -1;
    }
    if (spell * potions[0] >= success) {
      return 0;
    }
    //  到这里的说明肯定第一个不符合，最后一个符合了，也就是说至少是等于2的
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (0 == mid && spell * potions[mid] >= success) {
        return 0;
      } else if (spell * potions[mid] >= success &&
                 spell * potions[mid - 1] < success) {
        return mid;
      } else if (spell * potions[mid] >= success &&
                 spell * potions[mid - 1] >= success) {
        r = mid - 1;
      } else if (spell * potions[mid] < success) {
        l = mid + 1;
      }
    }
    std::runtime_error("wrong case");
    return 0;
  }
  vector<int> successfulPairs(vector<int> &spells, vector<int> &_potions,
                              long long success) {
    potions = _potions;
    sort(potions.begin(), potions.end());
    vector<int> result;
    for (int spell : spells) {
      int id = dichotomy(spell, success);
      if(-1 == id){
        result.push_back(0);
      }else{
         result.push_back(potions.size() - id);
      }
    }
    return result;
  }
  vector<int> potions;
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> spells = {3, 1, 2}, potions = {8, 5, 8};
  int success = 16;

  vector<int> result = solution.successfulPairs(spells, potions, success);
  //    std::cout << "result: " << result << std::endl;
}