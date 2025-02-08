#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Seller
{
  std::string name;
  int sales;

public:
  Seller()
  {
    name = "";
    sales = 0;
  }

  Seller(std::string name, int sales)
  {
    this->name = name;
    this->sales = sales;
  }

  std::string get_name()
  {
    return name;
  }
  int get_sales()
  {
    return sales;
  }

  void set_name(std::string name)
  {
    this->name = name;
  }
  void set_sales(int sales)
  {
    this->sales = sales;
  }

  friend std::ostream &operator<<(std::ostream &out, Seller &seller)
  {
    out << "Name: " << seller.get_name() << ", Sales: " << seller.get_sales() << "\n";
    return out;
  }
};

class Shop
{
private:
  std::string address;
  Seller seller1;
  Seller seller2;

public:
  Shop(std::string address, Seller seller1, Seller seller2)
  {
    this->address = address;
    this->seller1 = seller1;
    this->seller2 = seller2;
  }

  Seller best_seller()
  {
    if (seller1.get_sales() > seller2.get_sales())
    {
      return seller1;
    }
    else if (seller2.get_sales() > seller1.get_sales())
    {
      return seller2;
    }
  }

  void print()
  {
    std::cout << "Shop Address: " << this->address << "\n";
    std::cout << "Seller 1: " << seller1.get_name() << ", " << seller1.get_sales() << "\n";
    std::cout << "Seller 2: " << seller2.get_name() << ", " << seller2.get_sales() << "\n";
  }
};

std::vector<Seller> create_list(std::string file_name)
{
  std::vector<Seller> sellers = {};

  std::ifstream in;
  in.open(file_name);

  if (in.is_open())
  {
    std::string name;
    while (in >> name)
    {
      int sales = 0;
      in >> name;
      int numbers[7]; // Array to store 7 integers

      // Read 7 integers from the file
      for (int i = 0; i < 7; ++i)
      {
        in >> numbers[i];
      }

      for (int i = 0; i < 7; ++i)
      {
        sales += numbers[i];
      }

      Seller new_seller(name, sales);

      sellers.push_back(new_seller);
    }
  }

  return sellers;
}

int main()
{
  Seller seller1("Ana", 300);
  Seller seller2("Ben", 400);

  Shop shop1("Tirane", seller1, seller2);

  std::vector<Seller> sellers_list = create_list("usht9.txt");

  for (Seller seller : sellers_list)
  {
    std::cout << seller;
  }

  // shop1.print();
  return 0;
}
