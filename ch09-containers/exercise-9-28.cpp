// Exercise 9.28, page 448
//
// Write a function that takes a forward_list<string> and two
// additional string arguments. The function should find the first
// string and insert the second immediately following the first. If
// the first string is not found, then insert the second string at the
// end of the list.

#include <iostream>
#include <forward_list>
#include <string>

void insert_string_after(std::forward_list<std::string> &f_list,
                       std::string after_str,
                       std::string to_insert) {

  auto prev = f_list.cbefore_begin();
  auto curr = f_list.cbegin();
  while (curr != f_list.cend()) {
    bool current_is_after_target = (*curr) == after_str;

    if (current_is_after_target) {
      f_list.insert_after(curr, to_insert);
      return;
    }

    prev = curr;
    ++curr;
  }

  f_list.insert_after(prev, to_insert);

}

void print(const std::forward_list<std::string> &f_list) {
  for (auto s_iter = f_list.cbegin(); s_iter != f_list.cend(); ++s_iter) {
    std::cout << *s_iter << std::endl;
  }
}

int main(int argc, char *argv[argc])
{

  std::forward_list<std::string> strings = { "abc", "def", "jkl" };

  std::cout << "The forward list before we call any functions:" << std::endl;
  print(strings);

  std::cout << "After insert_string_after(strings, \"def\", \"ghi\"):" << std::endl;
  insert_string_after(strings, "def", "ghi");
  print(strings);

  std::cout << "After insert_string_after(strings, \"uvw\", \"xyz\"):" << std::endl;
  insert_string_after(strings, "uvw", "xyz");
  print(strings);
  
  return 0;
}

