#include <iostream>
#include <string>

class School
{
private:
  std::string name;
  int students_number;

public:
  School(std::string name, int students_number)
  {
    this->students_number = students_number;
    this->name = name;
  }

  std::string get_name()
  {
    return name;
  }
  int get_students_number()
  {
    return students_number;
  }

  void set_name(std::string name)
  {
    this->name = name;
  }
  void set_students_number(int students_number)
  {
    this->students_number = students_number;
  }

  void print()
  {
    std::cout << "Name: " << this->name << ", Nr. students: " << this->students_number << "\n";
  }

  friend bool operator>(School a, School b);
};

bool operator>(School a, School b)
{
  return a.students_number > b.students_number;
}

int main()
{
  School fshn("Fakulteti i shkencave te natyres", 4000);
  School fshn3("Fakulteti i shkencave te natyres", 2000);
  fshn.print();

  std::cout << (fshn > fshn3);
  return 0;
}
