// Exercise 10.1, page 477
//
// The algorithm header defines a function named count that, like
// find, takes a pair of iterators and a value. count returns a count
// of how often that value appears. Read a sequence of ints into a
// vector and print the count of how many elements have a given value.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

int main(int argc, char *argv[argc])
{
  int num_read;

  std::vector<int> num_vector = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5 };
  int count_of_fives = std::count(num_vector.cbegin(), num_vector.cend(), 5);
  std::cout << "There are " << count_of_fives << " fives in num_vector." << std::endl;

  std::list<int> num_list = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5 };
  int count_of_fours = std::count(num_list.cbegin(), num_list.cend(), 4);
  std::cout << "There are " << count_of_fours << " fours in num_vector." << std::endl;
 
  return 0;
}

