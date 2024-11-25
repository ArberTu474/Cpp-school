// Account numbers across many companies and institutions adhere to a stan-
// dard which contains an algorithm to validate the account number against
// accidental incorrect input.
// For a given account number, the following algorithm will validate if the
// account number is valid:

// 1. Split the number up into its individual digits
// 2. Starting from the rightmost second-least significant figure, double
// every second digit. If the result of doubling the number is greater than
// 9, then subtract 9 from the number.
// 3. After doubling every second digit, calculate the sum of all the digits
// 4. If the sum modulo 10 is 0, then the account number is correct; other-
// wise it is incorrect

// Write a class called AccountNumber. The class should store an account
// number as a pointer to an array of type int. The constructor should
// accept as input a pointer to an array of type int and an integer containing
// the size of the array.
// You should include a member function for checking if the account
// number is valid using the algorithm outlined above. This method
// should create a temporary dynamic array to perform the account number
// validation. Ensure that you delete the dynamic array before the function
// returns.
// You should also include another member function which, if the account
// number is not valid, will find a value for the least significant digit which
// makes the account number a valid number.
// Write a test driver program which tests your class with valid and invalid
// account numbers of varying length.

#include <iostream>
#include <vector>

class AccountNumber
{
private:
  int(*ptr);
  int size;

public:
  AccountNumber(int(*ptr), int size)
  {
    this->size = size;
    this->ptr = ptr;
  }

  // 2 4 5
  bool is_valid_number()
  {
    std::vector<int> temp;

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
      if (i % 2 == 1)
      {
        if (*ptr * 2 > 9)
        {
          temp.push_back(*ptr * 2 - 9);
        }

        temp.push_back(*ptr);
      }
      else
        temp.push_back(*ptr);
      {
      }
      sum += temp[i];
      *ptr++;
    }

    temp.clear();

    if (sum % 10 == 0)
    {
      return true;
    }

    return false;
  }
};

int main()
{
  int array[5] = {2, 8, 1, 1, 3};
  int(*ptr)[5] = &array;

  AccountNumber number(*ptr, 5);

  std::cout << number.is_valid_number() << "\n";

  return 0;
}