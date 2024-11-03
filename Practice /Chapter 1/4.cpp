// 4. Write a program that allows the user to enter a time in seconds and then
// outputs how far an object would drop if it is in freefall for that length of
// time. Assume that the object starts at rest, there is no friction or resistance
// from air, and there is a constant acceleration of 9.89m/s^2 due to
// gravity. Use the equation:
// distance = (acceleration * time^2) / 2

// You should first compute the product and then divide.

#include <iostream>
#include <iomanip>

int main()
{
  const double acceleration = 9.80665;

  std::cout << "Enter the time: ";
  double time;
  std::cin >> time;

  double distance = (acceleration * time * time) / 2.0;

  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  std::cout << "The object travels: " << distance << " m.\n";

  return 0;
}