// program qe konverton numrat ne fjale. Limit deri ne 100000

// 123 --> 100 20 3

#include <iostream>
#include <string>

int main()
{
  std::cout << "Enter your number: ";
  std::string input;
  std::cin >> input;

  for (int i = 0; i < input.length(); i++)
  {
    std::cout << input[i];

    for (int j = 0; j < input.length() - 1 - i; j++)
    {
      std::cout << "0";
    }

    std::cout << "\n";
  }

  return 0;
}