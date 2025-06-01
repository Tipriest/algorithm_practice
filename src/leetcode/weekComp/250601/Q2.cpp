#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k) {
    int m1 = grid.size(), n1 = grid[0].size();
    int m2 = m1 - k + 1, n2 = n1 - k + 1;
    vector<vector<int>> result(m2, vector<int>(n2, 0));
    if (k == 1) {
      return result;
    }
    for(int i = 0; i < m2; i++){
        for(int j = 0; j < n2; j++){
            
        }
    }
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> nums = {{1, 8}, {3, -2}};
  vector<vector<int>> result = solution.minAbsDiff(nums, 2);
  //    std::cout << "result: " << result << std::endl;
}