//

#include <iostream>

int main()
{
  int n, k;
  k = 5;
  n = (100 % k ? k + 1 : k - 1);

  std::cout << n << "\n";
  std::cout << k;

  return 0;
}