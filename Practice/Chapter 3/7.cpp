// A taxicab company calculates charges using a fixed $3.20 hire charge, a
// $2.05-per-kilometer charge for the distance covered, and an additional
// $0.95-per-minute charge based on the duration of the journey, in minutes. If
// the journey starts between 2300 and 0600 hours, a 15% surcharge is applied.
// Write a program that asks the user to input the duration of the journey
// (rounded up to the nearest minute), the distance traveled (in kilometers),
// and the journey start time (as a 24-hour single int value). The program
// should then output the fare that should be charged.

#include <iostream>

int main()
{
  const double HIRE_CHARGE = 3.2;
  const double CHARGE_PER_KILOMETER = 2.05;
  const double CHARGE_PER_MINUTE = 0.95;
  const double SUPER_CHARGE_STAR_HOUR = 23;
  const double SUPER_CHARGE_END_HOUR = 6;
  const double SUPER_CHARGE_PERCENT = 15;

  std::cout << "Enter the duration of the journy: ";
  int duration;
  std::cin >> duration;

  std::cout << "Enter the distance of the journy: ";
  int distance;
  std::cin >> distance;

  std::cout << "Enter the journy start time: ";
  int start_time;
  std::cin >> start_time;

  double cost = HIRE_CHARGE + CHARGE_PER_KILOMETER * distance + CHARGE_PER_MINUTE * duration;

  if (start_time >= SUPER_CHARGE_STAR_HOUR || start_time <= SUPER_CHARGE_END_HOUR)
  {
    cost = cost * (SUPER_CHARGE_PERCENT / 100 + 1);
  }

  std::cout << "Cost is: $" << cost << "\n";

  return 0;
}