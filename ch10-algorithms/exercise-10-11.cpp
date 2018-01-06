// Exercise 10.11, page 488
//
// Write a program that uses stable_sort and isShorter to sort a
// vector passed to your version of elimDups. Print the vector to
// verify that your program is correct.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool is_shorter(const std::string &left, const std::string &right) {
  return left.size() < right.size();
}

void eliminate_duplicates(std::vector<std::string> &words) {
  std::stable_sort(words.begin(), words.end(), is_shorter);

  // Rearrange so that unique elements appear first
  auto first_repeated_p = std::unique(words.begin(), words.end());

  auto repeat = first_repeated_p;
  while(repeat != words.cend()) {
    words.erase(repeat);
  }
}

int main(int argc, char *argv[argc])
{
  std::vector<std::string> words = { "fox", "jumps", "over", "quick", "red",
                                     "red", "slow", "the", "the", "turtle" };


  eliminate_duplicates(words);

  for (auto w : words) {
    std::cout << w << " ";
  }
  std::cout << std::endl;

  return 0;
}
