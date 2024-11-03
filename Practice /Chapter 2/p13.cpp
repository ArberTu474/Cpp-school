// Write a program to calculate the slope between two points x1, y1 and x2, y2.
// The points should be entered as four double values in the order x1, y1, x2,
// and y2.
//
// Output the calculated slope value.
// Use this value to output the equation of the line in the form
// y = mx + c
// You can calculate the value of c from one of the pair of points entered as
// input.

#include <iostream>

int main()
{
  double x1, y1, x2, y2;

  // Get input for points
  std::cout << "Enter the coordinates of the first point (x1 y1): ";
  std::cin >> x1 >> y1;
  std::cout << "Enter the coordinates of the second point (x2 y2): ";
  std::cin >> x2 >> y2;

  if (x1 == x2)
  {
    std::cout << "The slope is undefined (vertical line)." << "\n";
  }
  else
  {
    double slope = (y2 - y1) / (x2 - x1);

    // Out the function for these two points using
    // y = mx + c
    double c = y1 - slope * x1;

    if (c > 0)
    {
      std::printf("y = %.3lfx %.3lf\n", slope, c);
    }
    else
    {
      std::printf("y = %.3lfx %.3lf\n", slope, c);
    }
  }
  return 0;
}