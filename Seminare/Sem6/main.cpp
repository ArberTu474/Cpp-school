// Design and implement a class day Type that implements the day of the week in a program. 
// The class day Type should store the day, such as Sun for Sunday. 
// The program should be able to perform the following operations on an object of type dayType:

// a. Set the day.

// b. Print the day.

// c. Return the day.

// d. Return the next day.

// e. Return the previous day.

// f. Calculate and return the day by adding certain days to the current day
// For example, if the current day is Monday and we add 4 days, the day to be returned is Friday.
// Similarly, if today is Tuesday and we add 13 days, the day to be returned is Monday.

// g. Add the appropriate constructors.

#include <iostream>
#include <string>

enum Days
{
  Mon,
  Tue,
  Wed,
  Thur,
  Fri,
  Sat,
  Sun
};

class dayType
{
private:
  enum Days day;
  enum Days week[7] = {Mon, Tue, Wed, Thur, Fri, Sat, Sun};

public:
  dayType(Days day)
  {
    this->day = day;
  }

  void set_day(Days day)
  {
    this->day = day;
  }

  Days get_day()
  {
    return day;
  }

  void print_day()
  {
    switch (day)
    {
    case Mon:
      std::cout << "Monday";
      break;
    case Tue:
      std::cout << "Tuesday";
      break;
    case Wed:
      std::cout << "Wednesday";
      break;
    case Thur:
      std::cout << "Thursday";
      break;
    case Fri:
      std::cout << "Friday";
      break;
    case Sat:
      std::cout << "Saturday";
      break;
    case Sun:
      std::cout << "Sunday";
      break;

    default:
      break;
    }
  }

  void print_day(Days day)
  {
    switch (day)
    {
    case Mon:
      std::cout << "Monday";
      break;
    case Tue:
      std::cout << "Tuesday";
      break;
    case Wed:
      std::cout << "Wednesday";
      break;
    case Thur:
      std::cout << "Thursday";
      break;
    case Fri:
      std::cout << "Friday";
      break;
    case Sat:
      std::cout << "Saturday";
      break;
    case Sun:
      std::cout << "Sunday";
      break;

    default:
      break;
    }
  }

  Days next_day()
  {
    if (day == Sun)
    {
      return Mon;
    }
    else
    {
      return week[day + 1];
    }
  }

  Days previous_day()
  {
    if (day == Mon)
    {
      return Sun;
    }
    else
    {
      return week[day - 1];
    }
  }

  Days after(int days_after)
  {
    return week[(day + days_after) % 7];
  }
};

int main()
{
  dayType day1(Tue);

  day1.print_day(day1.after(13));

  return 0;
}
