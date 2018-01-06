// Exercise 11.7, page 533
//
// Define a map for which the key is the family’s last name and the
// value is a vector of the children’s names. Write code to add new
// families and to add new children to an existing family.

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main(int argc, char *argv[argc])
{
  std::unordered_map<std::string, std::vector<std::string>> families_data = {
    { "Munoz", { "Pablo" } } ,
    { "Ortega", { "Ricardo", "Sergio" } } 
  };

  families_data["Haro"] = { "Adriana", "Elizabeth", "Carlos", "Roberto" };

  for (auto family_children : families_data) {
    std::cout << "Children of the family " << family_children.first << std::endl;
    for (auto child_name : family_children.second) {
      std::cout << child_name << " " << std::endl;
    }
    std::cout << std::endl;
  }
  
  return 0;
}

