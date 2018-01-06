#ifndef _PERSON_G
#define _PERSON_G

#include <string>

struct Person {
  std::string name;
  std::string address;

  Person() = default;
  Person(std::string name, std::string address):
    name(name), address(address) {};

  std::string get_name const();
  std::string get_address const();
};


std::istream &read(std::istream &is, Person &p);
std::ostream &print(std::ostream &os, const Person &p);

#endif
