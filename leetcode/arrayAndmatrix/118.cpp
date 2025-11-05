#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    result.push_back({1});
    for (int i = 1; i < numRows; i++) { //第i层，应该有i-1个非1的中间数
      vector<int> temp;
      temp.push_back(1);
      for (int j = 0; j < i - 1; j++) {
        temp.push_back(result[i - 1][j] + result[i - 1][j+1]);
      }
      temp.push_back(1);
      result.push_back(temp);
    }
    return result;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> result = solution.generate(5);
  //    std::cout << "result: " << result << std::endl;
}