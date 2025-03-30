#include <iostream>

template <typename T>
class Vehicle
{
private:
  T speed;
  int passengers;

public:
  Vehicle()
  {
    speed = 0;
    passengers = 0;
  }

  Vehicle(T speed, int passengers)
  {
    this->passengers = passengers;
    this->speed = speed;
  }

  T get_speed()
  {
    return this->speed;
  }

  int get_passengers()
  {
    return this->passengers;
  }

  void print()
  {
    std::cout << "Speed:\t\t " << this->speed << "\n";
    std::cout << "Passengers:\t " << this->passengers << "\n";
  }

protected:
  void set_speed(T speed)
  {
    this->speed = speed;
  }

  void set_passengers(int passengers)
  {
    this->passengers = passengers;
  }
};

class Train : public Vehicle<double>
{
private:
  int train_carriages;

public:
  Train(double speed, int passengers, int train_carriages)
      : Vehicle(speed, passengers)
  {
    this->train_carriages = train_carriages;
  }

  Train()
  {
    this->train_carriages = 0;
  }

  void set_carriages(int carriages)
  {
    this->train_carriages = carriages;
  }

  int get_carriages()
  {
    return this->train_carriages;
  }

  void print()
  {
    std::cout << "Speed:\t\t " << this->get_speed() << "\n";
    std::cout << "Passengers:\t " << this->get_passengers() << "\n";
    std::cout << "Cerriages:\t " << this->train_carriages << "\n";
  }

  friend bool operator>(Train &a, Train &other);
};
bool operator>(Train &a, Train &other)
{
  if (a.get_speed() > other.get_speed())
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  Vehicle vehicle_int(120, 27);
  vehicle_int.print();

  Vehicle<double> makin(2.4, 50);

  Train train1(300, 500, 5);
  Train train2(200, 200, 5);

  std::cout << (train1 > train2) << "\n";

  Vehicle vehicle_double(33.0, 5);
  vehicle_double.print();

  return 0;
}
