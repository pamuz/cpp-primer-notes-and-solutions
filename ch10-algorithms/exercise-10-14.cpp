// Exercise 10.14, page 494
//
// Write a lambda that takes two ints and returns their sum.

#include <iostream>

int main(int argc, char *argv[argc])
{
  auto sum = [] (int n1, int n2) { return n1 + n2; };
  std::cout << sum(5, 3) << std::endl;
  
  return 0;
}
