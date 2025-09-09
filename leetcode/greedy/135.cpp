#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> result(n, 1);
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) {
        result[i] = result[i - 1] + 1;
      }
    }
    for (int i = n - 1; i >= 1; i--) {
      if (ratings[i - 1] > ratings[i] && result[i - 1] <= result[i]) {
        result[i - 1] = result[i] + 1;
      }
    }
    return accumulate(result.begin(), result.end(), 0);
  }
};

int main() {
   // 示例二叉树
   Solution solution;
   vector<int> ratings = {1, 0, 2};
   int result = solution.candy(ratings);
   std::cout << "result: " << result << std::endl;
}