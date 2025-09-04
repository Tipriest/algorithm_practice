#include <iostream>
#include <typeinfo>

class Base {
public:
  virtual ~Base() {}
};

class Derived : public Base {};

int main() {
  Base *b = new Derived();

  // 使用typeid获取类型信息
  const std::type_info &baseType = typeid(Base);
  const std::type_info &derivedType = typeid(*b);

  // 输出类型名称
  std::cout << "Base type: " << baseType.name() << std::endl;
  std::cout << "Derived type: " << derivedType.name() << std::endl;

  // 比较类型信息
  if (baseType == derivedType) {
    std::cout << "b is of type Base" << std::endl;
  } else {
    std::cout << "b is of type Derived" << std::endl;
  }

  delete b;
  return 0;
}