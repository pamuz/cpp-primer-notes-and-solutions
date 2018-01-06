// Exercise 11.4, page 530
//
// Extend your program to ignore case and punctuation. For example,
// “example.” “example,” and “Example” should all increment the same
// counter.

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <iterator>

const std::string punctuation = ",!.?;:";

auto is_punctuation = [] (char c) -> bool {
  return punctuation.find(c) != std::string::npos; };

int main(int argc, char *argv[argc])
{
  std::unordered_map<std::string, size_t> word_counts;

  std::string word_read;
  std::string clean_word;

  while(std::cin >> word_read) {
    clean_word.clear();

    std::transform(word_read.cbegin(), word_read.cend(),
                   std::back_inserter(clean_word),
                   [] (char c) -> char { return std::tolower(c); });

    clean_word.erase(std::remove_if(clean_word.begin(), clean_word.end(),
                                    is_punctuation),
                     clean_word.end());

    ++word_counts[clean_word];
  }

  for (const auto &wc : word_counts) {
    std::cout << wc.first << " appears " << wc.second << " times." << std::endl;
  }
  
  return 0;
}

