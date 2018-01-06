// Exercise 11.23, page 544
//
// Rewrite the map that stored vectors of children’s names with a key
// that is the family last name for the exercises in § 11.2.1 (p. 424)
// to use a multimap.

#include <iostream>
#include <string>
#include <map>

int main(int argc, char *argv[argc])
{
  std::multimap<std::string, std::string> families_data;

  families_data.insert({ "Munoz", "Pablo" });
  families_data.insert({ "Ortega", "Sergio" });
  families_data.insert({ "Ortega", "Ricard" });
  families_data.insert({ "Haro", "Adriana" });
  families_data.insert({ "Haro", "Elizabeth" });
  families_data.insert({ "Haro", "Carlos" });
  families_data.insert({ "Haro", "Roberto" });

  for (auto child_data : families_data) {
    std::cout << child_data.second << " in family " << child_data.first << std::endl;
  }

  std::cout << "Members of the Haro family: " << std::endl;
  for (auto childrenp = families_data.equal_range("Haro");
       childrenp.first != childrenp.second;
       ++(childrenp.first)) {
    std::cout << childrenp.first->second << std::endl;
  }
  
  return 0;
}

