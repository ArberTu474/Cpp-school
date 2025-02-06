/*
te implementohent 2 klasa RRethei dhe Cilindri. Klasa Reth ka variable instance rrezen e rrethit
Funksionet e saj duhet te lexojne dhe hkrujne vlerat e variablit te instances. Te llogarisin
vleren e siperfaces se rrethit dhe te favishtojne vleren e siperfaqes. Klasa duhet te ket 2 konstruktore
me dhe pa paramtra.

Klasa ilinder tashegon nga klasa rreth. Ka si variables instance lartesin e cilindrit.
Duhet te perfshije nje metode te re per llogaritjen e vellimit te cilindrit dhe te riimplementoje funksionin
e gjetjes se siperfaqes. do te kete 2 konstruktore, me dhe pa parametra.

*/

#include <iostream>
#include <math.h>

class Circle
{
protected:
  double radius;

public:
  Circle()
  {
    this->radius = 0;
  }

  Circle(double radius)
  {
    this->radius = radius;
  }

  void set_radius(double radius)
  {
    this->radius = radius;
  }

  double get_radius()
  {
    return this->radius;
  }

  double area()
  {
    return radius * radius * M_PI;
  }
};

class Cylinder : public Circle
{
private:
  double height;

public:
  Cylinder()
  {
    this->height = 0;
  }
  Cylinder(double height)
  {
    this->height = height;
  }

  void set_height(double radius, double height)
  {
    this->height = height;
    this->radius = radius;
  }

  double get_height()
  {
    return this->height;
  }

  double volume()
  {
    return Circle::area() * height;
  }

  double area()
  {
    return 2 * M_PI * this->radius * height + 2 * volume();
  }
};

int main()
{
  Circle circle1(2);

  Cylinder cylinder1(4);

  std::cout << circle1.area() << "\n";
  std::cout << cylinder1.area() << "\n";

  return 0;
}
