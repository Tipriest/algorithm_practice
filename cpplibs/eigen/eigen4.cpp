// 基本运算
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
using Mat6 = typename Eigen::Matrix<double, 6, 6>;
using Vec6 = typename Eigen::Matrix<double, 6, 1>;

class Eigen_learn {
public:
  Eigen_learn() {
    m6.setZero();
    v6.setZero();
  }
  template <typename T> void print_Matrix(const T &v) {
    cout << "Matrix: " << endl << v << endl;
  }
  template <typename T> void reset_Matrix(T &v) {
    v << 1, 2, 3, //
        4, 5, 6,  //
        7, 8, 9;  //
  }
  void print_m6() { cout << "m6: " << endl << m6 << endl; }
  void print_v6() { cout << "v6: " << endl << v6 << endl; }

  void basic_operations() {
    m6.block(0, 3, 3, 3).setIdentity();
    print_m6();
    m6.block(3, 0, 3, 3) = Vec3(2, 2, 2).asDiagonal();
    print_m6();
    v6.segment(1, 3) = Vec3(10, 20, 30);
    print_v6();
    cout << "数乘: 2 * v6=" << endl;
    print_Matrix(2 * v6);
    cout << "矩阵乘: m6 * v6" << endl;
    print_Matrix(m6 * v6);
    cout << "向量加: v6 + v6" << endl;
    print_Matrix(v6 + v6);
    cout << "矩阵转置: M.tran()" << endl;
    print_Matrix(m6.transpose());
    print_m6();
    cout << "矩阵求逆: m6.inverse()" << endl;
    print_Matrix(m6.inverse());
    // 需要强调的是，对于机器人学中常用的矩阵，如旋转矩阵和齐次变换矩阵，它们的逆矩阵都有简单的理论解，这种情况是不必使用inverse()函数的
  }

  Eigen::Matrix<double, 3, 3> M;
  Eigen::Matrix<double, 3, 1> v;
  Mat6 m6;
  Vec6 v6;
};

int main() {
  Eigen_learn e;
  e.basic_operations();
}