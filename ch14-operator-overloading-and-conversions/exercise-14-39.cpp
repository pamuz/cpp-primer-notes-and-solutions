// Exercise 14.38, page 711
//
// Revise the previous program to report the count of words that are
// sizes 1 through 9 and 10 or more.

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

  int words_with_1_through_9_chars = 0;
  int words_with_more_than_10_chars = 0;

  StrOfLenMatcher bound_decider(1, 9);

  std::string a_word;

  while(input_file >> a_word) {
    if (bound_decider(a_word))
      ++words_with_1_through_9_chars;
    else
      ++words_with_more_than_10_chars;
  }

  std::cout << words_with_1_through_9_chars << " words are within 1-9 chars." << std::endl;
  std::cout << words_with_more_than_10_chars << " words are with more than 10 chars." << std::endl;
  
  return 0;
}
