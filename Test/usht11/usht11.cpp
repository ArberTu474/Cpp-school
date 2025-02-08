#include <iostream>
#include <string>
#include <vector>

class Client
{
private:
  std::string name;
  std::string surname;

public:
  Client()
  {
    this->name = "";
    this->surname = "";
  }

  Client(std::string name, std::string surname)
  {
    this->name = name;
    this->surname = surname;
  }

  std::string get_name()
  {
    return name;
  }
  std::string get_surname()
  {
    return surname;
  }

  void set_name(std::string name)
  {
    this->name = name;
  }
  void set_surname(std::string surname)
  {
    this->surname = surname;
  }

  void print()
  {
    std::cout << this->name << " " << this->surname << "\n";
  }
};

class BankAccount : public Client
{
private:
  Client client;
  double balance;

public:
  BankAccount()
  {
    this->balance = 0;
  }

  BankAccount(Client client, double balance)
  {
    this->client = client;
    this->balance = balance;
  }

  void set_client(Client client)
  {
    this->client.set_name(client.get_name());
    this->client.set_surname(client.get_surname());
  }

  void set_balance(double balance)
  {
    this->balance = balance;
  }

  Client get_client()
  {
    return this->client;
  }

  double get_balance()
  {
    return this->balance;
  }

  void print()
  {
    this->client.print();
    std::cout << "Balance: " << this->balance << "\n";
  }

  friend std::ostream &operator<<(std::ostream &out, BankAccount &account)
  {
    out << account.client.get_name() << " : " << account.client.get_surname() << " : " << account.get_balance() << "\n";
    return out;
  }

  friend std::istream &operator>>(std::istream &in, BankAccount &account)
  {
    std::string name;
    std::string surname;
    double balance;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your surname: ";
    std::cin >> surname;
    std::cout << "Enter your bank balance: ";
    std::cin >> balance;
    account.client.set_name(name);
    account.client.set_surname(surname);
    account.set_balance(balance);
    return in;
  }
};

void print_matching_accounts(char c, std::vector<BankAccount> accounts)
{
  for (int i = 0; i < accounts.size(); i++)
  {
    if (accounts.at(i).get_client().get_name()[0] == c)
    {
      std::cout << accounts.at(i);
    }
  }
}

int main()
{
  Client client("Arber", "Tusha");

  BankAccount account(client, 4000);
  BankAccount bank;

  std::cin >> bank;
  std::cout << bank;

  std::vector<BankAccount> accounts = {};
  std::cout << "How many accounts do you want to include: ";
  int size;
  std::cin >> size;

  for (int i = 0; i < size; i++)
  {
    BankAccount new_account;
    std::cin >> new_account;
    accounts.push_back(new_account);
  }

  print_matching_accounts('A', accounts);

  return 0;
}
