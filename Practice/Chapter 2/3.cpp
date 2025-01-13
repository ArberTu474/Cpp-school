// 3. Many treadmills output the speed of the treadmill in miles per hour
// (mph) on the console, but most runners think of speed in terms of a
// pace. A common pace is the number of minutes and seconds per mile
// instead of mph.
// Write a program that starts with a quantity in mph and converts the
// quantity into minutes and seconds per mile. As an example, the proper
// output for an input of 6.5 mph should be 9 minutes and 13.8 seconds per
// mile. If you need to convert a double to an int, which will discard any value
// after the decimal point, then you may use
// intValue = static_cast<int>(dblVal);

#include <iostream>

int main()
{
  std::cout << "Enter the speed in mph: ";
  double spped_mph;
  std::cin >> spped_mph;

  double pace_mspm = 1.0 / spped_mph;

  int minutes = static_cast<int>(pace_mspm * 60);
  double seconds = (pace_mspm * 60 - minutes) * 60;

  std::printf("%d minutes %.2lf seconds\n", minutes, seconds);

  return 0;
}