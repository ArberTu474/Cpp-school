// It is important to consider the effect of thermal expansion when building a
// structure that must withstand changes in temperature. For example, a metal
// beam will expand in hot temperatures. The additional stress could cause
// the structure to fail. Similarly, a material will contract in cold temperatures.
// The linear change in length of a material if it is allowed to freely expand is
// described by the following equation:
// L∆ = aL0T∆
// Here, L0 is the initial length of the material in meters, LΔ is the displacement
// in meters, TΔ is the change in temperature in Celsius, and a is a coefficient
// for linear expansion.
// 		 Write a program that inputs a, LΔ, and TΔ, then calculates and outputs the
// linear displacement. If the displacement is positive then output that “The
// material will expand by” the displacement in meters. If the displacement is
// negative then output that “The material will contract by” the displacement
// in meters. You shouldn’t output the displacement as a negative number.
// Here are some values for a for different materials.
// Aluminum
// Copper
// Glass
// Steel
// 2.31 × 10−5
// 1.70 × 10−5
// 8.50 × 10−6
// 1.20 × 10−5

#include <iostream>
#include <cmath>

int main()
{
  double a, L0, T_delta;

  std::cout << "Enter the coefficient of linear expansion (a): ";
  std::cin >> a;
  std::cout << "Enter the initial length of the material in meters (L0): ";
  std::cin >> L0;
  std::cout << "Enter the change in temperature in Celsius (TΔ): ";
  std::cin >> T_delta;

  double L_delta = a * L0 * T_delta;

  if (L_delta > 0)
  {
    std::cout << "The material will expand by " << L_delta << " meters.\n";
  }
  else
  {
    std::cout << "The material will expand by " << std::abs(L_delta) << " meters.\n";
  }

  return 0;
}