// Exercise 10.27, page 508
//
// In addition to unique (§ 10.2.3, p. 384), the library defines
// function named unique_copy that takes a third iterator denoting a
// destination into which to copy the unique elements. Write a program
// that uses unique_copy to copy the unique elements from a vector
// into an initially empty list.

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main(int argc, char *argv[argc])
{
  std::vector<int> num_vector = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 100, 100 };
  std::list<int> num_list;

  unique_copy(num_vector.cbegin(), num_vector.cend(), back_inserter(num_list));

  std::cout << "The elements of num_vector are:" << std::endl;
  for (auto n_it : num_vector) {
    std::cout << n_it << std::endl;
  }

  std::cout << "The elements of num_list are:" << std::endl;
  for (auto n_it : num_list) {
    std::cout << n_it << std::endl;
  }
  
  return 0;
}
