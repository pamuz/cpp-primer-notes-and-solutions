#include <iostream>
#include <vector>


bool find_num_in_container(std::vector<int>::const_iterator begin,
                           std::vector<int>::const_iterator end,
                           int target) {
  std::vector<int>::const_iterator current = begin;

  while (current != end) {
    if (*current == target) {
      return true;
      break;
    } else {
      ++current;
    }
  }

  return false;
}


int main(int argc, char *argv[argc])
{
  std::vector<int> nums = { 2, 4, 6, 8, 10, 12, 14, 16 };

  bool found_8 = find_num_in_container(nums.cbegin(), nums.cend(), 8);
  std::cout << "8 found: " << found_8 << std::endl;

  bool found_3 = find_num_in_container(nums.cbegin(), nums.cend(), 3);
  std::cout << "3 found: " << found_3 << std::endl;
  
  return 0;
}

