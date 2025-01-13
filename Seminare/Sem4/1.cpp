// nje funksion i clli gjen fuqine e nje numri natyror ne baze dhe eksponent

#include <iostream>

int power(int base, int exp)
{
  if (exp == 0)
  {
    return 1;
  }

  int result = 1;
  for (int i = 0; i < exp; i++)
  {
    result *= base;
  }
  return result;
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