// Write a program that finds and prints all of the prime numbers between 3
// and 100. A prime number is a number such that 1 and itself are the only
// numbers that evenly divide it (for example, 3, 5, 7, 11, 13, 17, …).

#include <iostream>
#include <cmath>

int main()
{
  bool is_prime(int num);

  for (int i = 3; i <= 100; i++)
  {
    if (is_prime(i))
    {
      std::cout << i << " ";
    }
  }

  std::cout << "\n";

  return 0;
}

bool is_prime(int num)
{
  for (int i = 2; i < std::sqrt(num); i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }

  return true;
}