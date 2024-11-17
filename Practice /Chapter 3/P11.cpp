// Unfortunately the circuitry is damaged and the digits in the leftmost column
// no longer function. In other words, the digits 1, 4, and 7 do not work. If a
// recipe calls for a temperature that can’t be entered, then you would like to
// substitute a temperature that can be entered. Write a program that inputs a
// desired temperature. The temperature must be between 0 and 999 degrees.
// If the desired temperature does not contain 1, 4, or 7, then output the
// desired temperature. Otherwise, compute the next largest and the next
// smallest temperature that does not contain 1, 4, or 7 and output both.
// For example, if the desired temperature is 450, then the program
// should output 399 and 500. Similarly, if the desired temperature is
// 375, then the program should output 380 and 369.

#include <iostream>
#include <string>

bool contains_unvalid_digits(int temp)
{
  std::string str_temp = std::to_string(temp);

  for (char digit : str_temp)
  {
    if (digit == '1' || digit == '4' || digit == '7')
    {
      return true;
    }
  }

  return false;
}

int find_next_smaller(int temp)
{
  for (int i = temp - 1; i >= 0; i--)
  {
    if (!contains_unvalid_digits(i))
    {
      return i;
    }
  }

  return -1;
}

int find_next_larger(int temp)
{
  for (int i = temp + 1; i <= 999; i++)
  {
    if (!contains_unvalid_digits(i))
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  std::cout << "Enter your desired temeperature: ";
  int desired_temp;
  std::cin >> desired_temp;

  if (desired_temp < 0 || desired_temp > 999)
  {
    std::cout << "Enter a temperature between 0 and 999.\n";
    return 1;
  }

  if (!contains_unvalid_digits(desired_temp))
  {
    std::cout << "Temperature " << desired_temp << " can be used.\n";
  }
  else
  {

    int next_smaller = find_next_smaller(desired_temp);
    int next_larger = find_next_larger(desired_temp);

    std::cout << "The valid smaller temp is: " << (next_smaller != -1 ? std::to_string(next_smaller) : "None") << "\n";
    std::cout << "The valid larger temp is: " << (next_larger != -1 ? std::to_string(next_larger) : "None") << "\n";
  }

  return 0;
}