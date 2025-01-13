// 2. A store sells carpets for $2.75 per meter. If a customer buys more than
// 10 m of carpet, they get a discount of 15% on every additional meter of
// carpet they purchase. Write a program that inputs the carpet length that a
// user wishes to buy, stores the value in a double variable, and then calcu-
// lates and outputs the total cost of the carpet.

#include <iostream>

int main()
{
  const double COST_PER_METER = 2.75;
  const double DISCOUNT = 0.15;
  const int DISCOUNT_CAP = 10;

  std::cout << "Enter the length of the carpet: ";
  double length;
  std::cin >> length;

  double cost = 0.0;
  if (length > 10)
  {
    cost = 10 * COST_PER_METER + ((length - 10) * 2.75 * (1 - DISCOUNT));
  }
  else
  {
    cost = length * COST_PER_METER;
  }

  std::printf("It costs: $%.2lf\n", cost);

  return 0;
}