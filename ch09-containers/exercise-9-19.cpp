// Exercise 9.19, page 441
//

// Rewrite the program from the previous exercise (9.18) to use a
// list. List the changes you needed to make.

#include <iostream>
#include <list>
#include <string>

int main(int argc, char *argv[argc])
{
  std::list<std::string> strings_from_input;

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

// The changes required where 2: To include the list header in place of
// the deque one, and to declare the container to be of type std::list<...
// instead of std::deque<...
