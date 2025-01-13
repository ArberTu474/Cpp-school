// 14. Computers normally treat time as the number of seconds from an arbitrary
// starting point called an epoch. Write a C++ program that asks the user for
// the current hour of the day (from 0 to 23), the current minute of the hour
// (from 0 to 59) and the current second of the minute (from 0 to 59). Use
// the user’s input to calculate the number of seconds since midnight that
// their time represents. If the user enters an invalid input, like 67 minutes
// for the current minutes in the hour, then ask them for that value again
// until they enter a correct value. Sample input and output is shown below.
// Enter the hour of the day: 3
// Enter the minutes of the hour: 45
// Enter the seconds passed in the current minute: 25
// Enter the seconds passed in the current minute: 90
// Enter the seconds passed in the current minute: 3
// The time in seconds since midnight is: 45903

#include <iostream>

int main()
{
  int hours;
  do
  {
    std::cout << "\nEnter the hour of the day: ";
    std::cin >> hours;

  } while (!(hours >= 0 && hours <= 23));

  int minutes;
  do
  {
    std::cout << "\nEnter the minutes of the hour: ";
    std::cin >> minutes;

  } while (!(minutes >= 0 && minutes <= 59));

  int seconds;
  do
  {
    std::cout << "\nEnter the seconds passed in the current minute: ";
    std::cin >> seconds;

  } while (!(seconds >= 0 && seconds <= 59));

  int time_since_midnight = (hours * 3600) + (minutes * 60) + seconds;

  std::cout << "The time in seconds since midnight is: " << time_since_midnight << "\n"; 
  return 0;
}