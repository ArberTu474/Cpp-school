#include <iostream>
int main(int argc, char const *argv[])
{
  for (int i = 0; i >= 0; i++)
  {
    std::cout << "h";
  }
}

class X {
  public:
  X () {
    std::cout << "X" << "\n";
  }
};
class Y {
  public:
  Y () {
    std::cout << "Y" << "\n";
  }
};

// class Z :public X, public Y ();