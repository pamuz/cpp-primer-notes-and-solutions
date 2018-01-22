// Exercise 14.43, page 713
//
// Using library function objects, determine whether a given int value
// is divisible by any element in a container of ints.

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main(int argc, char *argv[argc])
{
  using namespace std::placeholders;

  int target = 1024;
  std::vector<int> possible_divisors = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
                                        13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };


  std::logical_not<int> neg;
  std::modulus<int> mod;
  auto divisible_by = std::bind(neg, std::bind(mod, target, _1));

  auto divisors_end = std::partition(possible_divisors.begin(),
                                     possible_divisors.end(), 
                                     divisible_by);

  for (auto x = possible_divisors.cbegin(); x != divisors_end; ++x) {
    std::cout << *x << " divides " << target << std::endl;
  }
  
  return 0;
}

