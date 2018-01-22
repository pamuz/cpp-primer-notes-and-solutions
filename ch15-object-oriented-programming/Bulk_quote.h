#ifndef __BULK_QUOTE_G_
#define __BULK_QUOTE_G_

#include "Quote.h"

class Bulk_quote : public Quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double sales_price, double disc):
    Quote(book, sales_price), discount(disc)  {}
  double net_price(std::size_t n) const
  { return n > 5 ? price * n * (1-discount) : price * n; }
  ~Bulk_quote() = default;
private:
  double discount = 0.0;
protected:
};

#endif
