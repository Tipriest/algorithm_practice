// 基本元素读取和分块操作
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