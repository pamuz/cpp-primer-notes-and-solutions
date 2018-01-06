// Exercise 13.5, page 620
//
// Given the following sketch of a class, write a copy constructor
// that copies all the members. Your constructor should dynamically
// allocate a new string (§ 12.1.2, p. 458) and copy the object to
// which ps points, rather than copying ps itself.

#include <iostream>
#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &orig):
    ps(new std::string(*(orig.ps))), i(orig.i) { std::cout << "Copy constructor called." << std::endl;  }
private:
  std::string *ps;
  int i;
};

void function_with_nonref_param(HasPtr a) {
  return;
}

HasPtr has_ptr_factory() {
  HasPtr ret("I was created in a factory.");
  return ret;
}

int main(int argc, char *argv[argc])
{
  std::cout << "HasPtr noncopy(\"Hello, worls!\");" << std::endl;
  HasPtr noncopy("Hello, worlds!");

  std::cout << "HasPtr copy1 = noncopy;" << std::endl;
  HasPtr copy1 = noncopy;

  std::cout << "HasPtr copy2(noncopy);" << std::endl;
  HasPtr copy2(noncopy);
  std::cout << "function_with_nonref_param(noncopy);" << std::endl;
  function_with_nonref_param(noncopy);

  std::cout << "HasPtr factory_made = has_ptr_factory();" << std::endl;
  HasPtr factory_made = has_ptr_factory();

  return 0;
}
