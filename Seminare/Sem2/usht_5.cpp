#include <iostream>

using namespace std;

int main()
{
  char input[10] = {};

  cin >> input;
  cout << input;

  for (int i = 0; i < 10; i++)
  {
    if (input[i] == '/')
    {
      input[i] = ':';
    }

    cout << input[i];
  }

  return 0;
}
