// Exercise 9.50, page 468
//
// Write a program to process a vector<string>s whose elements
// represent integral values. Produce the sum of all the elements in
// that vector. Change the program so that it sums of strings that
// represent floating-point values.

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[argc])
{
  std::vector<std::string> int_strings = { "1", "2", "3", "4", "5cinco" };

  int total = 0;
  for (auto n : int_strings) {
    total += std::stoi(n);
  }

  std::cout << "The sum over int_strings totals: " << total << std::endl;

  std::vector<std::string> double_strings = { "10.5", "50.8", "100.92", "5.3whatever" };

  double dtotal = 0.0;
  for (auto n : double_strings) {
    dtotal += std::stod(n);
  }

  std::cout << "The sum over double_strings totals: " << dtotal << std::endl;
  
  return 0;
}

