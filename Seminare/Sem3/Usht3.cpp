// nr i fundit te thjehst qe gjendet deri ne nje numer n limit qe jepet nga perdoruesi

#include <iostream>

bool thjeshte(int num)
{
  for (int i = 2; i < num / 2; i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  std::cout << "Vendos numrin: ";
  int num;
  std::cin >> num;

  for (int i = num; i > 1; i--)
  {
    if (thjeshte(i))
    {
      std::cout << i << "\n";
      break;
    }
  }

  return 0;
}