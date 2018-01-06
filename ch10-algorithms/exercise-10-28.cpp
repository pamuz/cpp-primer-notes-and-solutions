// Exercise 10.28, page 508
//
// Copy a vector that holds the values from 1 to 9 inclusive, into
// three other containers. Use an inserter, a back_inserter, and a
// front_inserter, respectivly to add elements to these
// containers. Predict how the output sequence varies by the kind of
// inserter and verify your predictions by running your programs.

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <iterator>

int main(int argc, char *argv[argc])
{
  std::vector<int> num_vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << "The elements of num_vec are:" << std::endl;
  for (auto n : num_vec) std::cout << n << std::endl;

  std::list<int> num_list;
  copy(num_vec.cbegin(), num_vec.cend(), std::inserter(num_list, num_list.end()));

  std::cout << "The elements of num_list are:" << std::endl;
  for (auto n : num_list) std::cout << n << std::endl;

  std::list<int> num_deque;
  copy(num_vec.cbegin(), num_vec.cend(), std::back_inserter(num_deque));

  std::cout << "The elements of num_deque are:" << std::endl;
  for (auto n : num_deque) std::cout << n << std::endl;

  std::forward_list<int> num_flist;
  copy(num_vec.cbegin(), num_vec.cend(), std::front_inserter(num_flist));

  std::cout << "The elements of num_flist are:" << std::endl;
  for (auto n : num_flist) std::cout << n << std::endl;

  
  return 0;
}
