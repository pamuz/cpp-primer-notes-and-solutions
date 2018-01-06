#include <iostream>
#include <vector>

int main(int argc, char *argv[argc])
{
  std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::vector<int> nums_reversed(nums.crbegin(), nums.crend());

  std::cout << "Elements of nums:" << std::endl;
  for (auto n : nums) {
    std::cout << n << std::endl;
  }

  std::cout << "Elements of nums_reversed:" << std::endl;
  for (auto n : nums_reversed) {
    std::cout << n << std::endl;
  }
  
  return 0;
}
