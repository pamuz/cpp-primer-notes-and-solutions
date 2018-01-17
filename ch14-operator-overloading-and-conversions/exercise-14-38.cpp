// Exercise 14.38, page 711
//
// Write a class that tests whether the length of a given string
// matches a given bound. Use that object to write a program to report
// how many words in an input file are of sizes 1 through 10
// inclusive.

#include <iostream>
#include <string>
#include <fstream>

struct StrOfLenMatcher {
  using sz = std::string::size_type;

  StrOfLenMatcher(sz lb, sz ub): lower_bound(lb), upper_bound(ub) {}
  bool operator()(std::string candidate) {
    return lower_bound <= candidate.size() && candidate.size() <= upper_bound;
  }
private:
  sz lower_bound;
  sz upper_bound;
};


int main(int argc, char *argv[argc])
{
  std::string input_file_path = argv[1];
  std::ifstream input_file(input_file_path);

  int words_within_bounds = 0;

  StrOfLenMatcher bound_decider(1, 10);

  std::string a_word;

  while(input_file >> a_word) {
    if (bound_decider(a_word))
      ++words_within_bounds;
  }

  std::cout << words_within_bounds << " words are within bounds." << std::endl;
  
  return 0;
}
