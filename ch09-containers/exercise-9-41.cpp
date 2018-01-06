// Exercise 9.41, page 459
//
// Write a program that initializes a string from a vector<char>.

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[argc])
{
  std::string orig_str = "Hello, world!";
  std::vector<char> charv = { 'H', 'e', 'l', 'l', 'o', ' ',
                              'W', 'o', 'r', 'l', 'd' };
  std::string str(charv.cbegin(), charv.cend());
  std::cout << str << std::endl;

  std::string str2;
  str2.reserve(100);

  std::cout << str2.capacity() << std::endl;
  std::cout << str2.max_size() << std::endl;
 
  return 0;
}

