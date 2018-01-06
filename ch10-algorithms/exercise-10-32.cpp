// Exercise 10.32, page 513
//
// Write a program that takes the names of an input file and two
// output files. The input file should hold integers. Using an
// istream_iterator read the input file. Using ostream_iterators,
// write the odd numbers into the first output file. Each value should
// be followed by a space. Write the even numbers into the second
// file. Each of these values should be placed on a separate line.

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

int main(int argc, char *argv[argc])
{
  if (argc < 4) {
    std::cout << "Usage ./exercise-10-32 <path-to-file-with-ints> <path-to-out-file1>"
              << " <path-to-out-file2>" << std::endl;
    return 1;
  }

  std::ifstream file_with_integers(argv[1]);
  std::ofstream odd_numbers_outfile(argv[2]);
  std::ofstream even_numbers_outfile(argv[3]);

  std::istream_iterator<int> file_with_integers_iter(file_with_integers), eof;
  std::ostream_iterator<std::string> odd_numbers_outfile_iter(odd_numbers_outfile);
  std::ostream_iterator<std::string> even_numbers_outfile_iter(even_numbers_outfile);

  std::for_each(file_with_integers_iter, eof,
                [&even_numbers_outfile_iter, &odd_numbers_outfile_iter] (int n) {
                  if (n % 2 == 0) {
                    *even_numbers_outfile_iter++ = std::to_string(n);
                    *even_numbers_outfile_iter++ = "\n";
                  } else {
                    *odd_numbers_outfile_iter++ = std::to_string(n);
                    *odd_numbers_outfile_iter++ = " ";
                  }
                });

  return 0;
}

