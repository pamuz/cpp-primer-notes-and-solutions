// Exercise 11.3, page 530
//
// Exercise 11.3: Write your own version of the word-counting program.

#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, char *argv[argc])
{
  std::unordered_map<std::string, size_t> word_counts;

  std::string word_read;
  while(std::cin >> word_read) {
    ++word_counts[word_read];
  }

  for (const auto &wc : word_counts) {
    std::cout << wc.first << " appears " << wc.second << " times." << std::endl;
  }
  
  return 0;
}

