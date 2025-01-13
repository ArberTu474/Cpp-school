// An approximate value of pi can be calculated using the series given below:
// pi = 4 [ 1 – 1/3 + 1/5 – 1/7 + 1/9 ... + ((–1)n)/(2n + 1) ]
// Write a C++ program to calculate the approximate value of pi using this
// series. The program takes an input n that determines the number of terms
// in the approximation of the value of pi and outputs the approximation.
// Include a loop that allows the user to repeat this calculation for new
// values n until the user says she or he wants to end the program.

#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
  std::cout << "Enter number of terms: ";
  int n;
  std::cin >> n;

  double sum = 0.0;

  for (int i = 0; i < n; i++)
  {
    double term = (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
    sum += term;
  }

  sum *= 4;

  std::cout << "\nApproximated Pi value using " << n << " terms: "
            << sum << "\n";
  std::cout << "\nPi value Using M_PI: "
            << M_PI << "\n";

  return 0;
}