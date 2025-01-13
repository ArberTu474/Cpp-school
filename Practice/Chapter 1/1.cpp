// 1. Write a C++ program that reads in two integers and then outputs both
// their sum and their product.

#include <iostream>

int main()
{
  int number_1, number_2;
  std::cout << "Enter your first number: ";
  std::cin >> number_1;

  std::cout << "Enter your second number: ";
  std::cin >> number_2;

  std::cout << "Sum: " << number_1 + number_2 << "\n"
            << "Product: " << number_1 * number_2 << "\n";

  return 0;
}