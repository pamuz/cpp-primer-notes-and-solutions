#include "Person.h"

std::string Person::get_name const() {
  return name;
}

std::string Person::get_address const() {
  return address;
}

std::istream &read(std::istream &is, Person &p) {
  is >> p.name >> p.address;
  return is;
}

std::ostream &print(std::ostream &os, const Person &p) {
  os << p.name << "(" << p.address << ")";
}
