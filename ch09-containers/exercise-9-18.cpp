// Exercise 9.18, page 441
//
//  Write a program to read a sequence of strings from the standard
//  input into a deque. Use iterators to write a loop to print the
//  elements in the deque.

#include <iostream>
#include <deque>
#include <string>

int main(int argc, char *argv[argc])
{
  std::deque<std::string> strings_from_input;

  std::string read_string;
  while(std::getline(std::cin, read_string)) {
    strings_from_input.push_back(read_string);
  }

  for(auto s_iter=strings_from_input.begin();
      s_iter != strings_from_input.end();
      ++s_iter) {
    std::cout << *s_iter << std::endl;
  }
  
  return 0;
}
