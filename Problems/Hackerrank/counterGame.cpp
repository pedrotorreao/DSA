/*********************************************************************************************/
/* Problem: Counter Game (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:

  > Example:

  > Input:

  > Output:

  > Constraints:

--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <string>
#include <cmath>

std::string counterGame(long n)
{
  int moves{0};
  while (n != 1)
  {
    if (log2(n) - (int)log2(n) == 0)
    {
      n /= 2;
    }
    else
    {
      int exponent = (int)log2(n);
      int base = 2;

      n -= pow(base, exponent);
    }
    ++moves;
  }
  return ((moves % 2 == 0) ? "Richard" : "Louise");
}

int main()
{
  long n{132};
  std::cout << "Winner for initial value " << n << ": " << counterGame(n) << "\n";

  n = 6;
  std::cout << "Winner for initial value " << n << ": " << counterGame(n) << "\n";

  return 0;
}