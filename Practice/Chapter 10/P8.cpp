// Define a class called Odometer that will be used to track fuel and mileage
// for an automotive vehicle. Include private member variables to track the
// miles driven and the fuel efficiency of the vehicle in miles per gallon. The
// class should have a constructor that initializes these values to zero. Include
// a member function to reset the odometer to zero miles, a member function
// to set the fuel efficiency, a member function that accepts miles driven for a
// trip and adds it to the odometer’s total, and a member function that returns
// the number of gallons of gasoline that the vehicle has consumed since the
// odometer was last reset.
// Use your class with a test program that creates several trips with different
// fuel efficiencies.

#include <iostream>

class Odometer
{
private:
  double miles;
  double fuel_efficiency;

public:
  Odometer()
  {
    miles = 0;
    fuel_efficiency = 0;
  }

  void reset()
  {
    miles = 0;
    fuel_efficiency = 0;
  }

  void set_fuel_efficiency(double fuel_efficiency)
  {
    this->fuel_efficiency = fuel_efficiency;
  }

  void add_miles(double miles)
  {
    this->miles += miles;
  }

  int gallons()
  {
    return miles * fuel_efficiency;
  }
};

int main()
{
  Odometer meter;
  meter.set_fuel_efficiency(2);
  meter.add_miles(200);
  meter.add_miles(30);

  std::cout << meter.gallons() << "\n";

  return 0;
}