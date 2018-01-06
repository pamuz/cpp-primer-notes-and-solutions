// Exercise 9.47, page 466
//
// Write a program that finds each numeric character and then each
// alphabetic character in the string "ab2c3d7R4E6". Write two
// versions of the program. The first should use find_first_of, and
// the second find_first_not_of.

#include <iostream>
#include <string>

int main(int argc, char *argv[argc])
{
  std::string str = "ab2c3d7R4E6";

  // Chose to use the "numerics" as the argument as the domain
  // of values is much smaller.
  std::string numerics = "0123456789";

  std::string::size_type str_sz = str.size();
  std::string::size_type str_last_index = str_sz - 1;

  // Categorize using find_first_of
  std::string::size_type last_alphabetic_index = -1;
  auto next_numeric_index = str.find_first_of(numerics);

  while (next_numeric_index != std::string::npos) {
    bool there_are_alphabetics_in_between = (next_numeric_index - last_alphabetic_index) > 1;
    if (there_are_alphabetics_in_between) {
      decltype(last_alphabetic_index) alphabetic_index;
      for (alphabetic_index = last_alphabetic_index + 1;
           alphabetic_index < next_numeric_index; ++alphabetic_index) {
        std::cout << str[alphabetic_index] << " is alphabetic." << std::endl;
      }
      last_alphabetic_index = alphabetic_index;
    }
    std::cout << str[next_numeric_index] << " is numeric." << std::endl;
    next_numeric_index = str.find_first_of(numerics, next_numeric_index + 1);
  }

  if (next_numeric_index < str_last_index) {
    for (auto alphabetic_index = last_alphabetic_index;
         alphabetic_index < str_sz; ++alphabetic_index) {
      std::cout << str[alphabetic_index] << " is alphabetic." << std::endl;
    }
  }

  // find_first_not_of version would follow a similar logic, but interchanging
  // te places of alphabetics and numerics.
  
  return 0;
}

