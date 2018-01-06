// Exercise 13.17.cpp, page 628
//
// Write versions of numbered and f corresponding to the previous
// three exercises and check whether you correctly predicted the
// output.

#include <iostream>
#include <string>

class numbered {
public:
  numbered() {
    std::cout << "numbered() called" << std::endl;
    mysn = nextsn++;
    text = std::string("A numbered instance.");
  }
  numbered(numbered &orig) {
    std::cout << "numbered(numbered &orig)" << std::endl;
    mysn = nextsn++;
    text = orig.text;
  }
  numbered& operator=(numbered &orig) {
    std::cout << "numbered& operator=(numbered &orig) called" << std::endl;
    mysn = nextsn++;
    text = orig.text;
    return *this;
  }
  static int init_nextsn() { return 1; }
  static int nextsn;
  int mysn;
  std::string text;
private:
};

void f1(numbered s) {
  std::cout << s.mysn << std::endl;
}

void f2(const numbered &s) {
  std::cout << s.mysn << std::endl;
}

int numbered::nextsn = numbered::init_nextsn();

int main(int argc, char *argv[argc])
{

  numbered a, b = a, c = b;
  std::cout << "f1(a); f1(b); f1(c);" << std::endl;
  f1(a); f1(b); f1(c);

  std::cout << "f2(a); f2(b); f2(c);" << std::endl;
  f2(a); f2(b); f2(c);

  return 0;
}

