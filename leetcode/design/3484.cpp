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

class Spreadsheet {
public:
  Spreadsheet(int rows) {
    sheet = new vector<vector<int>>(rows, vector<int>(26, 0));
  }

  void setCell(string cell, int value) {
    string row_str = cell.substr(1, cell.size() - 1);
    int row = stoi(row_str) - 1;
    int col = cell[0] - 'A';
    (*sheet)[row][col] = value;
  }
  int getCell(string cell) {
    // 如果直接就是值
    if (cell[0] < 'A' || cell[0] > 'Z') {
      return stoi(cell);
    }
    string row_str = cell.substr(1, cell.size() - 1);
    int row = stoi(row_str) - 1;
    int col = cell[0] - 'A';
    return (*sheet)[row][col];
  }
  void resetCell(string cell) { setCell(cell, 0); }

  int getValue(string formula) {
    int i = 0, n = formula.size();
    for(int i = 0; i < n; i++){
      if('+' == formula[i]){
        return getCell(formula.substr(1, i-1)) + getCell(formula.substr(i+1, n-i-1));
      }
    }
    return 1;
  }

private:
  vector<vector<int>> *sheet;
};
int main() {
  // 示例二叉树
  Spreadsheet *obj = new Spreadsheet(3);
  obj->getValue("=5+7");
  obj->setCell("A1", 10);
  obj->getValue("=A1+6");
  obj->resetCell("A1");
  return 0;
}