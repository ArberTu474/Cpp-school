#include <iostream>

class Point
{
protected:
  double x;
  double y;

  void set_x(double x)
  {
    this->x = x;
  }
  void set_y(double y)
  {
    this->y = y;
  }

public:
  Point(double x, double y)
  {
    this->x = x;
    this->y = y;
  }

  Point()
  {
    this->x = 0;
    this->y = 0;
  }

  double get_x()
  {
    return x;
  }
  double get_y()
  {
    return y;
  }

  void print_coordinates()
  {
    std::cout << "(" << x << ":" << y << ")" << "\n";
  }
};

class Line : public Point
{
private:
  Point point_a;
  Point point_b;

public:
  Line(Point point_a, Point point_b)
  {
    this->point_a = point_a;
    this->point_b = point_b;
  }

  Point get_point_a()
  {
    return this->point_a;
  }

  Point get_point_b()
  {
    return this->point_b;
  }

  void print_coordinates()
  {
    std::printf("(%.2f:%.2f), (%.2f:%.2f)\n", point_a.get_x(), point_a.get_y(), point_b.get_x(), point_b.get_y());
  }
};

int main()
{

  Point a(2, 4);
  Point b(3, 7);

  a.print_coordinates();
  b.print_coordinates();

  Line ab(a, b);

  Point a_test = ab.get_point_a();

  a_test.print_coordinates();

  ab.print_coordinates();
  return 0;
}
