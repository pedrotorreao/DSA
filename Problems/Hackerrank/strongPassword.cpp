/*********************************************************************************************/
/* Problem: Strong Password (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Louise joined a social networking site to stay in touch with her friends. The signup page
  required her to input a name and a password. However, the password must be strong. The website
  considers a password to be strong if it satisfies the following criteria:
    - Its length is at least 6.
    - It contains at least one digit.
    - It contains at least one lowercase English character.
    - It contains at least one uppercase English character.
    - It contains at least one special character. The special characters are: !@#$%^&*()-+
  She typed a random string of length 'n' in the password field but wasn't sure if it was strong.
  Given the string she typed, can you find the minimum number of characters she must add to make
  her password strong?
  Note: Here's the set of types of characters in a form you can paste in your solution:
    numbers = "0123456789"
    lower_case = "abcdefghijklmnopqrstuvwxyz"
    upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    special_characters = "!@#$%^&*()-+"

    > Example:
      a. passsword = '2bbbb'
        This password is 5 characters long and is missing an uppercase and a special character.
        The minimum number of characters to add is 2.
      b. password = '2bb#A'
        This password is 5 characters long and has at least one of each character type. The minimum
        number of characters to add is 1.

--Inputs:
  - int n: the length of the password
  - string password: the password to test

--Outputs:
  - int: the minimum number of characters to add.

--Reasoning:
  Iterate over the password string checking each condition and keep boolean variables to set when the
  conditions are met. Once a condition is met, its boolean variable is set and this condition does
  not need to be checked again. At the end, each boolean variable that remains 'false' is a condition
  which was not satisfied and an edit that needs to be made, add it to "minEdits". If the condition
  for the minimum length is satisfied, we need to make "minEdits" additional edits to the password.
  Otherwise, at least (6-n) edits will be needed, so we return the larger value between "minEdits"
  and (6-n).

--Time complexity: O(N), where N is the length of the password.

--Space complexity: O(1), no additional space directly dependent on the input size needed.

*/

#include <iostream>
#include <string>

int minimumNumber(int n, std::string password)
{
  // result:
  int minEdits{0};

  // Booleans for the checks:
  bool minLength{false}, oneDigit{false}, lower{false}, upper{false}, specialCharac{false};

  // checks for min length of 6:
  minLength = (n >= 6);

  for (auto &c : password)
  {
    // get ascii code for current character:
    int asciiCode = int(c);

    // checks for digits:
    if (((asciiCode >= int('0')) && (asciiCode <= int('9'))) && !oneDigit)
    {
      oneDigit = true;
      continue;
    }

    // checks for uppercase letters:
    if (((asciiCode >= int('A')) && (asciiCode <= int('Z'))) && !upper)
    {
      upper = true;
      continue;
    }

    // checks for lowercase letters:
    if (((asciiCode >= int('a')) && (asciiCode <= int('z'))) && !lower)
    {
      lower = true;
      continue;
    }

    // checks for special characters "!@#$%^&*()-+":
    if (!specialCharac)
    {
      for (auto &sp : "!@#$%^&*()-+")
      {
        if (c == sp)
          specialCharac = true;
      }
    }

    if (minLength && oneDigit && upper && lower && specialCharac)
      return minEdits;
  }

  if (!oneDigit)
    ++minEdits;

  if (!lower)
    ++minEdits;

  if (!upper)
    ++minEdits;

  if (!specialCharac)
    ++minEdits;

  if (!minLength)
    return std::max(minEdits, (6 - n));

  return minEdits;
}

int main()
{
  std::string str{"Ab1"};
  int n{3};

  std::cout << "Min. edits for " << str << ": " << minimumNumber(n, str) << "\n"; // 3

  str = "#HackerRank";
  n = 11;

  std::cout << "Min. edits for " << str << ": " << minimumNumber(n, str) << "\n"; // 1

  return 0;
}
