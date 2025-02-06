#include <iostream>
#include <fstream>
#include <string>

template <typename T>
class Room
{
private:
  T width;
  T height;
  std::string type;

public:
  Room(T width, T height, std::string type)
  {
    this->width = width;
    this->height = height;
    this->type = type;
  }

  Room()
  {
    this->width = 0;
    this->height = 0;
    this->type = "";
  }

  T get_width()
  {
    return this->width;
  }

  T get_height()
  {
    return this->height;
  }

  std::string get_type()
  {
    return this->type;
  }

  void set_width(T width)
  {
    this->width = width;
  }

  void set_height(T height)
  {
    this->height = height;
  }

  void set_type(std::string type)
  {
    this->type = type;
  }
};

template <typename T>
class House
{
private:
  std::string address;
  Room<T> room1;
  Room<T> room2;

protected:
  T area1 = room1.get_width() * room1.get_height();
  T area2 = room2.get_width() * room2.get_height();

public:
  House(std::string address, Room<T> room1, Room<T> room2)
  {
    this->address = address;
    this->room1 = room1;
    this->room2 = room2;
  }

  std::string get_address()
  {
    return this->address;
  }

  void set_address(std::string address)
  {
    this->address = address;
  }

  Room<T> get_room_1()
  {
    return this->room1;
  }

  Room<T> get_room_2()
  {
    return this->room2;
  }

  T get_biggest_room()
  {

    if (area1 >= area2)
    {
      return area1;
    }
    else
    {
      return area2;
    }
  }

  bool operator==(const House &other) const
  {
    if (this->area1 + this->area2 == other.area1 + other.area2)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

template <typename T>
void write_rooms(Room<T> table[], int size, std::string file_name)
{
  std::ofstream out(file_name);

  for (int i = 0; i < size; i++)
  {
    out << table[i].get_type() << " " << table[i].get_width() * table[i].get_height() << "\n";
  }

  std::cout << "Success\n";
  out.close();
}

int main()
{
  Room int_room(4, 5, "hello1");
  Room double_room(2.3, 500.0, "Hell2");
  Room double_room2(2.3, 5.6, "Hello3");
  Room double_room3(2.3, 6.6, "Hello4");
  Room double_room4(3.5, 5.6, "Hello4");

  Room<double> list[] = {double_room, double_room2, double_room3};
  int list_size = sizeof(list) / sizeof(list[0]);

  write_rooms(list, list_size, "usht2.txt");

  House<double> house1("Tirane", double_room, double_room2);
  House<double> house2("Tirane", double_room, double_room2);

  if (house1 == house2)
  {
    std::cout << "baras\n";
  }

  double big_room = house1.get_biggest_room();

  std::cout << big_room << "\n";
  return 0;
}
