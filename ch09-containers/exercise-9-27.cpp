// Exercise 9.26, page 448
//
// Write a program to find and remove the odd-valued elements in a
// forward_list<int>.

#include <iostream>
#include <forward_list>

int main(int argc, char *argv[argc])
{
  std::forward_list<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  auto prev = nums.before_begin();
  auto curr = nums.begin();

  while (curr != nums.end()) {
    bool curr_is_odd = ((*curr) % 2) != 0;
    if (curr_is_odd) {
      nums.erase_after(prev);
    }
    prev = curr;
    ++curr;
  }

  std::cout << "Numbers in forward list (all should be even): " << std::endl;
  for (auto num_it = nums.begin(); num_it != nums.end(); ++num_it) {
    std::cout << *num_it << std::endl;
  }
  
  return 0;
}
