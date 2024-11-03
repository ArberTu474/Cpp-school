// 2. Powers of numbers can be calculated by multiplying the number by itself
// for as many times as the value of the exponent. For example, 2 raised to
// the power 4 can be calculated by multiplying 2 by itself 4 times to get 16.
// Write a program that:
// 1. inputs a double as the base number and an int as the exponent;
// 2. multiplies the base number by itself using a loop that repeats for the
// number of times in the int;
// 3. outputs the exponential value calculated.
// Use an if statement for the special case where the output is 1 if the int
// value is 0. For a more challenging version, deal with the case where the
// exponent is negative.

#include <iostream>
#include <cmath>

int main()
{
  std::cout << "Enter the base: ";
  double base;
  std::cin >> base;

  std::cout << "Enter exponent: ";
  int exponent;
  std::cin >> exponent;

  double result = 1.0;
  if (base == 0)
  {
    std::cout << "Error\n";
  }
  else
  {
    if (exponent == 0)
    {
      result = 1;
    }
    else if (exponent < 0)
    {
      double power = 1.0;
      for (int i = 0; i < std::abs(exponent); i++)
      {
        power *= base;
      }

      result = 1.0 / power;
    }
    else
    {
      for (int i = 0; i < exponent; i++)
      {
        result *= base;
      }
    }

    std::cout << result << "\n";
  }
  return 0;
}