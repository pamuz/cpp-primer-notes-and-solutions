#include "Sales_data.h"

int main(int argc, char *argv[argc])
{
  Sales_data total;
  if (read(std::cin, total)) {
    Sales_data trans;
    while(read(std::cin, trans)) {
      if (total.isbn() == trans.isbn())
        total.combine(trans);
    } else {
      print(cout, total) << std::endl;
    }
  } else {
    std::cerr << "No data?!" << std::endl;
  }
  
  return 0;
}
