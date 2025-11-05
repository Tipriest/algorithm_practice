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

class Solution {
public:
  bool scoreBalance(string s) {
    unordered_set<int> uset;
    int result = 0;
    for (char ch : s) {
      result += ch - 'a' + 1;
      uset.insert(result);
    }
    if(0 != result%2){
      return false;
    }
    if(uset.count(result/2)){
      return true;
    }
    return false;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {-84, 28, 12};
  bool result = solution.scoreBalance("jijffihhgjigiggj");
  std::cout << "result: " << result << std::endl;
  return 0;
}