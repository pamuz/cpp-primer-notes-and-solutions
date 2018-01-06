// Exercise 10.3, page 480
//
// Use accumulate to sum the elements in a vector<int>.

#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char *argv[argc])
{
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int total = std::accumulate(nums.begin(), nums.end(), 0);

  std::cout << "The sum of each element in num is: " << total << std::endl;
  
  return 0;
}
