// Write a grading program for a class with the following grading policies:
// a. There are two quizzes, each graded on the basis of 10 points.
// b. There is one midterm exam and one final exam, each graded on the
// basis of 100 points.
// c. The final exam counts for 50 percent of the grade, the midterm counts
// for 25 percent, and the two quizzes together count for a total of
// 25 percent. (Do not forget to normalize the quiz scores. They should be
// converted to a percent before they are averaged in.)
// Any grade of 90 or more is an A, any grade of 80 or more (but less
// than 90) is a B, any grade of 70 or more (but less than 80) is a C, any
// grade of 60 or more (but less than 70) is a D, and any grade below 60 is an F.
// The program will read in the student’s scores and output the student’s
// record, which consists of two quiz and two exam scores as well as the
// student’s average numeric score for the entire course and the final letter
// grade. Define and use a structure for the student record. If this is a class
// assignment, ask your instructor if input/output should be done with the
// keyboard and screen or if it should be done with files. If it is to be done
// with files, ask your instructor for instructions on file names.

#include <iostream>
#include <iomanip>

struct Record
{
  double quiz_1;
  double quiz_2;
  double midterm_exam;
  double final_exam;
  double final_numeric_score;
  char final_letter_grade;
};

double calculate_final_score(const Record &student);
char determine_letter_grade(double score);
void print_student_record(const Record &student);

int main()
{
  Record student;

  // Input student scores
  std::cout << "Enter the score for Quiz 1 (out of 10): ";
  std::cin >> student.quiz_1;
  std::cout << "Enter the score for Quiz 2 (out of 10): ";
  std::cin >> student.quiz_2;
  std::cout << "Enter the score for the Midterm Exam (out of 100): ";
  std::cin >> student.midterm_exam;
  std::cout << "Enter the score for the Final Exam (out of 100): ";
  std::cin >> student.final_exam;

  student.final_numeric_score = calculate_final_score(student);
  student.final_letter_grade = determine_letter_grade(student.final_numeric_score);

  print_student_record(student);

  return 0;
}

char determine_letter_grade(double score)
{
  if (score >= 90)
    return 'A';
  else if (score >= 80)
    return 'B';
  else if (score >= 70)
    return 'C';
  else if (score >= 60)
    return 'D';
  else
    return 'F';
}

double calculate_final_score(const Record &student)
{
  double quizScore = ((student.quiz_1 + student.quiz_2) / 20.0) * 25.0;

  return quizScore + (student.midterm_exam * 0.25) + (student.final_exam * 0.5);
}

void print_student_record(const Record &student)
{
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "\nStudent Record:" << "\n";
  std::cout << "Quiz 1: " << student.quiz_1 << "/10" << "\n";
  std::cout << "Quiz 2: " << student.quiz_2 << "/10" << "\n";
  std::cout << "Midterm: " << student.midterm_exam << "/100" << "\n";
  std::cout << "Final Exam: " << student.final_exam << "/100" << "\n";
  std::cout << "Final Numeric Score: " << student.final_numeric_score << "%" << "\n";
  std::cout << "Final Letter Grade: " << student.final_letter_grade << "\n";
}