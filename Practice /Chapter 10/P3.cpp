// Define a class called BookInfo that is an abstract data type for storing
// information about a book. Your class should have two fields of type String,
// the first to store the author name and the second to store the book title.
// Include the following member functions: a constructor to set the book title
// and author, a second constructor which sets the book title to a parameter
// passed in and the author to “unknown”, and a method to get the author
// and title concatenated into a single C++ String. Write a driver program to
// test your class by creating a few book objects and printing them out using
// your member functions.

#include <iostream>
#include <string>

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

int main()
{
  BookInfo book_1("Net te bardha", "Dostojefski");
  BookInfo book_2("Hello title");

  std::cout << book_1.get_title_and_author() << "\n";
  // std::cout << book_2.get_title_and_author() << "\n";

  return 0;
}