// 16. The following flowchart contains a series of questions to determine what
// kind of haircut to get. Write a program that asks the questions to the user
// and outputs the recommended haircut.

#include <iostream>
#include <string>

int main()
{
  std::string choice;
  std::cout << "Male or Female? ";
  std::cin >> choice;
  if (choice == "male")
  {
    std::cout << "Superheroor Super villain? ";
    std::cin >> choice;

    if (choice == "supervillan")
    {
      std::cout << "You should get amohawk";
    }
    else if (choice == "superhero")
    {
      std::cout << "Anime or Sitcom? ";
      std::cin >> choice;

      if (choice == "anime")
      {
        std::cout << "You should go with bangs";
      }
      else if (choice == "sitcom")
      {
        std::cout << "You should get a bob";
      }
    }
  }
  else if (choice == "female")
  {
    std::cout << "Superheroor Super villain? ";
    std::cin >> choice;

    if (choice == "supervillan")
    {
      std::cout << "You should get amohawk";
    }
    else if (choice == "superhero")
    {
      std::cout << "Steak or Sushi? ";
      std::cin >> choice;

      if (choice == "steak")
      {
        std::cout << "You should get a flat top";
      }
      else if (choice == "sushi")
      {
        std::cout << "You should get a pompadour";
      }
    }
  }

  return 0;
}