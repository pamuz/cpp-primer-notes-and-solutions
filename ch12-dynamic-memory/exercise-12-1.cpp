// Exercise 12.1, page 572
//
// How many elements do b1 and b2 have at the end of this
// code?
// StrBlob b1;
// {
// StrBlob b2 = {"a", "an", "the"};
// b1 = b2;
// b2.push_back("about");
// }
// The answer is that there should be 4 elements "a", "an", "the" and "about".
// Even though b2 has gone out of scope and destroyed, there is still a reference
// to the vector in b1, so it wasn't destroyed.

#include <iostream>
#include "StrBlob.h"

int main(int argc, char *argv[argc])
{
  StrBlob b1;
  {
    StrBlob b2 = { "a", "an", "the" };
    b1 = b2;
    b2.push_back("about");
  }
  std::cout << "b1.size(): " << b1.size() << std::endl;
  return 0;
}
