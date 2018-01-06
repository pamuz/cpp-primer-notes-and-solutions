// Exercise 9-26, page 446
//
// Using the following definition of ia, copy ia into a vector and
// into a list. Use the single-iterator form of erase to remove the
// elements with odd values from your list and the even values from
// your vector.

#include <iostream>
#include <list>
#include <vector>
#include <string>

int main(int argc, char *argv[argc])
{
  int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

  // Copy
  std::vector<int> iv(std::begin(ia), std::end(ia));
  std::list<int> il(std::begin(ia), std::end(ia));

  // Erase based on evenness
  for (auto iv_iter = iv.cbegin(); iv_iter != iv.cend(); ++iv_iter) {
    bool element_is_even = ((*iv_iter) % 2) == 0;
    if (element_is_even) {
      iv.erase(iv_iter);
    }
  }

  // Erase based on evenness
  for (auto il_iter = il.cbegin(); il_iter != il.cend(); ++il_iter) {
    bool element_is_odd = ((*il_iter) % 2) != 0;
    if (element_is_odd) {
      il.erase(il_iter);
    }
  }

  std::cout << "Elements in vector (all should be odd):" << std::endl;
  for (auto iv_iter = iv.cbegin(); iv_iter != iv.cend(); ++iv_iter) {
    std::cout << *iv_iter << std::endl;
  }

  std::cout << "Elements in list (all should be even):" << std::endl;
  for (auto il_iter = il.cbegin(); il_iter != il.cend(); ++il_iter) {
    std::cout << *il_iter << std::endl;
  }
  
  return 0;
}
