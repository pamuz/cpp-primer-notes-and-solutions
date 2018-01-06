// Exercise 10.15, page 494
//
// Write a lambda that captures an int from its enclosing function and
// takes an int parameter. The lambda should return the sum of the
// captured int and the int parameter.

#include <iostream>

int increment(int amount) {
  int num = 42;
  auto inc = [amount] (int n) { return n + amount; };
  return inc(num);
}

int main(int argc, char *argv[argc])
{
  std::cout << "increment() = " << increment(2) << std::endl;
  
  return 0;
}
