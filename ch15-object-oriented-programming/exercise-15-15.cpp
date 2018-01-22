// Exercise 15.5, page 755
//
// Define your own versions of Disc_quote and Bulk_quote.

#include <iostream>
#include <string>
#include "Quote.h"

class Disc_quote : public Quote {
public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double price, std::size_t qty, double disc):
    Quote(book, price), quantity(qty), discount(disc) {}
  double net_price(std::size_t) const = 0;
protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double price, std::size_t qty, double disc):
    Disc_quote(book, price, qty, disc) {}
  double net_price(std::size_t num) const {
    return (num > quantity) ? (1-discount)*price*num : price*num;
  }
};

int main(int argc, char *argv[argc])
{

  // Disc_quote dquote; Wrong! Can't instantiate abstract base classes
  Bulk_quote bquote("123-456-789", 10.0, 5, 0.10);

  std::cout << "3 books cost: " << bquote.net_price(3) << std::endl;
  std::cout << "6 books cost: " << bquote.net_price(6) << std::endl;
  
  return 0;
}

