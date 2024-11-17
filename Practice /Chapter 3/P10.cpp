// Computer file sizes are measured in units of bytes, or higher units like
// kilobytes, megabytes, or gigabytes. Bytes, kilobytes, megabytes, and
// gigabytes are related by the following:
// a. One kilobyte is equal to 1024 bytes.
// b. One megabyte is equal to 1024 kilobytes.
// c. One gigabyte is equal to 1024 megabytes.
// Write a program that lets the user convert the size of a file from gigabytes,
// megabytes, or kilobytes to bytes. The program should prompt the user to
// enter the size of the file and the units the file size is being measured in,
// with G for gigabytes, M for Megabytes and K for Kilobytes. The program
// should then output the size of the file in each of the corresponding
// smaller file size types. For example, if the user enters the file size in
// megabytes, the program should output the file size in kilobytes and bytes.

#include <iostream>
#include <iomanip>

int main()
{
  std::cout << "Enter the file size: ";
  double file_size;
  std::cin >> file_size;
  std::cout << "Enter the file unit: ";
  char file_unit;
  std::cin >> file_unit;
  file_unit = tolower(file_unit);

  if (file_unit == 'g')
  {
    double size_in_mb = file_size * 1024;
    double size_in_kb = size_in_mb * 1024;
    double size_in_b = size_in_kb * 1024;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Mb: " << size_in_mb << "\n";
    std::cout << "Kb: " << size_in_kb << "\n";
    std::cout << "B: " << size_in_b << "\n";
  }
  else if (file_unit == 'm')
  {
    double size_in_kb = file_size * 1024;
    double size_in_b = size_in_kb * 1024;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Kb: " << size_in_kb << "\n";
    std::cout << "B: " << size_in_b << "\n";
  }
  else if (file_unit == 'k')
  {
    double size_in_b = file_size * 1024;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "B: " << size_in_b << "\n";
  }
  else
  {
    std::cout << "Enter a valid unit.\n";
  }

  return 0;
}