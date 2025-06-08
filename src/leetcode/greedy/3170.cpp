#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
#include <limits.h>
#include <stack>
using namespace std;
class Solution {
public:
  string clearStars(string s) {
    // 维护两个stack,一个用于找现在的
    stack<char> st1, st2;
    unordered_map<char, int> umap;
    umap[s[0]]++;
    st1.push(s[0]);
    int n = s.size();
    for (int i = 1; i < n; i++) {
      int minCharacter = 25;
      for (int j = 0; j < 26; j++) {
        if (umap['a' + j] > 0) {
          minCharacter = j;
          break;
        }
      }
      if (s[i] == '*') {
        umap['a' + minCharacter]--;
        while (!st1.empty()) {
          char temp = st1.top();
          st1.pop();
          if (temp == 'a' + minCharacter) { //已经找到了当前最小的character
            //把st2的东西还回去
            while (!st2.empty()) {
              st1.push(st2.top());
              st2.pop();
            }
            break;
            // break出来
          } else { //现在不是最小的character
            //把这个东西放到st2中
            st2.push(temp);
          }
        }
      }else{
        umap[s[i]]++;
        st1.push(s[i]);
      }
    }
    string result;
    while (!st1.empty()) {
      result.push_back(st1.top());
      st1.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
   // 示例二叉树
   Solution solution;
   string a = "aaba*";
   string result = solution.clearStars(a);
   std::cout << "result: " << result << std::endl;
}