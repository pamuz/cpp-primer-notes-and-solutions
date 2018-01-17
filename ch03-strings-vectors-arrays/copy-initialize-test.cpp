#include <iostream>
#include <string>
#include <memory>

class Animal {
public:
  Animal(const std::string &n): name(n) {}
  Animal(const Animal& other): name(other.name) {
    std::cout << "Animal copy constructor called." << std::endl;
  }
  Animal& operator=(const Animal &other) {
    name = other.name;
    std::cout << "Animal copy assignment called." << std::endl;
    return *this;
  }
  // Animal& operator=(const Animal &other) = delete;
  std::string get_name() { return name; }
private:
  std::string name;
};

int main(int argc, char *argv[argc])
{

  Animal cat("cat");
  Animal cat2 = cat;

  std::allocator<Animal> alloc;

  Animal *cat3 = alloc.allocate(1);
  *cat3 = cat2;

  std::cout << "cat.get_name(): " << cat.get_name() << std::endl;
  std::cout << "cat2.get_name(): " << cat2.get_name() << std::endl;
  std::cout << "cat3->get_name(): " << cat3->get_name() << std::endl;
  
  return 0;
}

