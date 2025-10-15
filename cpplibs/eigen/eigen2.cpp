// 可变维度矩阵基本构造
#include <algorithm>
#include <eigen3/Eigen/Dense>
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
using Mat3 = typename Eigen::Matrix<double, 3, 3>;
using Vec3 = typename Eigen::Matrix<double, 3, 1>;

class Eigen_learn {
public:
  Eigen_learn(int rowNum, int colNum) {
    this->rowNum = rowNum;
    this->colNum = colNum;
    M.resize(rowNum, colNum);
    v.resize(rowNum);
  }
  template <typename T> void print_Matrix(const T &v) {
    cout << "Matrix: " << endl << v << endl;
  }
  template <typename T> void reset_Matrix(T &v) { v.setZero(); }
  void basic_operations() {
    //   单位矩阵
    std::cout << "单位矩阵" << endl;
    M.setIdentity();
    print_Matrix(M);
    std::cout << "矩阵重置" << endl;
    reset_Matrix(M);
    //   零矩阵
    std::cout << "零矩阵" << endl;
    M.setZero();
    print_Matrix(M);
    std::cout << "矩阵重置" << endl;
    reset_Matrix(M);
    //   对角矩阵
    std::cout << "对角矩阵" << endl;
    M = Vec3(1, 2, 3).asDiagonal();
    print_Matrix(M);
    std::cout << "矩阵重置" << endl;
    reset_Matrix(M);
    //   全1向量
    std::cout << "全1向量" << endl;
    M.setOnes();
    print_Matrix(M);
    std::cout << "矩阵重置" << endl;
    reset_Matrix(M);
  }

  Eigen::MatrixXd M;
  Eigen::VectorXd v;
  int rowNum = 0;
  int colNum = 0;
};

int main() {
  Eigen_learn e(5, 3);
  // 示例二叉树
  e.M << 1, 2, 3, 4, 5,   //这个地方的赋值必须是满值的赋值
      6, 7, 8, 9, 10,     //
      11, 12, 13, 14, 15; //
  e.v << 1, 2, 3, 4, 5;
  e.print_Matrix(e.M);
  e.print_Matrix(e.v);
  e.basic_operations();
}