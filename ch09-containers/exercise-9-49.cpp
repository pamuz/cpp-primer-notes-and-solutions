// Exercise 9.49, page 466
//
// A letter has an ascender if, as with d or f, part of the letter
// extends above the middle of the line. A letter has a descender if,
// as with p or g, part of the letter extends below the line. Write a
// program that reads a file containing words and reports the longest
// word that contains neither ascenders nor descenders.

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[argc])
{
  // Read words
  std::string input_word;
  std::vector<std::string> words;

  while (std::cin >> input_word) {
    words.push_back(input_word);
  }

  std::string longest_target_word;
  int longest_target_word_size = 0;

  std::string disqualifiers = "dfpqg";

  for (auto a_word : words) {
    bool is_disqualified = a_word.find_first_of(disqualifiers) != std::string::npos;

    if (!is_disqualified) {
      bool is_longer_than_previous_longest = a_word.size() > longest_target_word_size;
      if (is_longer_than_previous_longest) {
        longest_target_word_size = a_word.size();
        longest_target_word = a_word;
      }
    }
  }

  if (longest_target_word_size == 0) {
    std::cout << "All words given had ascenders or descenders. None passed.";
  } else {
    std::cout << "The longest word without ascenders or descender was: "
              << longest_target_word << std::endl;
  }
  
  return 0;
}

