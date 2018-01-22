// Exercise 15.6, page 742
//
// Test your print_total function from the exercises in § 15.2.1
// (p. 595) by passing both Quote and Bulk_quote objects o that
// function.

#include "Quote.h"
#include "Bulk_quote.h"

int main(int argc, char *argv[argc])
{
  Quote q1("123-456-789", 50);
  Bulk_quote q2("123-456-789", 50, 0.2);

  print_total(std::cout, q1, 20);
  print_total(std::cout, q2, 20);
  
  return 0;
}

