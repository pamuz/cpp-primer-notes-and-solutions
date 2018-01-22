#ifndef __LIMITED_BULK_QUOTE_G_
#define __LIMITED_BULK_QUOTE_G_

#include "Quote.h"

class Limited_bulk_quote : public Quote {
public:
  Limited_bulk_quote() = default;
  Limited_bulk_quote(const std::string &book, double sales_price, double disc, int lim):
    Quote(book, sales_price), discount(disc), limit(lim)  {}
  double net_price(std::size_t n) const
  { return n <= limit ? price * n * (1-discount) : price * n; }
  ~Limited_bulk_quote() = default;
private:
  double discount = 0.0;
  int limit = 5;
};

#endif
