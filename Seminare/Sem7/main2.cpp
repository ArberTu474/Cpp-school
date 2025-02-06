/*
Ndertoni nje klase Automjet qe ka si variable instance shpejtesine e nje automjeti.
Ka nje konstruktore me parametra, nje metode qe kthen shpejtesine, nje metode qe ofron ndryshimin
e shpejtesise vetem brenda klases ose klasve qe trashegojne kete klase.

Ndertoni klasen tren qe trashegon ne menyre prvate nga klasa automjet. Ka si variable instance numrine
e vagonave. Ka nje konstruktor me parametra. Nje metode qe kthen numrin e vagonave te trenit si dhe
riimplementoni metoden e ndryshimit te te dhenave te trenit

Nje tren pasagejeresh trashegon ne menyre protected nga klasa tren. Ka si variable instance numrin e pasagjerve
Krijoni nje konstruktore me parametra, nje metode qe kthen numrin e pasagjerve per vagon, si dhe nje metode qe afishon
ne ekran te gjitha te dhenat qe mundet per trenin e pasagjerve


*/

#include <iostream>

class Vehicle
{
protected:
  double speed;

  void change_speed(double speed)
  {
    this->speed = speed;
  }

  Vehicle(double speed)
  {
    this->speed = speed;
  }

  double get_speed()
  {
    return this->speed;
  }
};

class Train : private Vehicle
{
private:
  int number_units;

public:
  Train(int unit, double speed) : Vehicle(speed)
  {
    number_units = unit;
  }

  void print_info()
  {
    std::cout << "Speed: " << speed << "\n";
    std::cout << "Units: " << number_units << "\n";
  }
};

main()
{
  Train train1(200, 23.5);

  train1.print_info();

  return 0;
}
