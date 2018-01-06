// Exercise 10.31, page 513
//
// Update the program from the previous exercise so that it prints
// only the unique elements. Your program should use unique_copy (§
// 10.4.1, p. 403).

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(int argc, char *argv[argc])
{
  std::istream_iterator<int> cin_iter(std::cin), eof;
  std::ostream_iterator<int> cout_iter(std::cout);
  std::vector<int> numbers;
  std::copy(cin_iter, eof, std::back_inserter(numbers));
  std::sort(numbers.begin(), numbers.end());
  std::unique_copy(numbers.cbegin(), numbers.cend(), cout_iter);
  std::cout << std::endl;
  
  return 0;
}

