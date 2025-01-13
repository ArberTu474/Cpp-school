// A metric ton is 35,273.92 ounces. Write a program that will read the weight
// of a package of breakfast cereal in ounces and output the weight in metric
// tons as well as the number of boxes needed to yield 1 metric ton of cereal.
// Your program should allow the user to repeat this calculation as often as
// the user wishes.

#include <iostream>

int main()
{
  const double METRIC_TON_IN_OUNCES = 35273.92;
  double package_weight;
  char choice;

  do
  {
    std::cout << "Enter the weight of a package of cereal: ";
    std::cin >> package_weight;

    std::cout << "Weight of the package in metric ton: " << package_weight / METRIC_TON_IN_OUNCES << "\n";
    std::cout << "Number of boxes needed to hold 1 metric ton: " << (int)(METRIC_TON_IN_OUNCES / package_weight) + 1 << "\n";

    // Asks the user if they want to continue
    std::cout << "\nDo you want to continue(y/n): ";
    std::cin >> choice;
  } while (tolower(choice) == 'y');

  std::cout << "End\n";

  return 0;
}