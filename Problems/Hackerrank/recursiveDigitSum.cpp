/*********************************************************************************************/
/* Problem: Recursive Digit Sum (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  We define super digit of an integer 'x' using the following rules:
    Given an integer, we need to find the super digit of the integer.
    - If 'x' has only 1 digit, then its super digit is 'x'.
    - Otherwise, the super digit of 'x' is equal to the super digit of the sum of the digits
    of 'x'.
    For example, the super digit of 9875 will be calculated as:
      super_digit(9875)     -->     9+8+7+5 = 29
      super_digit(29)       -->     2+9 = 11
      super_digit(11)       -->     1+1 = 2
      super_digit(2)        -->      = 2
  > Example:
    n = "9875"
    k = 4
    The number 'p' is created by concatenating the string 'n' 'k' times so the initial p=9875987598759875.
      super_digit(9875987598759875)     -->     9+8+7+5+9+8+7+5+9+8+7+5+9+8+7+5 = 116
      super_digit(116)                  -->     1+1+6 = 8
      super_digit(8)                    -->     = 8
    All of the digits of 'p' sum to 116. The digits of 116 sum to 8. 8 is only one digit, so it is
    the super digit.

--Inputs:
  - string n: a string representation of an integer.
  - int k: the times to concatenate 'n' to make 'p'.

--Outputs:
  - int: the super digit of 'n' repeated times 'k'.

--Constraints:
  1 <= n < 10^100000
  1 <= k <= 10^5

--Reasoning:
  Simple recursive s

--Time complexity: O(number_of_digits*recursive_calls), due to the iteration to account for each digit in the original number.

--Space complexity: O(1)

*/

#include <iostream>
#include <string>

int superDigit(std::string n, int k)
{
  // If 'x' has only 1 digit, then its super digit is 'x':
  if (n.size() == 1)
  {
    return (stoi(n));
  }

  long long sum{0};

  // Convert each digit to its ascii code and rescale the result to 0-9
  // and add it to the new sum:
  for (const auto &digit : n)
  {
    sum += (int(digit) - '0');
  }

  // Make a recursive call for the new sum and pass it k=1, since k was
  // used to concatenate the original string:
  return superDigit(std::to_string(sum * k), 1);
}

int main()
{
  std::string num{"9875"};
  int k{4};
  std::cout << "Super Digit for " << num << ": " << superDigit(num, k) << "\n";

  num = "12345678987654321";
  k = 5555;
  std::cout << "Super Digit for " << num << ": " << superDigit(num, k) << "\n";

  return 0;
}