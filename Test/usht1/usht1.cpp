// Ndertoni klasen Librari qe ruan te dhenat e disa librave ne shitje. Per cod liber ruan, titullin, cmimin dhe sasine ne gjendje. Krijo nje tip te ri per librin qe te ruaje kto te dhena.
// Implementoni keto metoda tek klasa librari:
// kerkimin per nje liber te caktuar dhe kthimin e sasise ne gjendje.
// Blerejen e nje libri me nje titull specifik dhe nje sasi specifike. Duhet marre nen konsiderate qe libri nuk gjendet ne librari ose sasianuk gjendet. 
// Futja e nje libri te ri ne librari, duke marre parasysh qe libri mund te ndodhet ne librari. Ne ate rast do te rritet sasia ne gjendje e atij libri. 
// overload + operator qe te mbledh by libra se bashku, pra te mbledh sasite e tyre ne gjendje 

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Book
{
private:
  std::string title;
  double price;
  int quantity;

public:
  Book()
  {
    this->title = "";
    this->price = 0.0;
    this->quantity = 0;
  }

  Book(std::string title, double price, int quantity)
  {
    this->title = title;
    this->price = price;
    this->quantity = quantity;
  }

  std::string get_title()
  {
    return this->title;
  }
  double get_price()
  {
    return this->price;
  }
  int get_quantity()
  {
    return this->quantity;
  }

  void set_title(std::string title)
  {
    this->title = title;
  }
  void set_price(double price)
  {
    this->price = price;
  }
  void set_quantity(int quantity)
  {
    this->quantity = quantity;
  }

  Book operator+(const Book &other) const
  {
    return Book(this->title, this->price, this->quantity + other.quantity);
  }
};

class Library
{
private:
  std::vector<Book> list;

  int find_book(std::string title)
  {
    for (int i = 0; i < list.size(); i++)
    {
      if (list[i].get_title() == title)
      {
        return i;
      }
    }
    return -1;
  }

public:
  Library()
  {
    list = {};
  }

  void add_books_form_file(std::string file_name)
  {
    std::ifstream in;
    in.open(file_name);

    if (in.is_open())
    {
      while (!in.eof())
      {
        std::string title_temp;
        double price_temp;
        int quantity_temp;
        in >> title_temp >> price_temp >> quantity_temp;

        Book new_book(title_temp, price_temp, quantity_temp);
        list.push_back(new_book);
      }
    }
  }

  int get_quantity(std::string book_title)
  {
    for (Book book : list)
    {
      if (book.get_title() == book_title)
      {
        return book.get_quantity();
      }
    }
    return 0;
  }

  void buy_book(std::string title, int quantity)
  {
    if (find_book(title) == -1 || list[find_book(title)].get_quantity() < quantity || quantity <= 0)
    {
      std::cout << "You can't buy this book right now\n";
      return;
    }
    else
    {
      int index = find_book(title);
      int actual_quantity = list[index].get_quantity();
      list[index].set_quantity(actual_quantity + quantity);
    }
  }

  void add_book(std::string title, double price, int quantity)
  {
    if (find_book(title) != -1)
    {
      int index = find_book(title);
      int actual_quantity = list[index].get_quantity();
      list[index].set_quantity(actual_quantity + quantity);
    }
    else
    {
      Book new_book(title, price, quantity);

      list.push_back(new_book);
    }
  }

  void print_library()
  {
    for (Book book : list)
    {
      std::cout << book.get_title() << " : " << book.get_price() << " : " << book.get_quantity() << "\n";
    }
  }

  Book get_book(int index)
  {
    return list[index];
  }
};

int main()
{
  Library library;
  library.add_books_form_file("usht1.txt");
  library.print_library();

  library.buy_book("hello2", 70);
  library.add_book("hello", 20.5, 300);

  library.print_library();

  Book book3 = library.get_book(0) + library.get_book(1);

  std::cout << book3.get_quantity() << "\n";
}
