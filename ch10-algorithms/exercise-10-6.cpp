// Exercise 10.6, page 484
//
// Using fill_n, write a program to set a sequence of int values to 0.

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[argc])
{
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::fill_n(numbers.begin(), numbers.size(), 0);

  for (auto n : numbers) {
    std::cout << n << std::endl;
  }
  
  return 0;
}

