// Exercise 14.37, page 709
//
// Write a class that tests whether two values are equal. Use that
// object and the library algorithms to write a program to replace all
// instances of a given value in a sequence.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct EqualComparator {
  EqualComparator(std::string s): compare_to(s) {}
  bool operator()(std::string candidate) {
    return candidate == compare_to;
  }
private:
  std::string compare_to;
};

int main(int argc, char *argv[argc])
{
  std::vector<std::string> words = { "hola", "hola", "hola", "mundo", "hola" };
  EqualComparator comparer("hola");

  std::replace_if(words.begin(), words.end(), comparer, "hello");

  for (std::string s : words) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  
  return 0;
}

