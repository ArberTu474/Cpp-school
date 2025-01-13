// 10. Write a program that reads in int values from the user until they enter
// a negative number like -1. Once the user has finished entering num-
// bers, print out the highest value they’ve entered, the lowest value they’ve
// entered, and the total number of numbers they’ve entered. The negative
// number they entered should not be taken as one of the values entered.

#include <iostream>
#include <climits>

int main()
{
  int max = INT_MIN;
  int min = INT_MAX;
  int number_count = 0;
  int current_number;

  do
  {
    std::cout << "Enter a number: ";
    std::cin >> current_number;
    if (current_number < 0)
    {
      break;
    }
    number_count++;

    // Control if the current number is the max number
    if (current_number > max)
    {
      max = current_number;
    }

    // Control if the current number is the min number
    if (current_number < min)
    {
      min = current_number;
    }

  } while (current_number > 0);

  if (number_count == 0)
  {
    std::cout << "No positive numbers were entered\n";
  }
  else
  {
    std::cout << "\n";
    std::cout << "Max: " << max << "\n";
    std::cout << "Min: " << min << "\n";
    std::cout << "Number count: " << number_count << "\n";
  }

  return 0;
}