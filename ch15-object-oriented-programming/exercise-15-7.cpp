// Exercise 15.6, page 742
//
// Test your print_total function from the exercises in § 15.2.1
// (p. 595) by passing both Quote and Bulk_quote objects o that
// function.

#include "Quote.h"
#include "Limited_bulk.h"

int main(int argc, char *argv[argc])
{
  Quote q1("123-456-789", 50);
  Limited_bulk_quote q3("123-456-789", 50, 0.2, 5);

  print_total(std::cout, q1, 20);
  print_total(std::cout, q3, 20);
  print_total(std::cout, q3, 4);
  
  return 0;
}

