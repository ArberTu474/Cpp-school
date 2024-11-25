// Redo Programming Project 1 (or do it for the first time), but this time make
// the student record type a class type rather than a structure type. The student
// record class should have member variables for all the input data described
// in Programing Project 1 and a member variable for the student’s weighted
// average numeric score for the entire course as well as a member variable for
// the student’s final letter grade. Make all member variables private. Include
// member functions for each of the following: member functions to set each
// of the member variables to values given as an argument(s) to the function
// member functions to retrieve the data from each of the member variables, a
// void function that calculates the student’s weighted average numeric score
// for the entire course and sets the corresponding member variable, and a
// void function that calculates the student’s final letter grade and sets the
// corresponding member variable.

#include <iostream>
#include <iomanip>

class StudentRecord
{
private:
  double quiz_1;
  double quiz_2;
  double midterm_exam;
  double final_exam;
  double final_numeric_score;
  char final_letter_grade;

public:
  StudentRecord(double quiz_1, double quiz_2, double midterm_exam, double final_exam)
  {
    this->quiz_1 = quiz_1;
    this->quiz_2 = quiz_2;
    this->midterm_exam = midterm_exam;
    this->final_exam = final_exam;
  }

  void calculate_final_score()
  {
    double quizScore = ((quiz_1 + quiz_2) / 20.0) * 25.0;

    final_numeric_score = quizScore + (midterm_exam * 0.25) + (final_exam * 0.5);
  }

  void determine_letter_grade()
  {
    if (final_numeric_score >= 90)
      final_letter_grade = 'A';
    else if (final_numeric_score >= 80)
      final_letter_grade = 'B';
    else if (final_numeric_score >= 70)
      final_letter_grade = 'C';
    else if (final_numeric_score >= 60)
      final_letter_grade = 'D';
    else
      final_letter_grade = 'F';
  }

  void print_student_record()
  {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nStudent Record:" << "\n";
    std::cout << "Quiz 1: " << quiz_1 << "/10" << "\n";
    std::cout << "Quiz 2: " << quiz_2 << "/10" << "\n";
    std::cout << "Midterm: " << midterm_exam << "/100" << "\n";
    std::cout << "Final Exam: " << final_exam << "/100" << "\n";
    std::cout << "Final Numeric Score: " << final_numeric_score << "%" << "\n";
    std::cout << "Final Letter Grade: " << final_letter_grade << "\n";
  }
};

int main()
{
  StudentRecord student(9, 8, 80, 90);

  student.calculate_final_score();
  student.determine_letter_grade();

  student.print_student_record();

  return 0;
}