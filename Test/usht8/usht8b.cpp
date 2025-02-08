#include <iostream>
#include <cmath>

class X2Function
{
private:
  int a;
  int b;
  int c;

public:
  X2Function(int a, int b, int c)
  {
    this->a = a;
    this->b = b;
    this->c = c;
  }

  int get_a()
  {
    return a;
  }
  int get_b()
  {
    return b;
  }
  int get_c()
  {
    return c;
  }

  void set_a(int a)
  {
    this->a = a;
  }
  void set_b(int b)
  {
    this->b = b;
  }
  void set_c(int c)
  {
    this->c = c;
  }

  double D()
  {
    return (b * b) - (4 * a * c);
  }

  bool real_roots()
  {
    if (this->D() < 0)
    {
      return false;
    }
    return true;
  }

  double positive_root()
  {
    return (-1 * b + sqrt(this->D())) / 2 * a;
  }

  double negative_root()
  {
    return (-1 * b - sqrt(this->D())) / 2 * a;
  }

  void print()
  {
    std::printf("%dx2 +%dx + %d = 0\n", a, b, c);
  }

  bool operator==(X2Function &other)
  {
    if (this->a == other.a && this->b == other.b && this->c == other.c)
    {
      return true;
    }
    return false;
  }

  X2Function operator+(X2Function &other)
  {
    X2Function result(this->a + other.a, this->b + other.b, this->c + other.c);
    return result;
  }

  X2Function operator-(X2Function &other)
  {
    X2Function result(this->a - other.a, this->b - other.b, this->c - other.c);
    return result;
  }
};

int main()
{
  X2Function x1(2, 4, 5);
  X2Function x2(0, 1, 3);

  X2Function result = x1 + x2;

  result.print();
  return 0;
}
