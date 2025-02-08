#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Product
{
private:
  std::string name;
  double price;
  int quantity;

public:
  Product()
  {
    this->name = "";
    this->price = 0.0;
    this->quantity = 0;
  }
  Product(std::string name, double price, int quantity)
  {
    this->name = name;
    this->price = price;
    this->quantity = quantity;
  }

  std::string get_name()
  {
    return name;
  }
  double get_price()
  {
    return price;
  }
  int get_quantity()
  {
    return quantity;
  }

  void set_name(std::string name)
  {
    this->name = name;
  }
  void set_price(double price)
  {
    this->price = price;
  }
  void set_quantity(int quantity)
  {
    this->quantity = quantity;
  }

  void print()
  {
    std::cout << this->name << ", $" << this->price << " : " << this->quantity << "\n";
  }

  bool operator==(Product &other)
  {
    return (this->get_name() == other.get_name() && this->get_price() == other.get_price());
  }
};

class Supermarket
{
private:
  std::vector<Product> products;

  int find(std::string name)
  {
    for (int i = 0; i < products.size(); i++)
    {
      if (products.at(i).get_name() == name)
      {
        return i;
      }
    }
    return -1;
  }

public:
  Supermarket(std::string file_name)
  {
    std::ifstream in(file_name);

    if (in.is_open())
    {
      while (!in.eof())
      {
        std::string name;
        double price;
        int quantity;

        in >> name >> price >> quantity;

        Product new_product(name, price, quantity);

        products.push_back(new_product);
      }
    }
  }

  int get_quantity(std::string name)
  {
    for (Product product : products)
    {
      if (product.get_name() == name)
      {
        return product.get_quantity();
      }
    }
    return -1;
  }

  void buy(std::string name, int quantity)
  {
    int index = this->find(name);
    if (index == -1)
    {
      return;
    }
    else if (quantity >= this->products[index].get_quantity())
    {
      this->products[index].set_quantity(0);
    }
    else
    {
      this->products[index].set_quantity(this->products[index].get_quantity() - quantity);
    }
  }

  void add(Product product)
  {
    int index = this->find(product.get_name());

    if (index == -1)
    {
      this->products.push_back(product);
    }
    else
    {
      this->products[index].set_quantity(this->products[index].get_quantity() - product.get_quantity());
    }
  }

  void print()
  {
    for (Product product : products)
    {
      product.print();
    }
  }

  int number_of_products()
  {
    return this->products.size();
  }

  friend bool operator==(Supermarket &supermarkert1, Supermarket &supermarkert2)
  {
    return (supermarkert1.number_of_products() == supermarkert2.number_of_products());
  }
};

int main()
{
  Supermarket supermarket("usht12.txt");

  std::cout << supermarket.number_of_products();

  supermarket.print();

  supermarket.print();

  Product orange("orange", 20, 56);

  supermarket.add(orange);

  supermarket.print();

  return 0;
}
