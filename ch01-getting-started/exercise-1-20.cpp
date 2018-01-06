#include <iostream>
#include "Sales_item.h"

int main(int argc, char *argv[argc])
{
  std::cout << "Enter data for 2 book sales. " << std::endl;
  Sales_item sale1;
  Sales_item sale2;

  std::cin >> sale1 >> sale2;

  std::cout << "The sales you entered where: " << std::endl;
  std::cout << "Sale #1: " << sale1 << std::endl;
  std::cout << "Sale #2: " << sale2 << std::endl;
  
  return 0;
}
