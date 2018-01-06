// Exercise 11.12, page 537
//
// Write a program to read a sequence of strings and ints,
// storing each into a pair. Store the pairs in a vector.

#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main(int argc, char *argv[argc])
{
  std::string read_str;
  int read_int;
  std::vector<std::pair<std::string, int>> pairs;

  while ((std::cin >> read_str) >> read_int) {
    pairs.push_back({read_str, read_int});
  }

  for (auto p : pairs) {
    std::cout << p.first << ": " << p.second << std::endl;
  }
  
  return 0;
}

