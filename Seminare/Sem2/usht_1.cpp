#include <iostream>
#include <cmath>

struct Koha
{
  int oret;
  int minutat;
  int sekontat;
};

using namespace std;

int main()
{
  Koha time;

  cout << "Enter the numbers of hours: ";
  cin >> time.oret;

  cout << "Enter the numbers of minutes: ";
  cin >> time.minutat;

  cout << "Enter the numbers of seconds: ";
  cin >> time.sekontat;

  int time_in_seconds = time.oret * 3600 + time.minutat * 60 + time.sekontat;

  cout << "Time in seconds: " << time_in_seconds << "\n";

  return 0;
}
