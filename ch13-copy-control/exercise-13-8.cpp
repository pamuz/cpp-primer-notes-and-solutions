// Exercise 13.8, page 622
//
// Write the assignment operator for the HasPtr class from exercise
// 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your
// assignment operator should copy the object to which ps points.

#include <iostream>
#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &orig):
    ps(new std::string(*(orig.ps))), i(orig.i) { std::cout << "Copy constructor called." << std::endl;  }
  HasPtr& operator=(HasPtr& other) {
    std::cout << "Copy assignment constructor called" << std::endl;
    delete ps;
    ps = new std::string(*(other.ps));
    i = other.i;
    return *this;
  }
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

  std::cout << "copy1 = noncopy;" << std::endl;
  copy1 = noncopy;

  return 0;
}
