#include "Sales_data.h"

Sales_data::Sales_data(std::istream &is) {
  read(is, *this);
}

Sales_data &Sales_data::combine(const Sales_data& other) {
  book_no = book_no;
  units_sold = units_sold + other.units_sold;
  revenue = revenue + other.revenue;

  return *this;
}

std::ostream &print(std::ostream& os, const Sales_data& sale_data) {
  os << "isbn: " << sale_data.isbn() << ", "
     << "units sold: " << sale_data.units_sold << ", "
     << "revenue: " << sale_data.revenue;

  return os;
}

std::istream &read(std::istream& is, Sales_data& sale_data) {
  is >> sale_data.book_no >> sale_data.units_sold >> sale_data.revenue;
  return is;
}

// Exercise 7.6
Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
  Sales_data addition_result = lhs;
  addition_result.units_sold += rhs.units_sold;
  addition_result.revenue += rhs.revenue;
  return addition_result;
}

std::ostream& operator<<(std::ostream &os, Sales_data& sales_data)
{
  os << sales_data.book_no << ", units sold: "
     << sales_data.units_sold << ", revenue: "
     << sales_data.revenue;
  return os;
}

std::istream& operator>>(std::istream &is, Sales_data& sales_data)
{
  is >> sales_data.book_no >> sales_data.units_sold >> sales_data.revenue;
  if (!is) {
    sales_data = Sales_data();
  }
  return is;
}
