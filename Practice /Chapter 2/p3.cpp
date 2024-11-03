// Modify your program from Programming Project 2 so that the minimum
// length of carpet that is applicable for the discount, the percent rate of the
// discount, and the cost per meter can be input by the user.

#include <iostream>

int main()
{
  double COST_PER_METER;
  double DISCOUNT;
  int DISCOUNT_CAP;

  std::cout << "Enter the length of the carpet: ";
  double length;
  std::cin >> length;

  std::cout << "Enter the price per meter: ";
  std::cin >> COST_PER_METER;

  std::cout << "Enter the discount amount: ";
  std::cin >> DISCOUNT;

  std::cout << "Enter the minimum length to get a discount: ";
  std::cin >> DISCOUNT_CAP;

  double cost = 0.0;
  if (length > 10)
  {
    cost = 10 * COST_PER_METER + ((length - 10) * 2.75 * (1 - static_cast<double>(DISCOUNT) / 100));
  }
  else
  {
    cost = length * COST_PER_METER;
  }

  std::printf("It costs: $%.2lf\n", cost);

  return 0;
}