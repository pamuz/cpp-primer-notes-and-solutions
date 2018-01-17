// Exercise 14.36, page 709
//
// Write a class like PrintString that reads a line of input from an
// istream and returns a string representing what was read. If the
// read fails, return the empty string.

#include <iostream>
#include <string>

struct ReadString {
  ReadString(std::string dv): default_value(dv) {}
  std::string operator()(std::istream &is = std::cin) {
    std::string read;
    is >> read;
    return is ? read : default_value;
  }
private:
  std::string default_value;
};

int main(int argc, char *argv[argc])
{
  ReadString reader(std::string("nodata"));
  std::string read;

  while((read = reader()) != "nodata") {
    std::cout << read << std::endl;
  }

  std::cout << read << std::endl;
  
  return 0;
}

