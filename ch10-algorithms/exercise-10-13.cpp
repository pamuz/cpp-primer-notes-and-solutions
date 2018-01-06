// Exercise 10.13, page 488
//
// The library defines an algorithm named partition that takes a
// predicate and partitions the container so that values for which the
// predicate is true appear in the first part and those for which the
// predicate is false appear in the second part. The algorithm returns
// an iterator just past the last element for which the predicate
// returned true. Write a function that takes a string and returns a
// bool indicating whether the string has five characters or more. Use
// that function to partition words. Print the elements that have five
// or more characters.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool has_less_than_5_chars(const std::string str) {
  return str.size() < 5;
}


int main(int argc, char *argv[argc])
{
  std::vector<std::string> words = { "some", "words", "in", "this", "vector",
                                     "have", "five", "or", "more", "characters",
                                     "in", "them", "making", "it", "possible",
                                     "to", "partition" };

  auto first_of_five_or_more_chars = std::partition(words.begin(), words.end(), has_less_than_5_chars);

  auto w = first_of_five_or_more_chars;
  while (w != words.end()) {
    std::cout << *w << " ";
    ++w;
  }
  std::cout << std::endl;
  
  return 0;
}
