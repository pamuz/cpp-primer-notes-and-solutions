// Exercise 10.30, page 513
//
// Use stream iterators, sort, and copy to read a sequence of integers
// from the standard input, sort them, and then write them back to the
// standard output.

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
  std::copy(numbers.cbegin(), numbers.cend(), cout_iter);
  
  return 0;
}

