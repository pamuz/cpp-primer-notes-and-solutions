// Exercise 14.42, page 713
//
// Using library function objects and adaptors, define an
// expression to:
// (a) Count the number of values that are greater than 1024
// (b) Find the first string that is not equal to pooh
// (c) Multiply all values by 2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

int main(int argc, char *argv[])
{
  std::vector<int> nums = { 10, 100, 1000, 10000, 100000, 1000000 };
  std::vector<std::string> words = { "pooh", "pooh", "hello", "world" };

  std::greater<int> greater;
  auto greater_than_1024 = std::bind(greater, _1, 1024);

  int count_greater_than_1024 = std::count_if(nums.cbegin(), nums.cend(), greater_than_1024);

  std::cout << "The number of values greater than 1024 is: " << count_greater_than_1024 << std::endl;

  std::not_equal_to<std::string> neq;
  auto neq_to_pooh = std::bind(neq, _1, std::string("pooh"));

  auto first_different_to_pooh = std::find_if(words.cbegin(), words.cend(), neq_to_pooh);

  std::cout << "The first string different from 'pooh' is: " << *first_different_to_pooh << std::endl;

  std::multiplies<int> mult;
  auto double_num = std::bind(mult, _1, 2);
  std::transform(nums.begin(), nums.end(), nums.begin(), double_num);

  std::cout << "Values of nums after doubling: " << std::endl;
  for (auto x : nums) {
    std::cout << x << std::endl;
  }
  
  return 0;
}
