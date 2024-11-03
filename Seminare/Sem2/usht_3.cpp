// Dsh shkruani nje app qe i kerkon perdoruesit qe te vendos vlereat e nje thyese ne formen `a/b + c/d`
// Gjeni resultation ne po te njejten forme duke perdorur nje strukture per thyesat

// Tip: find index of /

#include <iostream>
#include <string>
#include <numeric>

struct Fraction
{
  int numerator;
  int denominator;
};

// 123/34
// 012345
int main()
{
  std::string input;

  // Get the first fraction
  std::cout << "Enter your first fraction: ";
  std::cin >> input;
  int slesh_index = input.find("/");

  Fraction fra_1;
  fra_1.numerator = std::stoi(input.substr(0, slesh_index));
  fra_1.denominator = std::stoi(input.substr(slesh_index + 1, input.length() - slesh_index - 1));

  // Get the second fraction
  std::cout << "Enter your second fraction: ";
  std::cin >> input;
  slesh_index = input.find("/");

  Fraction fra_2;
  fra_2.numerator = std::stoi(input.substr(0, slesh_index));
  fra_2.denominator = std::stoi(input.substr(slesh_index + 1, input.length() - slesh_index - 1));

  // Calculate the result
  Fraction fra_result;
  fra_result.denominator = std::lcm(fra_1.denominator, fra_2.denominator);
  fra_result.numerator = (fra_result.denominator / fra_1.denominator * fra_1.numerator) +
                         (fra_result.denominator / fra_2.denominator * fra_2.numerator);

  // Format the result fraction
  if (fra_result.numerator > fra_result.denominator)
  {
    int full_part = fra_result.numerator / fra_result.denominator;
    fra_result.numerator = fra_result.numerator - fra_result.denominator * full_part;
    std::cout << "\nResult: " << full_part << " " << fra_result.numerator << "/" << fra_result.denominator << "\n";
  }
  else
  {
    std::cout << "\nResult: " << fra_result.numerator << "/" << fra_result.denominator << "\n";
  }

  return 0;
}