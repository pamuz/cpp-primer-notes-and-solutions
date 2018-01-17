#ifndef _SALES_DATA_G
#define _SALES_DATA_G

#include <string>
#include <iostream>

struct Sales_data {
  std::string book_no;
  unsigned units_sold = 0;
  double revenue = 0.0;

  Sales_data() = default;
  Sales_data(std::istream &is);

Sales_data(std::string isbn, unsigned units_sold, double rev):
  book_no(isbn), units_sold(units_sold), revenue(rev) {};

Sales_data(std::string isbn):
  book_no(isbn) {};

  std::string isbn() const { return book_no; }
  Sales_data& combine(const Sales_data&);
  double avg_price() const;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

std::ostream& operator<<(std::ostream &os, Sales_data& sales_data);

// Exercise 14.9
// Define an input opeator for you Sales_data class
std::istream& operator>>(std::istream &is, Sales_data& sales_data);

#endif
