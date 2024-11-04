// Krijo nje makine llogaritese qe merr si input 2 numbra te plote
// dhe nje operator * / + - dhe afishon rezultation

#include <iostream>

using namespace std;

int main()
{
  std::cout << "Enter the first number: ";
  int num_1;
  std::cin >> num_1;
  std::cout << "Enter the second number: ";
  int num_2;
  std::cin >> num_2;

  std::cout << "Enter the operator: ";
  char operatori;
  std::cin >> operatori;

  double result;
  switch (operatori)
  {
  case '+':
    result = num_1 + num_2;
    break;
  case '-':
    result = num_1 - num_2;
    break;
  case '*':
    result = num_1 * num_2;
    break;
  case '/':
    if (num_2 == 0)
    {
      std::cout << "Error\n";
    }
    else
    {
      result = num_1 / num_2;
    }

    break;

  default:
    std::cout << ""
                 "Error\n";
    break;
  }

  return 0;
}