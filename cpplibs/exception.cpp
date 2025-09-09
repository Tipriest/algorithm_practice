#include <exception>
#include <iostream>

void mightGoWrong() {
  bool errorOccurred = true; // 假设发生了一个错误
  if (errorOccurred) {
    throw std::exception();
  }
}

int main() {
  try {
    mightGoWrong();
  } catch (const std::exception &e) {
    std::cout << "Caught an exception: " << e.what() << std::endl;
  }

  return 0;
}