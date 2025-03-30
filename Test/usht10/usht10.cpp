#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Shop
{
private:
  std::string address;
  std::string name;

public:
  Shop()
  {
    this->name = "";
    this->address = "";
  }

  Shop(std::string name, std::string address)
  {
    this->name = name;
    this->address = address;
  }

  std::string get_address()
  {
    return this->address;
  }
  std::string get_name()
  {
    return this->name;
  }

  void set_address(std::string address)
  {
    this->address = address;
  }
  void set_name(std::string name)
  {
    this->name = name;
  }
};

class ClothesShop : public Shop
{
private:
  std::string clothes_type;

public:
  ClothesShop(std::string name, std::string address, std::string clothes_type)
      : Shop(name, address)
  {
    this->clothes_type = clothes_type;
  }

  ClothesShop()
  {
    this->clothes_type = "";
  }

  std::string get_clothes_type()
  {
    return this->clothes_type;
  }

  void set_clothes_type(std::string)
  {
    this->clothes_type = clothes_type;
  }

  void print()
  {
    std::cout << "Name: " << this->get_name() << "\n";
    std::cout << "Address: " << this->get_address() << "\n";
    std::cout << "Clothes: " << this->get_clothes_type() << "\n";
  }

  bool operator==(ClothesShop &other)
  {
    return ((this->get_name() == other.get_name()) &&
            (this->get_address() == other.get_address()) &&
            (this->get_clothes_type() == other.get_clothes_type()));
  }
};

bool is_shop(ClothesShop shop, std::vector<ClothesShop> &list)
{
  for (int i = 0; i < list.size(); i++)
  {
    if (list.at(i) == shop)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  ClothesShop h_and_m("H&M", "Tirane", "Jeans");
  ClothesShop h_and_m2("H&M", "Tirane", "Jeans");

  std::cout << (h_and_m == h_and_m2) << "\n";

  h_and_m.print();

  std::vector<ClothesShop> list = {};
  // Lexojme te dhenat

  std::ifstream in;
  in.open("usht10.txt");

  if (in.is_open())
  {
    while (!in.eof())
    {
      std::string temp_name;
      std::string temp_address;
      std::string temp_clothes_type;

      in >> temp_name >> temp_address >> temp_clothes_type;
      ClothesShop new_shop(temp_name, temp_address, temp_clothes_type);
      list.push_back(new_shop);
    }
  }

  std::cout << is_shop(h_and_m, list);

  return 0;
}
