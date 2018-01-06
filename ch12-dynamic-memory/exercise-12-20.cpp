// Exercise 12.20, page 594
//
// Write a program that reads an input file a line at a time into a
// StrBlob and uses a StrBlobPtr to print each element in that
// StrBlob.

#include <iostream>
#include <fstream>
#include "StrBlob.h"

int main(int argc, char *argv[argc])
{
  if (argc < 2) {
    std::cout << "Usage: ./exercise-12-19 <path-to-txt-file>" << std::endl;
    return 1;
  }

  std::ifstream input_file(argv[1]);
  std::string read_from_file;

  StrBlob str_blob;

  while (std::getline(input_file, read_from_file)) {
    str_blob.push_back(read_from_file);
  }

  auto str_blob_curr = str_blob.begin();
  auto str_blob_end = str_blob.end();
  while (!str_blob_curr.eq(str_blob_end)) {
    std::cout << str_blob_curr.deref() << std::endl;
    str_blob_curr.incr();
  }
  
  return 0;
}

