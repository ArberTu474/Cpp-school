// 4. Write a very simple conversational dialog program. Your program should
// do the following:
// ■ Say “Hello” to the user.
// ■ Ask them if they are having a good day, and record their input.
// ■ If their response is anything other than a ‘y’ for yes or an ‘n’ for no,
// repeat the question.
// ■ If they respond with a ‘y’, output “I’m glad to hear thatI’m glad to hear that”, and if they
// answer with an ‘n’, then output “I hope your day gets better soon.”
// You may need to use a do-while loop to repeat the questions to the user.

#include <iostream>

int main()
{
  char choice;
  std::cout << "Hello\n";

  do
  {
    std::cout << "Are you having a good day(y/n): ";
    std::cin >> choice;
    std::cin.ignore(10000, '\n'); // Clear the buffer
  } while (tolower(choice) != 'y' && tolower(choice) != 'n');

  if (choice == 'y')
  {
    std::cout << "I'm glad to hear that.\n";
  }
  else
  {
    std::cout << "I hope your day gets better soon.\n";
  }

  return 0;
}