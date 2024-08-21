#include <iostream>
#include <Eigen/Dense>

int main() {
  Eigen::Matrix3f matrix;
  matrix << 1, 2, 3,
           4, 5, 6,
           7, 8, 9;

  std::cout << matrix << std::endl;
  return 0;
}
