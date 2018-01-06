// Exercise 12.7, page 579
//
// Redo the previous exercise, this time using shared_ptr.

#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> make_int_vector() {
  return std::make_shared<std::vector<int>>();
}

void read_into_vector_from_stdin(std::shared_ptr<std::vector<int>> int_vec_p) {
  int tmp;
  while (std::cin >> tmp)
    int_vec_p->push_back(tmp);
}

void print_vector_to_stdin(std::shared_ptr<std::vector<int>> int_vec_p) {
  for (auto n : *int_vec_p) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[argc])
{
  std::shared_ptr<std::vector<int>> int_vec_p = make_int_vector();
  read_into_vector_from_stdin(int_vec_p);
  print_vector_to_stdin(int_vec_p);
  int_vec_p = nullptr;

  return 0;
}


