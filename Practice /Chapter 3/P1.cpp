// Write a program that computes the cost of a long-distance call. The cost of
// the call is determined according to the following rate schedule:
// a. Any call started between 8:00 am and 6:00 pm, Monday through Friday,
// is billed at a rate of $0.40 per minute.
// b. Any call starting before 8:00 am or after 6:00 pm, Monday through
// Friday, is charged at a rate of $0.25 per minute.
// c. Any call started on a Saturday or Sunday is charged at a rate of $0.15
// per minute.
// The input will consist of the day of the week, the time the call started, and
// the length of the call in minutes. The output will be the cost of the call. The
// time is to be input in 24-hour notation, so the time 1:30 pm is input as
// 13:30
// The day of the week will be read as one of the following pairs of character
// values, which are stored in two variables of type char:
// Mo Tu We Th Fr Sa Su
// Be sure to allow the user to use either uppercase or lowercase letters or a
// combination of the two. The number of minutes will be input as a value
// of type int. (You can assume that the user rounds the input to a whole
// number of minutes.) Your program should include a loop that lets the
// user repeat this calculation until the user says she or he is done.

#include <iostream>
#include <string>

#include <bits/stdc++.h>

int main()
{
  std::string repeat;

  do
  {
    std::cout << "Enter the day of the weeks: ";
    std::string day;
    std::cin >> day;

    std::cout << "Enter the call duration: ";
    int duration;
    std::cin >> duration;

    std::cout << "Enter the call start time: ";
    std::string time;
    std::cin >> time;

    transform(day.begin(), day.end(), day.begin(), ::tolower);

    bool weekday = true;
    if (day == "sa" ||
        day == "su")
    {
      weekday = false;
    }

    int time_in_minutes = std::stoi(time.substr(0, 2)) * 60 + std::stoi(time.substr(3, 2));
    double cost = 0.0;

    // calls between 8 am - 6 pm in week days 08:00 - 18:00
    if (weekday)
    {
      if (time_in_minutes >= 8 * 60 && time_in_minutes <= 18 * 60)
      {
        cost = duration * 0.4;
      }
      else
      {
        cost - duration * 0.25;
      }
    }
    else
    {
      cost = duration * 0.15;
    }

    std::cout << "The cost is: $" << cost << "\n\n";
    std::cout << "Do you want to calculate another call(yes/no): ";
    std::cin >> repeat;

  } while (repeat == "yes" || repeat == "Yes" || repeat == "YES");

  return 0;
}