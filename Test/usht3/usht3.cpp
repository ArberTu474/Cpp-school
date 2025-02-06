#include <iostream>
#include <fstream>
#include <string>
template <typename T>
class Article
{
private:
  std::string title;
  T price;

public:
  Article(std::string title, double price)
  {
    this->title = title;
    this->price = price;
  }

  Article()
  {
    this->title = "";
    this->price = 0;
  }

  std::string get_title()
  {
    return title;
  }
  T get_price()
  {
    return price;
  }

  void set_title(std::string title)
  {
    this->title = title;
  }
  void set_price(T price)
  {
    this->price = price;
  }

  std::string generate_code()
  {
    std::string result = this->title.substr(0, 3);
    result += std::to_string(this->title.length());
    result += this->title.substr(this->title.length() - 2, 1);
    return result;
  }
};

template <typename T>
class Bill
{
private:
  std::string buyer;
  Article<T> article1;
  Article<T> article2;

public:
  Bill(std::string buyer, Article<T> article1, Article<T> article2)
  {
    this->buyer = buyer;
    this->article1 = article1;
    this->article2 = article2;
  }

  void set_buyers_name(std::string new_name)
  {
    this->buyer = new_name;
  }

  void change_price(T new_price, int article_number)
  {
    if (article_number == 1)
    {
      article1.set_price(new_price);
    }
    else if (article_number == 2)
    {
      article2.set_price(new_price);
    }
  }

  T get_total_price()
  {
    return article1.get_price() + article2.get_price();
  }

  void print_bill()
  {
    std::cout << article1.get_title() << ", " << article2.get_title() << "\n"
              << "Total Price: " << article1.get_price() + article2.get_price() << "\n";
  }

  bool operator>(Bill &other)
  {
    if (this->get_total_price() > other.get_total_price())
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator<(Bill &other)
  {
    if (this->get_total_price() < other.get_total_price())
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator==(Bill &other)
  {
    if (this->get_total_price() == other.get_total_price())
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
void write_articles(Article<T> articles[], int size, std::string file_name)
{
  std::ofstream out(file_name);

  for (int i = 0; i < size; i++)
  {
    out << articles[i].get_title() << " " << articles[i].get_price() << " " << articles[i].generate_code() << "\n";
  }

  out.close();
}

int main()
{
  Article<double> article1("hello1", 23.4);
  Article<double> article2("hello2", 1.4);
  Article<double> article3("hello3", 40.4);

  Article<double> list[] = {article1, article2, article3};

  write_articles(list, 3, "usht3.txt");

  Bill<double> bill1("Arber", article1, article2);
  Bill<double> bill2("Arber", article1, article2);

  bill1.print_bill();
  bill1.change_price(200.0, 2);
  std::cout << article2.get_price() << "\n";
  bill1.print_bill();

  std::cout << (bill1 > bill2);

  return 0;
}
