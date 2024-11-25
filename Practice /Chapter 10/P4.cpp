// Define a class called UpdatedBook which inherits the BookInfo class
// created in Programming Project 3. This new class should contain an
// integer field for the edition number of the book, a constructor to create
// the UpdatedBook object accepting as input the author, title, and edition
// number of the book, and a getter method to return the edition number.

#include <iostream>
#include <string>

class BookInfo
{
protected:
  std::string author;
  std::string title;

public:
  BookInfo(std::string book_author, std::string book_title)
  {
    author = book_author;
    title = book_title;
  }

  BookInfo(std::string bookTitle)
  {
    author = "unknown";
    title = bookTitle;
  }

  std::string get_author_and_title() const
  {
    return "Author: " + author + ", Title: " + title;
  }
};

class UpdatedBook : public BookInfo
{
private:
  int edition;

public:
  UpdatedBook(std::string bookAuthor, std::string bookTitle, int bookEdition)
      : BookInfo(bookAuthor, bookTitle), edition(bookEdition) {};

  int get_edition()
  {
    return edition;
  }

  std::string get_book_details() const
  {
    return get_author_and_title() + " edition: " + std::to_string(edition);
  }
};

int main()
{
  UpdatedBook book1("J.K. Rowling", "Harry Potter and the Chamber of Secrets", 2);
  UpdatedBook book2("George Orwell", "1984", 3);

  std::cout << book1.get_book_details() << "\n";
  std::cout << book2.get_book_details() << "\n";

  return 0;
}