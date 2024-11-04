// Nje program i cili gjen dhe afishon shumen e shifrave te nje numri te plote

#include <iostream>
#include <string>

int main()
{
  std::cout << "Enter your number: ";
  std::string input;
  std::cin >> input;

  int sum = 0;
  for (int i = 0; i < input.length(); i++)
  {
    if (isdigit(input[i]))
    {
      sum += input[i] - '0';
    }
    else
    {
      std::cout << "Error\n";
      return 1;
    }
  }

  std::cout << sum << "\n";
  return 0;
}