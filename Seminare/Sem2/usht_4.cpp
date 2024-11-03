#include <iostream>

using namespace std;

int main()
{
  int array[4] = {};

  for (int i = 0; i < 4; i++)
  {
    cout << "Enter number " << i + 1 << ": ";
    cin >> array[i];
  }

  for (int i = 3; i >= 0; i--)
  {
    cout << array[i] * 2 << " ";
  }

  return 0;
}
