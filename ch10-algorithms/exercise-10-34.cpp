// Exercise 10.34, page 516
//
// Use reverse_iterators to print a vector in reverse
// order.

#include <iostream>
#include <vector>

int main(int argc, char *argv[argc])
{
  std::vector<std::string> words = { "the", "brown", "fox", "jumped", "over",
                                     "the", "fence" };

  for (auto w_it = words.crbegin(); w_it != words.crend(); ++w_it) {
    std::cout << *w_it << " ";
  }

  std::cout << std::endl;
  
  return 0;
}
