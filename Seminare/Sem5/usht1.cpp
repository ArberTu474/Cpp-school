// Nderto nje program qe menaxhon nje librari.
// Per cdo liber duhet te ruaje nje ID, titullin, autorin, i disponueshem.
// Libraria duhet te punoje me 100 libra maksimumi.
// Funksionalitetet:
// 1. shton nje liber te ri. X
// 2. kerkon nje liber sipar titullit ose autorit. X
// 3. terheqjen e nje libri nga libraria. X
// 4. kthimin e nje libri. X
// 5. afishon listen e te gjitha librave qe jane marre X

#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Book
{
  int id;
  std::string title;
  std::string author;
  bool is_available;
};

void print_library(Book library[], int library_size, int index = -1);
void print_table_head();

void add_new_book(Book library[], int &books_count, std::string title, std::string author);
std::vector<int> search_books(Book library[], int library_size, std::string search_query);
std::vector<int> search_books(Book library[], int library_size, bool is_available);
void take_a_book(Book library[], int library_size, int book_id);
void return_a_book(Book library[], int library_size, int book_id);
void print_all_taken_books(Book library[], int library_size);
void print_all_available_books(Book library[], int library_size);

void library_loop(Book library[], int &library_size);

int main()
{
  const int MAX_BOOK_NUMBER = 100;

  Book library[MAX_BOOK_NUMBER] = {};
  int books_count = 0;

  add_new_book(library, books_count, "net", "man");
  add_new_book(library, books_count, "hello", "man");
  add_new_book(library, books_count, "test", "test");

  library_loop(library, books_count);

  return 0;
}

void library_loop(Book library[], int &library_size)
{
  std::cout << "=========================================\n";
  std::cout << "                 WELCOME                 \n";
  std::cout << "=========================================\n\n";

  int choice;
  while (true)
  {
    std::cout << "What do you want to do: \n";
    std::cout << "-1. Quit\n";
    std::cout << "1. Add a new book\n";
    std::cout << "2. Search for a book\n";
    std::cout << "3. Take a book\n";
    std::cout << "4. Return a book\n";
    std::cout << "5. Print the list of taken books\n";
    std::cin >> choice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choice == -1)
    {
      std::cout << "Goodbye!\n";
      break;
    }
    else if (choice == 1)
    {
      system("clear");
      std::string new_book_title;
      std::string new_book_author;

      std::cout << "Enter the title: ";
      std::getline(std::cin, new_book_title);

      std::cout << "Enter the author: ";
      std::getline(std::cin, new_book_author);

      add_new_book(library, library_size, new_book_title, new_book_author);
      system("clear");
      std::cout << "Great\n";
      print_library(library, library_size);
    }
    else if (choice == 2)
    {
      system("clear");
      std::string search_query;

      std::cout << "Enter the title/ author: ";
      std::getline(std::cin, search_query);

      std::vector<int> results = search_books(library, library_size, search_query);

      if (std::size(results) == 0)
      {
        std::cout << "Sorry, no books were found!\n\n";
      }
      else
      {
        std::cout << std::size(results) << " Search results:";
        print_table_head();
        for (int i = 0; i < std::size(results); i++)
        {
          print_library(library, library_size, results[i]);
        }
        std::cout << "\n";
      }
    }
    else if (choice == 3)
    {
      system("clear");
      std::cout << "Available books: ";
      print_all_available_books(library, library_size);
      std::cout << "\nEnter the id of the book that you want to take: ";
      int book_id;
      std::cin >> book_id;

      if (library[book_id].is_available)
      {
        library[book_id].is_available = false;
        std::cout << "Happy reading!\n";
      }
      else
      {
        std::cout << "Sorry this book is not available at the moment.\n";
      }
    }
    else if (choice == 4)
    {
      system("clear");
      std::cout << "Available books to return: ";
      print_all_taken_books(library, library_size);
      std::cout << "\nEnter the id of the book that you want to return: ";
      int book_id;
      std::cin >> book_id;

      if (!library[book_id].is_available)
      {
        library[book_id].is_available = true;
        std::cout << "Thank you for returing this book!\n";
      }
      else
      {
        std::cout << "Sorry, make sure you entered the correct id.\n";
      }
    }
    else if (choice == 5)
    {
      system("clear");
      std::cout << "Books that are taken: ";
      print_all_taken_books(library, library_size);
    }
    else
    {

      std::cout << "Enter a valid input (1-5) or -1.\n";
    }
  }
}

void print_table_head()
{
  std::printf("\n%-5s%-20s%-20s%-20s\n", "ID", "Title", "Author", "Is Available");
}

void print_library(Book library[], int library_size, int index)
{

  if (index == -1)
  {
    std::printf("%-5s%-20s%-20s%-20s\n", "ID", "Title", "Author", "Is Available");
    for (int i = 0; i < library_size; i++)
    {
      std::printf("%-5d%-20s%-20s%-1d\n",
                  library[i].id, library[i].title.c_str(), library[i].author.c_str(), library[i].is_available);
    }
  }
  else
  {
    for (int i = index; i < index + 1; i++)
    {
      std::printf("%-5d%-20s%-20s%-1d\n",
                  library[i].id, library[i].title.c_str(), library[i].author.c_str(), library[i].is_available);
    }
  }
}

void add_new_book(Book library[], int &books_count, std::string title, std::string author)
{
  Book new_book;
  new_book.id = books_count;
  new_book.title = title;
  new_book.author = author;
  new_book.is_available = true;

  library[books_count] = new_book;
  books_count++;
}

std::vector<int> search_books(Book library[], int library_size, std::string search_query)
{
  std::vector<int> results;

  for (int i = 0; i < library_size; i++)
  {
    if (library[i].author == search_query || library[i].title == search_query)
    {
      results.push_back(i);
    }
  }

  return results;
}

std::vector<int> search_books(Book library[], int library_size, bool is_available)
{
  std::vector<int> results;

  for (int i = 0; i < library_size; i++)
  {
    if (library[i].is_available == is_available)
    {
      results.push_back(i);
    }
  }

  return results;
}

void take_a_book(Book library[], int library_size, int book_id)
{
  library[book_id].is_available = false;
}

void return_a_book(Book library[], int library_size, int book_id)
{
  library[book_id].is_available = true;
}

void print_all_taken_books(Book library[], int library_size)
{
  std::vector<int> taken_books_id = search_books(library, library_size, false);
  print_table_head();
  for (int i = 0; i < std::size(taken_books_id); i++)
  {
    print_library(library, library_size, taken_books_id[i]);
  }
}

void print_all_available_books(Book library[], int library_size)
{
  std::vector<int> available_books_id = search_books(library, library_size, true);
  print_table_head();
  for (int i = 0; i < std::size(available_books_id); i++)
  {
    print_library(library, library_size, available_books_id[i]);
  }
}