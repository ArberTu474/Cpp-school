// Ky usht nuk perdor template classes sepse eshte e kote ti perdoresh
// thjesht eshte nje kerekese e dhene pa kuptim nga zysha, per te
// shtuar kompleksitet dhe veshtiresi ne zgjidhje pa qene nevoja

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class BankAccount
{
private:
  std::string name;
  double amount;

public:
  BankAccount(std::string name, double amount)
  {
    this->name = name;
    this->amount = amount;
  }

  BankAccount()
  {
    this->name = "";
    this->amount = 0.0;
  }

  std::string get_name()
  {
    return name;
  }
  double get_amount()
  {
    return amount;
  }

  void set_name(std::string name)
  {
    this->name = name;
  }
  void set_amount(double amount)
  {
    this->amount = amount;
  }

  void deposit_money(double money)
  {
    this->amount += money;
  }

  void withdraw_money(double money)
  {
    if (money >= this->amount)
    {
      this->amount = 0.0;
    }
    else
    {
      this->amount -= money;
    }
  }

  void print()
  {
    std::cout << this->name << ": $" << this->amount << "\n";
  }
};

class SavingsAccount : public BankAccount
{
private:
  double interest_rate;
  int allowed_withdraws;
  int actual_withdraws;

public:
  double get_interest_rate()
  {
    return interest_rate;
  }
  int get_allowed_withdraws()
  {
    return allowed_withdraws;
  }
  int get_actual_withdraws()
  {
    return actual_withdraws;
  }

  void set_interest_rate(double interest_rate)
  {
    this->interest_rate = interest_rate;
  }
  void set_allowed_withdraws(int allowed_withdraws)
  {
    this->allowed_withdraws = allowed_withdraws;
  }
  void set_actual_withdraws(int actual_withdraws)
  {
    this->actual_withdraws = actual_withdraws;
  }

  SavingsAccount(std::string name, double amount, double interest_rate, int allowed_withdraws)
      : BankAccount(name, amount)
  {
    this->interest_rate = interest_rate;
    this->allowed_withdraws = allowed_withdraws;
    actual_withdraws = 0;
  }

  void reset_allowed_withdraws()
  {
    this->actual_withdraws = 0;
  }

  void withdraw_money(double money)
  {
    if (this->actual_withdraws == this->allowed_withdraws)
    {
      std::cout << "You can't withdraw now\n";
      return;
    }
    else if (money >= this->get_amount())
    {
      this->actual_withdraws++;
      this->set_amount(0);
    }
    else
    {
      this->actual_withdraws++;
      this->set_amount(this->get_amount() - money);
    }
  }

  double calculate_earnings(int months)
  {
    return this->get_amount() * this->interest_rate * months;
  }

  void update_balance(int months)
  {
    this->set_amount(this->get_amount() + this->calculate_earnings(months));
  }

  bool operator==(SavingsAccount &other)
  {
    if ((this->interest_rate == other.get_interest_rate()) &&
        (this->allowed_withdraws == other.get_allowed_withdraws()))
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void print()
  {
    std::cout << this->get_name() << ": $" << this->get_amount() << ":" << this->interest_rate << ":" << this->allowed_withdraws << "\n";
  }
};

std::vector<BankAccount> create_accounts_from_file(std::string file_name)
{
  std::vector<BankAccount> accounts = {};

  std::ifstream in;
  in.open(file_name);

  if (in.is_open())
  {
    while (!in.eof())
    {
      std::string temp_name;
      double temp_amount;

      in >> temp_name >> temp_amount;
      BankAccount new_account(temp_name, temp_amount);

      accounts.push_back(new_account);
    }
  }
  in.close();

  return accounts;
}

int main()
{
  BankAccount account1("Arber", 1000.0);

  // account1.print();

  account1.deposit_money(300);
  // account1.print();

  std::vector<BankAccount> accounts = create_accounts_from_file("usht4.txt");

  for (BankAccount account : accounts)
  {
    // account.print();
  }

  SavingsAccount savings("ArberS", 2000, 0.03, 3);
  SavingsAccount savings1("ArberS", 20000, 0.03, 3);

  std::cout << (savings1 == savings) << "\n";

  std::string name;
  double ammount;
  double interest;
  int withdraws;

  std::cin >> name >> ammount >> interest >> withdraws;

  SavingsAccount savings3(name, ammount, interest, withdraws);
  savings3.print();
  return 0;
}
