// Exercise 10.22, page 506
//
// Rewrite the program to count words of size 6 or less using
// functions in place of the lambdas.

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

bool less_than(int number, int limit) {
  return number < limit;
}

int main(int argc, char *argv[argc])
{
  std::vector<int> nums = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

  int less_than_6_count = std::count_if(nums.begin(), nums.end(),
                                     std::bind(less_than, _1, 6));

  std::cout << "There are " << less_than_6_count
            << " numbers smaller than 6 in the nums vector." << std::endl;

  auto less_than_first_endp = std::partition(nums.begin(), nums.end(),
                                             std::bind(less_than, _1, 6));

  std::cout << "The numbers less than 6 are: " << std::endl;
  for (auto np = nums.cbegin(); np < less_than_first_endp; ++np) {
    std::cout << *np << std::endl;
  }

  return 0;
}

