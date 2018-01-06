// Exercise 10.37, page 516
//
// Given a vector that has ten elements, copy the elements from
// positions 3 through 7 in reverse order to a list.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(int argc, char *argv[argc])
{
  std::vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> nums_copy;
  std::copy(nums.crbegin() + 3, nums.crend() - 2, std::back_inserter(nums_copy));

  for (auto n : nums_copy) std::cout << n << std::endl;
  
  return 0;
}

