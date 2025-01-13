// Write a program to compute the interest due, total amount due, and
// the minimum payment for a revolving credit account. The program
// accepts the account balance as input, then adds on the interest to get the
// total amount due. The rate schedules are the following: The interest is
// 1.5 percent on the first $1,000 and 1 percent on any amount over that.
// The minimum payment is the total amount due if that is $10 or less;
// otherwise, it is $10 or 10 percent of the total amount owed, whichever is
// larger. Your program should include a loop that lets the user repeat this
// calculation until the user says she or he is done.

#include <iostream>
#include <string>
#include <iomanip>

int main()
{

  std::string repeat;

  do
  {
    std::cout << "\nEnter your account balance: ";
    double balance;
    std::cin >> balance;

    double interest;
    if (balance <= 1000)
    {
      interest = 1000 * 0.15;
    }
    else
    {
      interest = 1000 * 0.15 + (balance - 1000) * 0.01;
    }

    double totat_amount_due = balance + interest;

    double minimum_payment;
    if (totat_amount_due <= 10)
    {
      minimum_payment = totat_amount_due;
    }
    else
    {
      double ten_percent = totat_amount_due * 0.10;
      minimum_payment = (ten_percent > 10) ? ten_percent : 10;
    }

    std::cout << std::fixed << std::setprecision(2); // Set output format for currency
    std::cout << "Interest due: $" << interest << "\n";
    std::cout << "Total amount due: $" << totat_amount_due << "\n";
    std::cout << "Minimum payment: $" << minimum_payment << "\n";

    std::cout << "Do you want to repeat the: ";
    std::cin >> repeat;
  } while (repeat == "yes" || repeat == "Yes" || repeat == "YES");

  return 0;
}