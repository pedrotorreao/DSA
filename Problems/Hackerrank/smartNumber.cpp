/*********************************************************************************************/
/* Problem: Smart Number (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  In this challenge, the task is to debug the existing code to successfully execute all provided
  test files.
  A number is called a smart number if it has an odd number of factors. Given some numbers,
  find whether they are smart numbers or not. Debug the given function "is_smart_number" to
  correctly check if a given number is a smart number.
  Note: You can modify only one line in the given code and you cannot add or remove any new
  lines.

-- Inputs:
  - int n: integer number

--Outputs:
  - bool: boolean indicating whether or not the number has an odd numbers of factors.

--Reasoning:
  Perfect squares have odd unique factors. For a given number 'N', we can group its divisors, 'D',
  in pairs (D,N/D), except that if N=M^2, this would pair M with itself.
  You can always list the factors of a number, 'N', into pairs (Ai,Bi) where Ai<=sqrt(N)<=Bi. This
  means that a number will always have an even number of factors, unless the number is a perfect
  square, in which case one pair will consist of the same two numbers.
    > Example - factors of 36
      (1,36)
      (2,18)
      (3,12)
      (4,9)
      (6,6)
      A total of 9 unique factors since 6 repeats itself. Or, 5 unique divisors.

      In the solution below, since a casting to <int> is being performed to the result of the square
      root operation, in order to check if it's a perfect square we cast 'val' to <double> to make
      sure that we're not neglecting anything after the decimal point and check if (num/val) is equal
      to 'val' itself, which would make num = val*val, hence 'num' is a perfect square and should have
      odd factors.

--Time complexity: O(1)

--Space complexity: O(1)

*/

#include <iostream>
#include <vector>
#include <cmath>

bool is_smart_number(int num)
{
  int val = (int)std::sqrt(num);
  if ((num / (double)val == val))
    return true;
  return false;
}

int main()
{
  std::vector<int> test_cases{1, 2, 7, 169};

  for (int i = 0; i < test_cases.size(); i++)
  {
    bool ans = is_smart_number(test_cases.at(i));

    if (ans)
    {
      std::cout << "YES" << std::endl;
    }
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}
/*
Expected:
  YES
  NO
  NO
  YES
*/