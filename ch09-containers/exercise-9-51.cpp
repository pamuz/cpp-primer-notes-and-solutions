// Exercise 9.51, page 468
//
// Write a class that has three unsigned members representing year,
// month, and day. Write a constructor that takes a string
// representing a date. Your constructor should handle a variety of
// date formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and
// so on.

#include <iostream>
#include <string>
#include <array>

std::array<std::string, 12> full_month_names = { "January", "February", "March",
                                             "April", "May", "June", "July",
                                             "August", "September", "October",
                                             "November", "December" };

std::array<std::string, 12> short_month_names = { "Jan", "Feb", "Mar", "Apr",
                                                  "May", "Jun", "Jul", "Aug",
                                                  "Sept", "Oct", "Nov", "Dec" };

class Date {
  friend void print(std::ostream &os, const Date &d);

private:
  unsigned year = 1970;
  unsigned month = 1;
  unsigned day = 1;

public:
  Date(unsigned yr, unsigned mnt, unsigned d) :
    year(yr), month(mnt), day(d) { }

  Date(std::string str_date) {
    bool begins_with_char = str_date.find_first_not_of(numeric_chars) == 0;

    if (begins_with_char) {
      std::string month_name = str_date.substr(0, str_date.find_first_of(" ,"));

      decltype(full_month_names.size()) month_i = 0;

      for (month_i = 0; month_i < 12; ++month_i) {
        if (month_name == full_month_names[month_i]) {
          month = month_i + 1;
          break;
        }
      }

      for (month_i = 0; month_i < 12; ++month_i) {
        if (month_name == short_month_names[month_i]) {
          month = month_i + 1;
          break;
        }
      }

      auto first_day_digit = str_date.find_first_of(numeric_chars);
      auto last_day_digit = str_date.find_first_of(" /,", first_day_digit+1) - 1;
      auto day_digits = str_date.substr(first_day_digit, last_day_digit);

      auto first_year_digit = str_date.find_first_of(numeric_chars, last_day_digit + 1);
      auto last_year_digit = str_date.size() - 1;
      auto year_digits = str_date.substr(first_year_digit, last_year_digit);

      year = stoi(year_digits);
      day = stoi(day_digits);
    } else {
      auto first_day_digit = str_date.find_first_of(numeric_chars);
      auto last_day_digit = str_date.find_first_of(" /", first_day_digit+1) - 1;
      auto day_digits = str_date.substr(first_day_digit, last_day_digit);

      auto first_month_digit = str_date.find_first_of(numeric_chars, last_day_digit + 1);
      auto last_month_digit = str_date.find_first_of(" /,", first_month_digit+1) - 1;
      auto month_digits = str_date.substr(first_month_digit, last_month_digit);

      auto first_year_digit = str_date.find_first_of(numeric_chars, last_month_digit);
      auto last_year_digit = str_date.size() - 1;
      auto year_digits = str_date.substr(first_year_digit, last_year_digit);

      year = stoi(year_digits);
      month = stoi(month_digits);
      day = stoi(day_digits);
    }
  }

  Date(const char* old_str_date) : Date(std::string(old_str_date)) { }

  static std::string numeric_chars;
  static std::string init_numeric_chars() { return std::string("0123456789"); };
};

void print(std::ostream &os, const Date &d) {
  os << d.year << "/" << d.month << "/" << d.day;
}

std::string Date::numeric_chars = Date::init_numeric_chars();

int main(int argc, char *argv[argc])
{

  Date new_year(2018, 1, 1);
  print(std::cout, new_year);
  std::cout << std::endl;

  Date format1("April 10, 1991");
  print(std::cout, format1);
  std::cout << std::endl;
  
  return 0;
}
