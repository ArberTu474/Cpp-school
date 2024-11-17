// Write a program that scores a blackjack hand. In blackjack, a player
// receives from two to five cards. The cards 2 through 10 are scored as 2
// through 10 points each. The face cards—jack, queen, and king—are scored
// as 10 points. The goal is to come as close to a score of 21 as possible
// without going over 21. Hence, any score over 21 is called “busted.” The ace
// can count as either 1 or 11, whichever is better for the user. For example,
// an ace and a 10 can be scored as either 11 or 21. Since 21 is a better score,
// this hand is scored as 21. An ace and two 8s can be scored as either 17 or
// 27. Since 27 is a “busted” score, this hand is scored as 17.
// The user is asked how many cards she or he has, and the user responds
// with one of the integers 2, 3, 4, or 5. The user is then asked for the card
// values. Card values are 2 through 10, jack, queen, king, and ace. A good
// way to handle input is to use the type char so that the card input 2, for
// example, is read as the character '2', rather than as the number 2. Input
// the values 2 through 9 as the characters '2' through '9'. Input the values
// 10, jack, queen, king, and ace as the characters 't', 'j', 'q', 'k', and
// 'a'. (Of course, the user does not type in the single quotes.) Be sure to
// allow upper- as well as lowercase letters as input.
// After reading in the values, the program should convert them from character
// values to numeric card scores, taking special care for aces. The output is
// either a number between 2 and 21 (inclusive) or the word Busted. You
// are likely to have one or more long multiway branches that use a switch
// statement or nested if-else statement. Your program should include a loop
// that lets the user repeat this calculation until the user says she or he is done.

#include <iostream>

int main()
{
  std::cout << "How many cards do you have: ";
  int hand_cards;
  std::cin >> hand_cards;

  char card_value;
  int hand_score = 0;
  bool have_an_ace = false;
  bool busted = false;
  for (int i = 0; i < hand_cards; i++)
  {
    std::cout << "Enter the value of your card: ";
    std::cin >> card_value;

    switch (card_value)
    {
    case '2':
      hand_score += card_value - '0';
      break;
    case '3':
      hand_score += card_value - '0';
      break;
    case '4':
      hand_score += card_value - '0';
      break;
    case '5':
      hand_score += card_value - '0';
      break;
    case '6':
      hand_score += card_value - '0';
      break;
    case '7':
      hand_score += card_value - '0';
      break;
    case '8':
      hand_score += card_value - '0';
      break;
    case '9':
      hand_score += card_value - '0';
      break;
    case 't':
      hand_score += 10;
      break;
    case 'j':
      hand_score += 10;
      break;
    case 'q':
      hand_score += 10;
      break;
    case 'k':
      hand_score += 10;
      break;
    case 'a':
      have_an_ace = true;
      break;

    default:
      std::cout << "Please enter a valid card value\n";
      i--;
      break;
    }
  }

  if (hand_score > 21 || (have_an_ace && (hand_score + 1 > 21)))
  {
    busted = true;
  }
  else if (have_an_ace)
  {
    if (hand_score + 11 <= 21)
    {
      hand_score += 11;
    }
    else
    {
      hand_score += 1;
    }
  }

  if (busted)
  {
    std::cout << "Busted\n";
  }
  else
  {
    std::cout << "Hand score: " << hand_score << "\n";
  }

  return 0;
}