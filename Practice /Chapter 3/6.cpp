// Buoyancy is the ability of an object to float. Archimedes’ principle states
// that the buoyant force is equal to the weight of the fluid that is displaced
// by the submerged object. The buoyant force can be computed by
// Fb = V * y
// where Fb is the buoyant force, V is the volume of the submerged object,
// and y is the specific weight of the fluid. If Fb is greater than or equal to the
// weight of the object, then it will float, otherwise it will sink.
// Write a program that inputs the weight (in pounds) and radius (in feet)
// of a sphere and outputs whether the sphere will sink or float in water. Use
// y = 62.4 lb/ft3 as the specific weight of water. The volume of a sphere is
// computed by (4/3)πr3.

#include <iostream>
#include <cmath>

int main()
{
  const int WATER_SPECIFIC_WEIGHT = 1000;

  std::cout << "Enter the weight(kg): ";
  double weight;
  std::cin >> weight;

  std::cout << "Enter the radius(m): ";
  double radius;
  std::cin >> radius;

  double volume = (4.0 / 3.0) * M_PI * pow(radius, 3);
  double buoyant_force = volume * WATER_SPECIFIC_WEIGHT;

  if (buoyant_force >= weight)
  {
    std::cout << "The sphere will float\n";
  }
  else
  {
    std::cout << "The sphere will sink\n";
  }

  return 0;
}