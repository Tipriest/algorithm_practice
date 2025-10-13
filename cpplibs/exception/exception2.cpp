#include <exception>
#include <iostream>

class MyException : public std::exception {
public:
  const char *what() const noexcept override {
    return "My custom exception occurred";
  }
};

int main() {
  try {
    throw MyException();
  } catch (const MyException &e) {
    std::cout << "Caught MyException: " << e.what() << std::endl;
  }

  return 0;
}