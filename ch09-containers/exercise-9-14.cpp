// Exercise 9.14, page 433
// Write a program to assign the elements from a list of char*
// pointers to C-style character strings to a vector of strings.

#include <iostream>
#include <list>
#include <vector>

int main(int argc, char *argv[argc])
{
  std::list<const char*> charp_list = { "abc", "def", "ghi", "jkl" };
  std::vector<std::string> str_vector(charp_list.cbegin(), charp_list.cend());

  std::cout << "Elements of charp_list:" << std::endl;
  for (auto s : charp_list) {
    std::cout << s << std::endl;
  }

  std::cout << "Elements of str_vector:" << std::endl;
  for (auto s : str_vector) {
    std::cout << s << std::endl;
  }
  
  return 0;
}

