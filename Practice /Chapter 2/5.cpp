#include <iostream>
#include <cmath>

int main()
{
  double radius, vm;
  std::cout << "Enter radius of a sphere: ";
  std::cin >> radius;
  vm = 4.0 / 3.0 * M_PI * radius * radius * radius;
  std::cout << "The volume is " << vm << "\n";
  return 0;
}