// Exercise 11.9, page 535
//
// Define a map that associates words with a list of line
// numbers on which the word might occur.

#include <iostream>
#include <map>
#include <list>
#include <string>

int main(int argc, char *argv[argc])
{
  std::map<std::string, std::list<int>> possible_line_map = {
    { "Hello", {1, 10, 35, 88 } },
    { "world", {2, 3, 4, 5}}
  };

  for (auto word_lines : possible_line_map) {
    std::cout << "Word " << word_lines.first << " may appear in lines: ";
    for (auto line_no : word_lines.second) {
      std::cout << line_no << " ";
    }
    std::cout << std::endl;
  }
  
  return 0;
}

