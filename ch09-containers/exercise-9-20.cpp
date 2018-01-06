// Exercise 9.20, page 441
//
// Write a program to copy elements from a list<int> into two
// deques. The even-valued elements should go into one deque and the
// odd ones into the other.

#include <iostream>
#include <list>
#include <deque>
#include <string>

int main(int argc, char *argv[argc])
{
  std::list<int> list_of_nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  std::cout << "The numbers in the list are: " << std::endl;
  for (auto num_it = list_of_nums.cbegin(); num_it != list_of_nums.cend(); ++num_it) {
    std::cout << *num_it << std::endl;
  }

  std::deque<int> even_nums_deque;
  std::deque<int> odd_nums_deque;

  for (auto num_it = list_of_nums.cbegin(); num_it != list_of_nums.cend(); ++num_it) {
    bool num_is_even = ((*num_it) % 2) == 0;
    if (num_is_even) {
      even_nums_deque.push_back(*num_it);
    } else {
      // num is od
      odd_nums_deque.push_back(*num_it);
    }
  }

  std::cout << "The numbers in the even number deque are: " << std::endl;
  for (auto num_it = even_nums_deque.begin(); num_it != even_nums_deque.end();
       ++num_it) {
    std::cout << *num_it << std::endl;
  }

  std::cout << "The numbers in the odd number deque are: " << std::endl;
  for (auto num_it = odd_nums_deque.begin(); num_it != odd_nums_deque.end();
       ++num_it) {
    std::cout << *num_it << std::endl;
  }
  
  return 0;
}
