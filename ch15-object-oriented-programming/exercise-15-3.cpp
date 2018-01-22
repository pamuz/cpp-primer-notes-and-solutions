// Exercise 15.3, page 736
//
// Define your own versions of the Quote class and the print_total
// function.

#include "Quote.h"

int main(int argc, char *argv[argc])
{
  Quote q1("1234-56789", 50.0);

  print_total(std::cout, q1, 20);
  
  return 0;
}

