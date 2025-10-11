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

class ExamTracker {
public:
  ExamTracker() {
    vt.clear();
    vs.clear();
  }

  void record(int time, int score) {
    vt.push_back(time);
    vs.push_back(score);
    if (0 == prefix_sum.size()) {
      prefix_sum.push_back(score);
    } else {
      prefix_sum.push_back(prefix_sum[prefix_sum.size() - 1] + score);
    }
  }

  long long totalScore(int startTime, int endTime) {
    int l = dichotomyfors(startTime);
    int r = dichotomyforr(endTime);
    if (-1 == l || -1 == r) {
      return 0;
    }
    long long result = 0;
    if(0 == l){
      return prefix_sum[r];
    }else{
      return prefix_sum[r] - prefix_sum[l-1];
    }
    return 0;
  }
  int dichotomyfors(int startTime) {
    if (vt[0] >= startTime) {
      return 0;
    }
    int l = 0, r = vt.size();
    while (l <= r) {
      int mid = (l + r) / 2;
      if (vt[mid] < startTime) {
        l = mid + 1;
      } else {
        if (vt[mid - 1] >= startTime) {
          r = mid - 1;
        } else {
          return mid;
        }
      }
    }
    return -1;
  }
  int dichotomyforr(int endTime) {
    int n = vt.size();
    if (vt[n - 1] <= endTime) {
      return n - 1;
    }
    int l = 0, r = vt.size();
    while (l <= r) {
      int mid = (l + r) / 2;
      if (vt[mid] > endTime) {
        r = mid - 1;
      } else {
        if (vt[mid + 1] <= endTime) {
          l = mid + 1;
        } else {
          return mid;
        }
      }
    }
    return -1;
  }
  vector<int> vt, vs;
  vector<long long> prefix_sum;
};
int main() {
  // 示例二叉树
  ExamTracker *obj = new ExamTracker();
  obj->record(2, 2);
  long long param_2 = obj->totalScore(1, 1);
  param_2 = obj->totalScore(1, 2);
  param_2 = obj->totalScore(2, 2);

  return 0;
}