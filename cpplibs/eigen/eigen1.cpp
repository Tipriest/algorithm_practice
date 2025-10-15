// 矩阵基本构造
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
  template <typename T> void print_Matrix(const T &v) {
    cout << "Matrix: " << endl << v << endl;
  }
  template <typename T> void reset_Matrix(T &v) {
    v << 1, 2, 3, //
        4, 5, 6,  //
        7, 8, 9;  //
  }
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
    //   常值矩阵
    std::cout << "常值矩阵" << endl;
    M.setConstant(5.0);
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
    //   随机矩阵+赋值构造
    std::cout << "随机矩阵+赋值构造" << endl;
    M = Eigen::Matrix3d::Random();
    print_Matrix(M);
    std::cout << "矩阵重置" << endl;
    reset_Matrix(M);
    //   单位矩阵+赋值构造
    std::cout << "随机矩阵+赋值构造" << endl;
    M = Eigen::Matrix3d::Identity();
    print_Matrix(M);
    std::cout << "矩阵重置" << endl;
    reset_Matrix(M);
  }

  Eigen::Matrix<double, 3, 3> M;
  Eigen::Matrix<double, 3, 1> v;
};

int main() {
  Eigen_learn e;
  // 列表初始化
  e.M << 1, 2, 3, //
      4, 5, 6,    //
      7, 8, 9;    //
  e.v << 1, 2, 3;
  e.print_Matrix(e.M);
  e.print_Matrix(e.v);
  e.basic_operations();
}