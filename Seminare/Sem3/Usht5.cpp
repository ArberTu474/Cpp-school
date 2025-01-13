// perllogarisni prodhimin e dy numrave te plote pa perdorur *

#include <iostream>

int main()
{
  int num_1, num_2;

  std::cout << "Enter num1: ";
  std::cin >> num_1;

  std::cout << "Enter num2: ";
  std::cin >> num_2;

  int product = 0;
  for (int i = 1; i <= num_2; i++)
  {
    product += num_1;
  }

  std::cout << product << "\n";

  return 0;
}