#include <utility>
#include <iostream>

int main(int argc, char *argv[argc])
{
  int i = 42;
  std::cout << "i = " << i << std::endl;

  int &j = i;
  std::cout << "i = " << i << std::endl;
  std::cout << "j = " << j << std::endl;

  int &&k = std::move(i);
  std::cout << "i = " << i << std::endl;
  std::cout << "j = " << j << std::endl;
  std::cout << "k = " << k << std::endl;
  
  return 0;
}
