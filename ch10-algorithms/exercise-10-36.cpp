// Exercise 10.36, page 516
//
// Use find to find the last element in a list of ints with value 0.

#include <iostream>
#include <vector>

int main(int argc, char *argv[argc])
{
  std::vector<int> nums = { 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};

  auto last_zero = std::find(nums.rbegin(), nums.rend(), 0);

  std::cout << *last_zero << std::endl;

  return 0;
}

