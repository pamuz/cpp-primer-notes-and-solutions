// Exercise 11.33, page 555
//
// Implement your own version of the word-transformation
// program.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

std::map<std::string, std::string> build_word_substitutions_map
(std::ifstream &word_substitutions_file) {
  std::map<std::string, std::string> word_substitutions_map;

  std::string word;
  std::string substitution;

  while (word_substitutions_file >> word) {
    std::getline(word_substitutions_file, substitution);
    word_substitutions_map[word] = substitution.substr(1);
  }

  return word_substitutions_map;
}

void substitue_words_and_print(std::ifstream &word_substitutions_file,
                               std::ifstream &file_to_substitue) {
  auto word_substitutions = build_word_substitutions_map(word_substitutions_file);
  std::string line;
  while (std::getline(file_to_substitue, line)) {
    std::stringstream line_stream(line);
    std::string word_that_may_need_substition;
    while (line_stream >> word_that_may_need_substition) {
      if (word_substitutions.find(word_that_may_need_substition) != word_substitutions.end()) {
        std::cout << word_substitutions[word_that_may_need_substition];
      } else {
        std::cout << word_that_may_need_substition;
      }
      std::cout << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char *argv[argc])
{
  if (argc < 3) {
    std::cout << "Usage: ./exercise-11-33 <substitutions-file> <file-to-substitue>"
              << std::endl;
    return 1;
  }

  std::ifstream word_substitutions_file = std::ifstream(argv[1]);
  std::ifstream file_to_substitue = std::ifstream(argv[2]);

  substitue_words_and_print(word_substitutions_file, file_to_substitue);
  
  return 0;
}

