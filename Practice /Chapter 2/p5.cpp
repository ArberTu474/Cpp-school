// 5. Write a program that determines whether a meeting room is in violation of
// fire law regulations regarding the maximum room capacity. The program
// will read in the maximum room capacity and the number of people at-
// tending the meeting. If the number of people is less than or equal to the
// maximum room capacity, the program announces that it is legal to hold
// the meeting and tells how many additional people may legally attend. If
// the number of people exceeds the maximum room capacity, the program
// announces that the meeting cannot be held as planned due to fire regula-
// tions and tells how many people must be excluded in order to meet the
// fire regulations. For a harder version, write your program so that it allows
// the calculation to be repeated as often as the user wishes. If this is a class
// exercise, ask your instructor whether you should do this harder version.

#include <iostream>

int main()
{
  int maximum_room_capacity;
  int people_in_room;

  char choice;

  do
  {
    std::cout << "What is the maximum room capacity: ";
    std::cin >> maximum_room_capacity;

    std::cout << "How many people are atending the meeting: ";
    std::cin >> people_in_room;

    if (people_in_room <= maximum_room_capacity)
    {
      std::cout << "You can continue with the meeting. There are " << maximum_room_capacity - people_in_room << " spots left.\n";
    }
    else
    {
      std::cout << "The meeting can not be held. " << people_in_room - maximum_room_capacity << " people should leave the room.\n";
    }

    std::cout << "\nDo you want to continue (y/n): ";
    std::cin >> choice;
  } while (tolower(choice) == 'y');

  return 0;
}