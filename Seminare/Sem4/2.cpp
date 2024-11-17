// me rukursiv.

#include <iostream>

int power(int base, int exp)
{
  if (exp == 0)
  {
    return 1;
  }
  return base * power(base, exp - 1);
}

int main()
{
  std::cout << "Enter base: ";
  int base;
  std::cin >> base;

  std::cout << "Enter exp: ";
  int exp;
  std::cin >> exp;

  std::cout << power(base, exp) << "\n";

  return 0;
}