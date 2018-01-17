// Exercise 14.9, page 693
//
// Define an input operator for your Sales_data class.

#include "Sales_data.h"

int main(int argc, char *argv[argc])
{
  Sales_data sales_data;
  std::cout << "Enter a sales_data values, or EOF to quit." << std::endl;

  while (std::cin >> sales_data) {
    std::cout << "You entered: " << std::endl;
    std::cout << sales_data << std::endl;
  }
  
  return 0;
}
