// Take as input dd/mm/yyyyand save it in a struct
// Output dd:mm:yyyy;

// dd/mm/yyyy
// 0123456789

#include <iostream>
#include <string>
using namespace std;

struct Date
{
  int year;
  int month;
  int day;
};

int main()
{
  cout << "Enter a date in this format (dd/mm/yyyy): ";
  string input;

  cin >> input;
  Date formatted_date;
  formatted_date.day = stoi(input.substr(0, 2));
  formatted_date.month = stoi(input.substr(3, 2));
  formatted_date.year = stoi(input.substr(6, 4));

  cout << "\nFormatted Date:\n";
  cout << formatted_date.day << ":"
       << formatted_date.month << ":"
       << formatted_date.year << "\n";

  return 0;
}
