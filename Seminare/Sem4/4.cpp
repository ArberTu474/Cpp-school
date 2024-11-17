// nje program ndihmon nje nexenes te mesoje tabelen e shumezimi
// programi duhet te shtyp nje pyetje:

// 3 * 2 = ?
// nxenesi jep pergjigjen

#include <iostream>
#include <random>

int main()
{

  while (true)
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10);

    int random_1 = dis(gen);
    int random_2 = dis(gen);

    int result = random_1 * random_2;

    std::printf("%d * %d = ? ", random_1, random_2);
    int user_answer;
    std::cin >> user_answer;
    if (user_answer == result)
    {
      std::cout << "Correct\n";
    }
    else
    {
      std::cout << "Wrong\n";
    }

    std::cout << "Do you want ot continue: ";
    std::cin >> user_answer;
    if (user_answer == -1)
    {
      break;
    } 
  }

  return 0;
}