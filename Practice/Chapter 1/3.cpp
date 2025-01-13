// 3. Write a program that allows the user to enter a number of quarters, dimes,
// and nickels and then outputs the monetary value of the coins in cents. For
// example, if the user enters 2 for the number of quarters, 3 for the number
// of dimes, and 1 for the number of nickels, then the program should
// output that the coins are worth 85 cents.

#include <iostream>

int main()
{
  int quarters, dimes, nickels;

  std::cout << "Enter your quarters: ";
  std::cin >> quarters;

  std::cout << "Enter your dimes: ";
  std::cin >> dimes;

  std::cout << "Enter your nickels: ";
  std::cin >> nickels;

  int cents = quarters * 25 + dimes * 10 + nickels * 5;

  std::cout << "You have: " << cents << " cents\n";

  return 0;
}