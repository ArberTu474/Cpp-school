// A theatre sells seats for shows and needs a system to keep track of the
// seats they have sold tickets for. Define a class for a type called ShowTicket.

// The class should contain fields for the row, seat number, and whether the
// ticket has been sold or not. Define a constructor which accepts as argu-
// ments the row and seat number and sets the sold status to false in the
// constructor initialization section. Include member functions to check if
// the ticket has been sold; to update the ticket status to sold; and to print
// the row, seat number, and sold status. Embed your class definition in a test
// program which creates some ShowTicket objects, sets some tickets as sold,
// and prints each of them out.

#include <iostream>

class ShowTicket
{
private:
  int row;
  int seat_number;
  bool sold;

public:
  ShowTicket(int row, int seat_number)
  {
    this->row = row;
    this->seat_number = seat_number;
    sold = false;
  }

  bool isSold() const
  {
    return sold;
  }

  void sellTicket()
  {
    sold = true;
  }

  void print_ticket_info()
  {
    std::cout << "Row: " << row << "\n";
    std::cout << "Seat number: " << seat_number << "\n";
    std::cout << "Is available: " << (sold ? "no" : "yes") << "\n\n";
  }
};

int main()
{
  ShowTicket ticket_1(2, 7);
  ShowTicket ticket_2(4, 2);
  ShowTicket ticket_3(1, 3);

  ticket_1.sellTicket();

  ticket_1.print_ticket_info();
  ticket_2.print_ticket_info();
  ticket_3.print_ticket_info();

  return 0;
}