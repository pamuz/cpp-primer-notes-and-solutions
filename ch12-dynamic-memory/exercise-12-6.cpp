// Exercise 12.6, page 579
//
// Write a function that returns a dynamically allocated vector of
// ints. Pass that vector to another function that reads the standard
// input to give values to the elements. Pass the vector to another
// function to print the values that were read. Remember to delete the
// vector at the appropriate time.

#include <iostream>
#include <vector>

std::vector<int> *make_int_vector() {
  return new std::vector<int>();
}

void read_into_vector_from_stdin(std::vector<int> * const int_vec_p) {
  int tmp;
  while (std::cin >> tmp)
    int_vec_p->push_back(tmp);
}

void print_vector_to_stdin(const std::vector<int> * const int_vec_p) {
  for (auto n : *int_vec_p) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[argc])
{
  std::vector<int> *int_vec_p = make_int_vector();
  read_into_vector_from_stdin(int_vec_p);
  print_vector_to_stdin(int_vec_p);
  delete int_vec_p;
  int_vec_p = nullptr;

  return 0;
}

