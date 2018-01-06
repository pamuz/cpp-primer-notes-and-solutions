#include "TextQuery.h"

void run_queries(std::ifstream &infile) {
  TextQuery tq(infile);

  while (true) {
    std::cout << "enter word to look for, or q to quit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q") break;
    print(std::cout, tq.query(s)) << std::endl;
  }
}

int main(int argc, char *argv[argc])
{
  if (argc < 2) {
    std::cout << "Usage: ./run-queries <path-to-text-file>" << std::endl;
    return 1;
  }

  std::ifstream file(argv[1]);
  run_queries(file);
  return 0;
}

