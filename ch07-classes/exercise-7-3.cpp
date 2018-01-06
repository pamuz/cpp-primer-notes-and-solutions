#include "Sales_data.h"

int main(int argc, char *argv[argc])
{
  Sales_data example("abc", 10, 20);

  print(std::cout, example);

  Sales_data total(std::cin);

  Sales_data trans;
  while(read(std::cin, trans)) {
    if (total.isbn() == trans.isbn()) {
      total.combine(trans);
    } else {
      print(std::cout, total) << std::endl;
      total = trans;
    }
  }
 
  return 0;
}
