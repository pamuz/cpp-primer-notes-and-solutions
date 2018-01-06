// Exercise 10.9, page 486
//
// Implement your own version of elimDups. Test your program by
// printing the vector after you read the input, after the call to
// unique, and after the call to erase.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void eliminate_duplicates(std::vector<std::string> &words) {
  std::sort(words.begin(), words.end());

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
