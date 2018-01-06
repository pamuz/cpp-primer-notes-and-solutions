// Exercise 10.29, page 513
//
// Write a program using stream iterators to read a text file
// into a vector of strings.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

int main(int argc, char *argv[argc])
{
  std::ifstream text_file("text_file.txt");
  std::istream_iterator<std::string> file_iter(text_file), eof;
  std::vector<std::string> contents(file_iter, eof);

  for (auto s : contents) {
    std::cout << s << std::endl;
  }
  
  return 0;
}

