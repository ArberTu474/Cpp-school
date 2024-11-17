// nje parking kushton minimalisht 2 dollare per 3 ore qendrimi
// kushton 0.5 shtese pas ores se trete dhe per nje dite ksuhton 10 dollar
// shkruani nje program llogarit orarin dhe vleen e parkimit
// per 3 kliente si me poshte
//

#include <iostream>

double calculate_cost(double time)
{
  if (time <= 3)
  {
    return 2;
  }
  else if (time == 24)
  {
    return 10;
  }
  else
  {
    return 2 + (time - 3) * 0.5;
  }
}

int main()
{
  double total_cost = 0.0;
  double total_time = 0.0;
  double time;
  for (int i = 0; i < 3; i++)
  {
    std::cout << "Enter time for car " << i + 1 << ": ";
    std::cin >> time;
    total_cost += calculate_cost(time);
    total_time += time;
  }

  std::cout << total_time << " total time\n";
  std::cout << total_cost << " total cost\n";

  return 0;
}
