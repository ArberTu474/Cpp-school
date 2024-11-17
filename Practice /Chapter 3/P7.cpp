// The value e^x can be approximated by the sum
// 1 + x^1/1! + x^2/2! + x^3/3! + ... + x^n/n!

// Write a program that takes a value x as input and outputs this sum for n taken
// to be each of the values 1 to 100. The program should also output e x calculated
// using the predefined function exp. The function exp is a predefined function
// such that exp(x) returns an approximation to the value e x. The function exp
// is in the library with the header file cmath. Your program should repeat the
// calculation for new values of x until the user says she or he is through.
// Use variables of type double to store the factorials or you are likely to
// produce integer overflow (or arrange your calculation to avoid any direct
// calculation of factorials). 100 lines of output might not fit comfortably
// on your screen. Output the 100 output values in a format that will fit all
// 100 values on the screen. For example, you might output 10 lines with
// 10 values on each line.

#include <iostream>
#include <cmath>

int main()
{
  std::cout << "Eneter a value for x: ";
  double x;
  std::cin >> x;

  double sum = 1.0;
  double term = 1.0;

  for (int i = 1; i <= 100; i++)
  {
    std::printf("%.10f\t", sum);
    term *= x / i;
    sum += term;

    if (i % 10 == 0)
    {
      std::cout << "\n";
    }
  }
  std::cout << "\n"
            << sum;
  std::cout << "\n"
            << exp(x) << "\n";
  return 0;
}