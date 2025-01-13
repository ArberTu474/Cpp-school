// kontrollon dhe verifikon nese nje numer eshte i thjeshte ose jo

#include <iostream>

int main()
{
  std::cout << "Enter a number: ";
  int num;
  std::cin >> num;
  bool thjeshte = true;
  for (int i = 2; i < num / 2; i++)
  {
    if (num % i == 0)
    {
      std::cout << "Jo numer i thjeshte\n";
      thjeshte = false;
      break;
    }
  }

  std::cout << "I thjehste\n";

  return 0;
}