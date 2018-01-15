// Exercise 13.19, page 633
//
// Does your Employee class need to define its own versions of the
// copy-control members? If so, why? If not, why not? Implement
// whatever copy-control members you think Employee needs.

#include <iostream>
#include <string>
#include <memory>

class Employee {
public:
  Employee(): name(std::string()), id(next_id++){}
  Employee(std::string n): name(n), id(next_id++) {}
  Employee(Employee &other) {
    name = other.name;
    id = next_id++;
  }
  Employee &operator=(const Employee &other) {
    name = other.name;
    id = next_id++;
    return *this;
  }
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
  Employee pablo2 = pablo;

  // Use allocator to reserve space for a new employee
  // that will be a copy-assign of pablo without triggering
  // the constructor on declaration (this way we don't "waste")
  // an employee id
  std::allocator<Employee> employee_allocator;
  Employee *pablo3 = employee_allocator.allocate(1);
  *pablo3 = pablo;

  std::cout << default_employee.get_name() << ", " << default_employee.get_id()
            << std::endl;

  std::cout << pablo.get_name() << ", " << pablo.get_id() << std::endl;

  std::cout << sergio.get_name() << ", " << sergio.get_id() << std::endl;

  std::cout << pablo2.get_name() << ", " << pablo2.get_id() << std::endl;

  std::cout << pablo3->get_name() << ", " << pablo3->get_id() << std::endl;
  
  return 0;
}

