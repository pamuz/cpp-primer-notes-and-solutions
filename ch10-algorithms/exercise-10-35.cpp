// Exercise 10.34, page 516
//
// Now print the elements in reverse order using ordinary iterators.

#include <iostream>
#include <vector>

int main(int argc, char *argv[argc])
{
  std::vector<std::string> words = { "the", "brown", "fox", "jumped", "over",
                                     "the", "fence" };

  for (auto w_it = words.cend(); w_it != words.cbegin(); --w_it) {
    std::cout << *(w_it - 1) << " ";
  }

  std::cout << std::endl;
  
  return 0;
}
