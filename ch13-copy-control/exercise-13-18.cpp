// Exercise 13.18, page 633
//
// Define an Employee class that contains an employee name and a
// unique employee identifier. Give the class a default constructor
// and a constructor that takes a string representing the employee’s
// name. Each constructor should generate a unique ID by incrementing
// a static data member.

#include <iostream>
#include <string>

class Employee {
public:
  Employee(): name(std::string()), id(next_id++){}
  Employee(std::string n): name(n), id(next_id++) {}
  std::string get_name() {
    return name;
  }
  long get_id() {
    return id;
  }
private:
  std::string name;
  long id;
  static long next_id;
  static long init_employees_id() { return 1; }
};

long Employee::next_id = Employee::init_employees_id();

int main(int argc, char *argv[argc])
{
  Employee default_employee;
  Employee pablo("Pablo Munoz");
  Employee sergio("Sergio Ortega");

  std::cout << default_employee.get_name() << ", " << default_employee.get_id()
            << std::endl;

  std::cout << pablo.get_name() << ", " << pablo.get_id() << std::endl;

  std::cout << sergio.get_name() << ", " << sergio.get_id() << std::endl;
  
  return 0;
}

