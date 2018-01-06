/*
 * This program is the solution by Pablo Muñoz to the exercise 1.4
 * of the C++ primer book.
 *
 * Exercise instruction: Write a program that uses the multiplication
 * operator, *, to print the product of two numbers.
 *
 */

#include <iostream>

int main() {
  std::cout << "This program multipliers two numbers." << std::endl;
  std::cout << "Enter the numbers separated by whitespace: " << std::endl;

  int number_1, number_2;

  std::cin >> number_1 >> number_2;

  int result = number_1 * number_2;

  std::cout << "Result: " << result << std::endl;
}
