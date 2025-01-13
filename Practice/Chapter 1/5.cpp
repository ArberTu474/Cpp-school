// 5. Write a program that inputs a character from the keyboard and then
// outputs a large block letter “C” composed of that character. For example,
// if the user inputs the character “X,” then the output should look as
// follows:
//   X X X
//  X    X
// X
// X
// X
// X
// X
// X
// X
//  X    X
//   X X X

#include <iostream>

int main()
{
  std::cout << "Enter your character: ";
  char c;
  std::cin >> c;

  std::printf("  %c %c %c\n", c, c, c);
  std::printf(" %c    %c\n", c, c);
  std::printf("%c\n", c);
  std::printf("%c\n", c);
  std::printf("%c\n", c);
  std::printf("%c\n", c);
  std::printf("%c\n", c);
  std::printf("%c\n", c);
  std::printf("%c\n", c);
  std::printf(" %c    %c\n", c, c);
  std::printf("  %c %c %c\n", c, c, c);

  return 0;
}