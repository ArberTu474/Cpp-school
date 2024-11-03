// 7. It is difficult to make a budget that spans several years, because prices are
// not stable. If your company needs 200 pencils per year, you cannot simply
// use this year’s price as the cost of pencils 2 years from now. Because of
// inflation the cost is likely to be higher than it is today. Write a program
// to gauge the expected cost of an item in a specified number of years. The
// program asks for the cost of the item, the number of years from now that
// the item will be purchased, and the rate of inflation. The program then
// outputs the estimated cost of the item after the specified period. Have the
// user enter the inflation rate as a percentage, like 5.6 (percent). Your program
// should then convert the percent to a fraction, like 0.056, and should use a
// loop to estimate the price adjusted for inflation. (Hint: This is similar to com-
// puting interest on a charge card account, which was discussed in this chapter.)

// 10:39

#include <iostream>

int main()
{
  double item_cost;
  double item_inflation;
  int years;

  std::cout << "Enter the cost for the item: ";
  std::cin >> item_cost;

  std::cout << "Enter the items inflation rate: ";
  std::cin >> item_inflation;

  std::cout << "Enter the number of years you want to buy this item: ";
  std::cin >> years;

  item_inflation = item_inflation / 100.0 ;

  for (int i = 1; i <= years; i++)
  {
    item_cost += item_cost * item_inflation;
  }

  std::printf("\nTotal:\t%8.2lf\n", item_cost);
  return 0;
}