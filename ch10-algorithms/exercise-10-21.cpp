// Exercise 10.21, page 501
//
// Write a lambda that captures a local int variable and decrements
// that variable until it reaches 0. Once the variable is 0 additional
// calls should no longer decrement the variable. The lambda should
// return a bool that indicates whether the captured variable is 0.

#include <iostream>

int main(int argc, char *argv[argc])
{
  int number = 5;

  auto floor_decrement = [&number] () -> bool {
    if (number == 0) return true;
    --number;
    return false;
  };

  std::cout << "Initially, number = " << number << std::endl;
  floor_decrement();
  std::cout << "1st floor_decrement(), number = " << number << std::endl;
  floor_decrement();
  std::cout << "2nd floor_decrement(), number = " << number << std::endl;
  floor_decrement();
  std::cout << "4rd floor_decrement(), number = " << number << std::endl;
  floor_decrement();
  std::cout << "4th floor_decrement(), number = " << number << std::endl;
  floor_decrement();
  std::cout << "5th floor_decrement(), number = " << number << std::endl;
  floor_decrement();
  std::cout << "6th floor_decrement(), number = " << number << std::endl;
  floor_decrement();
  std::cout << "7th floor_decrement(), number = " << number << std::endl;
  floor_decrement();
  std::cout << "8th floor_decrement(), number = " << number << std::endl;

  return 0;
}

