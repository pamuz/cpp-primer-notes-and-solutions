/*
 * This program is the solution by Pablo Muñoz to the exercise 1.8
 * of the C++ primer book.
 *
 * Exercise instruction: Verify what happens when we run a program
 * with different use of comment in statements comments.
 *
 */

#include <iostream>

int main() {
  std::cout << "/*" << std::endl;
  std::cout << "*/" << std::endl;
  // std::cout << /* "*/" */ << std::endl;
  std::cout << /* "*/" /* "/*" */ << std::endl;
}
