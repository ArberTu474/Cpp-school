// Write a program to score the paper-rock-scissor game. Each of two users
// types in either P, R, or S. The program then announces the winner as
// well as the basis for determining the winner: Paper covers rock, Rock
// breaks scissors, Scissors cut paper, or Nobody wins. Be sure to
// allow the users to use lowercase as well as uppercase letters. Your program
// should include a loop that lets the user play again until the user says she
// or he is done.
/* code */
#include <iostream>

int main()
{

  while (true)
  {
    char palyer_1;
    char palyer_2;

    std::cout << "Player 1 turn (P, R, S): ";
    std::cin >> palyer_1;
    std::cout << "Player 2 turn (P, R, S): ";
    std::cin >> palyer_2;

    palyer_1 = tolower(palyer_1);
    palyer_2 = tolower(palyer_2);

    if (palyer_1 == 'p' && palyer_2 == 'r')
    {
      std::cout << "Player 1 wins\n";
      std::cout << "Paper covers rock\n\n";
    }
    else if (palyer_2 == 'p' && palyer_1 == 'r')
    {
      std::cout << "Player 2 wins\n";
      std::cout << "Paper covers rock\n\n";
    }
    else if (palyer_1 == 'r' && palyer_2 == 's')
    {
      std::cout << "Player 1 wins\n";
      std::cout << "Rock breaks scissors\n\n";
    }
    else if (palyer_2 == 'r' && palyer_1 == 's')
    {
      std::cout << "Player 2 wins\n";
      std::cout << "Rock breaks scissors\n\n";
    }
    else if (palyer_1 == 's' && palyer_2 == 'p')
    {
      std::cout << "Player 1 wins\n";
      std::cout << "Scissors cut paper\n\n";
    }
    else if (palyer_2 == 's' && palyer_1 == 'p')
    {
      std::cout << "Player 2 wins\n";
      std::cout << "Scissors cut paper\n\n";
    }
    else if ((palyer_1 == 'r' && palyer_2 == 'r') ||
             (palyer_1 == 's' && palyer_2 == 's') ||
             (palyer_1 == 'p' && palyer_2 == 'p'))
    {
      std::cout << "Nobody Wins\n\n";
    }
    else
    {
      std::cout << "Quting...\n";
      break;
    }
  }

  return 0;
}