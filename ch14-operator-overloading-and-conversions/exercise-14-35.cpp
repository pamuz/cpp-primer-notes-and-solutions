// Exercise 14.35, page 709
//
// Define a function-object class to perform an if-then-else
// operation: The call operator for this class should take three
// parameters. It should test its first parameter and if that test
// succeeds, it should return its second parameter; otherwise, it
// should return its third parameter.

#include <iostream>

struct IfThenElse {
  int operator()(int first, int second, int third) {
    return first ? second : third;
  }
};

int main(int argc, char *argv[argc])
{

  IfThenElse ite;

  std::cout << "ite(1, 2, 3): "  << ite(1, 2, 3) << std::endl;
  std::cout << "ite(0, 9, 10): "  << ite(0, 9, 10) << std::endl;

  return 0;
}
