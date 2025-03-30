#include <iostream>
#include <string>
#include <vector>

class Person
{
private:
  std::string name;
  int age;

public:
  Person()
  {
    this->name = "";
    this->age = 0;
  }

  Person(std::string name, int age)
  {
    this->name = name;
    this->age = age;
  }

  void print()
  {
    std::cout << name << "\n";
    std::cout << age << "\n";
  }

  virtual ~Person() {}
};

class Student : public Person
{
private:
  int student_id;
  std::string major;

public:
  Student()
  {
    student_id = 0;
    major = "";
  }

  Student(std::string name, int age, int student_id, std::string major)
      : Person(name, age)
  {
    this->student_id = student_id;
    this->major = major;
  }

  void print()
  {
    Person::print();
    std::cout << student_id << "\n";
    std::cout << major << "\n";
  }
};

class Professor : public Person
{
private:
  int employee_id;
  std::string department;

public:
  Professor()
  {
    this->employee_id = 0;
    this->department = "";
  }

  Professor(std::string name, int age, int employee_id, std::string department)
      : Person(name, age)
  {
    this->employee_id = employee_id;
    this->department = department;
  }

  void print()
  {
    Person::print();
    std::cout << employee_id << "\n";
    std::cout << department << "\n";
  }
};

int main()
{
  Person per("Ana", 12);
  Student student("Arber", 20, 1, "informatike");
  Student proffesor("Ben", 50, 1352, "Math");

  std::vector<Person *> people;

  people.push_back(new Student("Alice", 20, 1213, "Computer Science"));
  people.push_back(new Professor("Dr. Bob", 45, 1213, "Mathematics"));
  people.push_back(new Student("Charlie", 22, 1213, "Biology"));
  people.push_back(new Professor("Dr. Eve", 50, 1213, "Physics"));

  for (const auto &person : people)
  {
    person->print();
    std::cout << "-----------------------" << "\n";
  }

  // per.print();
  // student.print();
}
