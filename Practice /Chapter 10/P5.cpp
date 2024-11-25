// (In order to do this project, you must have first done either Programming
// Project 3 or Project 4.) Define a class called BookLibrary. This class should
// contain a field storing a vector of BookInfo objects. Your BookLibrary class
// should have the following methods: a default constructor; a constructor for
// adding an already existing vector of BookInfo objects; a method for adding
// a book into the library; a method for getting the number of books in the
// library; and a method for printing out information about each book in the
// library. Write a test program which creates a library and a number of books.
// Your program should add and remove these books from the library and print
// out information about the books in the library.

#include <iostream>
#include <vector>
class BookInfo
{
private:
  std::string author;
  std::string title;

public:
  BookInfo(std::string title, std::string author)
  {
    this->title = title;
    this->author = author;
  }

  BookInfo(std::string title)
  {
    this->title = title;
    author = "unknown";
  }

  std::string get_title_and_author()
  {
    return title + " " + author;
  }
};

class BookLibrary
{
private:
  std::vector<BookInfo> library;

public:
  BookLibrary(std::vector<BookInfo> library)
  {
    this->library = library;
  }

  void add_book(std::string author, std::string title)
  {
    library.push_back(BookInfo(title, author));
  }

  void remove_book(int index)
  {
    if (index > std::size(library))
    {
      std::cerr << "Index not found\n";
    }

    library.erase(library.begin() + index);
  }

  int get_number_of_books()
  {
    return std::size(library);
  }

  void print_library_info()
  {
    for (int i = 0; i < std::size(library); i++)
    {
      std::cout << (i + 1) << ". " << library[i].get_title_and_author() << "\n";
    }
  }
};

int main()
{
  std::vector<BookInfo> books_list;

  BookLibrary library(books_list);
  library.add_book("Ben2", "books 2 title");
  library.add_book("Ana", "title");
  library.add_book("Ana2", "title");

  library.remove_book(1);
  library.print_library_info();

  return 0;
}