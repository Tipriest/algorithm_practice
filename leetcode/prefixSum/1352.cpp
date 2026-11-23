#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
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
class ProductOfNumbers {
public:
  vector<int> numArray, prefixDot, hasZeroNum;
  ProductOfNumbers() {}

  void add(int num) {
    numArray.push_back(num);
    if (0 == num) {
      if (0 == hasZeroNum.size()) {
        hasZeroNum.push_back(1);
      } else {
        hasZeroNum.push_back(hasZeroNum[hasZeroNum.size() - 1] + 1);
      }
    } else {
      if (0 == hasZeroNum.size()) {
        hasZeroNum.push_back(0);
      } else {
        hasZeroNum.push_back(hasZeroNum[hasZeroNum.size() - 1]);
      }
    }
    if (0 == prefixDot.size()) {
      prefixDot.push_back(num);
    } else {
      if (0 == prefixDot[prefixDot.size() - 1]) {
        prefixDot.push_back(num);
      } else {
        prefixDot.push_back(num * prefixDot[prefixDot.size() - 1]);
      }
    }
  }

  int getProduct(int k) {
    if (0 == numArray[prefixDot.size() - k] ||
        0 != hasZeroNum[prefixDot.size() - 1] -
                 hasZeroNum[prefixDot.size() - k]) {
      return 0;
    }
    return prefixDot[prefixDot.size() - 1] / prefixDot[prefixDot.size() - k] *
           numArray[prefixDot.size() - k];
  }
};
int main() {
  // 示例二叉树
  ProductOfNumbers solution;
  solution.add(1);
  solution.getProduct(1);
  solution.getProduct(1);
  solution.getProduct(1);
  solution.add(7);
  solution.add(6);
  solution.add(7);
  //   std::cout << "result: " << result << std::endl;
}