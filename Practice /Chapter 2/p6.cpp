// 6. An employee is paid at a rate of $16.78 per hour for the first 40 hours
// worked in a week. Any hours over that are paid at the overtime rate of one-
// and-one-half times that. From the worker’s gross pay, 6% is withheld for
// Social Security tax, 14% is withheld for federal income tax, 5% is withheld
// for state income tax, and $10 per week is withheld for union dues. If the
// worker has three or more dependents, then an additional $35 is withheld
// to cover the extra cost of health insurance beyond what the employer pays.
// Write a program that will read in the number of hours worked in a week
// and the number of dependents as input and will then output the worker’s
// gross pay, each withholding amount, and the net take-home pay for the
// week.

#include <iostream>

int main()
{
  const double HOURLY_RATE = 16.78;
  const int MAX_WORK_HOURS = 40;
  const double EXTRA_HOURS_INCREASE = 1.5;

  const double SOCIAL_SECURITY_TAX = 0.06;
  const double FEDERAL_INCOME_TAX = 0.14;
  const double STATE_INCOME_TAX = 0.05;
  const double UNION_DUES = 10;
  const int DEPENDENTS_EXTRA_COST = 35;

  int work_hours;
  int dependents_number;

  std::cout << "Enter the number of hours worked in this week: ";
  std::cin >> work_hours;

  std::cout << "ENters the number of dependents: ";
  std::cin >> dependents_number;

  double gross_pay;
  if (work_hours > MAX_WORK_HOURS)
  {
    gross_pay = HOURLY_RATE * MAX_WORK_HOURS + ((work_hours - MAX_WORK_HOURS) * HOURLY_RATE * EXTRA_HOURS_INCREASE);
  }
  else
  {
    gross_pay = work_hours * HOURLY_RATE;
  }

  // Calculate taxes
  double social_security_withheld = gross_pay * SOCIAL_SECURITY_TAX;
  double federal_income_withheld = gross_pay * FEDERAL_INCOME_TAX;
  double state_income_withheld = gross_pay * STATE_INCOME_TAX;
  double dependents_withheld = (dependents_number >= 3) ? 35.0 : 0.0;

  double take_home_pay = gross_pay - social_security_withheld - federal_income_withheld - state_income_withheld - UNION_DUES - dependents_withheld;

  // Output:
  std::printf("\n---------------------------------\n");
  std::printf("Gross Pay:\t\t%8.2f$\n", gross_pay);

  std::printf("\n");
  std::printf("Social Security Tax:\t%8.2f$\n", social_security_withheld);
  std::printf("Federal Income Tax:\t%8.2f$\n", federal_income_withheld);
  std::printf("State Income Tax:\t%8.2f$\n", state_income_withheld);
  std::printf("Union Dues Tax:\t\t%8.2f$\n", UNION_DUES);
  std::printf("Dependents Tax:\t\t%8.2f$\n", dependents_withheld);
  std::printf("\n");

  std::printf("Take Home Pay:\t\t%8.2f$\n", take_home_pay);

  return 0;
}