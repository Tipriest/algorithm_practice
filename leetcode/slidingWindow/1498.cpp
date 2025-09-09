#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  const int mod = 1e9 + 7;
  // 快速幂算法，计算 (base^exp) % mod
  long fastPow(long base, int exp, int mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
      if (exp & 1) {
        result = (result * base) % mod;
      }
      base = (base * base) % mod;
      exp >>= 1;
    }
    return result;
  }

  int numSubseq(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int l = 0, r = n-1;
    int result = 0;
    while(l <= r){
        if(nums[l] + nums[r] <= target){
          result += fastPow(2, r - l, mod);
          result = result % mod;
          l++;
        }else{
            r--;
        }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {2, 3, 3, 4, 6, 7};
  int result = solution.numSubseq(nums, 12);
  std::cout << "result: " << result << std::endl;
}