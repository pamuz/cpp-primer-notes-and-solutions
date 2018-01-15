#include "StrVec.h"
#include <iostream>

int main(int argc, char *argv[argc])
{

  std::cout << "Type a word to enter it into the vector, or 'q' to quit" << std::endl;
  std::string user_input;

  StrVec vec;

  while(std::cin >> user_input) {
    if (user_input == "q") break;
    vec.push_back(user_input);
    std::cout << "vec now contains: " << std::endl;
    for (auto s = vec.begin(); s != vec.end(); ++s) {
      std::cout << *s << std::endl;
    }
    std::cout << std::endl;
  }
  
  return 0;
}
