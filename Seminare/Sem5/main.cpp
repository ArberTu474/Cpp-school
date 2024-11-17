#include <iostream>
#include <string>

int main()
{
  std::string firstInput;
  std::string secondInput;

  std::cout << "Enter the first line of text: ";
  std::getline(std::cin, firstInput); // Reads the first line

  std::cout << "Enter the second line of text: ";
  std::getline(std::cin, secondInput); // Reads the second line

  std::cout << "First input: " << firstInput << std::endl;
  std::cout << "Second input: " << secondInput << std::endl;

  return 0;
}
