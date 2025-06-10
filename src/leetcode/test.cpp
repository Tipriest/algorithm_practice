#include <Eigen/Dense>
#include <iostream>

int main() {
  std::cout << "Eigen version: " << EIGEN_WORLD_VERSION << "."
            << EIGEN_MAJOR_VERSION << "." << EIGEN_MINOR_VERSION << std::endl;
  return 0;
}