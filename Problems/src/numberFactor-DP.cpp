/****************************************************************/
/* Problem: Number Factor - Dynamic Programming Approach ********/
/****************************************************************/
/*
-- Summary:
Given an integer N, determine how many combinations are possible to make
using the numbers {1,3,4} to reach N. Example:
  N = 4: [1,1,1,1] [1,3] [3,1] [4] --> 4 possible combinations
-- Input(s):
N: integer to be reached
-- Expected output(s):
Print the number of combinations possible.
*/
#include <iostream>
#include <vector>

// ---- Top Down Approach - Memoization ----:
int nfHelper(int n, std::vector<int> &mem)
{
  if (n < 1)
    return 0;

  if (mem.at(n) != 0)
    return mem.at(n);

  mem.at(n) = nfHelper(n - 1, mem) + nfHelper(n - 3, mem) + nfHelper(n - 4, mem);

  return mem.at(n);
}

int nfTD(int n)
{
  std::vector<int> memo(n + 1);
  // - push first known cases:
  // number factor of 0: 0 combinations possible []
  memo.at(0) = 0;
  // number factor of 1: 1 combination possible [1]
  memo.at(1) = 1;
  // number factor of 2: 1 combination possible [1,1]
  memo.at(2) = 1;
  // number factor of 3: 2 combinations possible [1,1,1], [3]
  memo.at(3) = 2;
  // number factor of 4: 4 combinations possible [1,1,1,1], [3,1], [1,3], [4]
  memo.at(4) = 4;

  return nfHelper(n, memo);
}

// ---- Bottom Up Approach - Tabulation ----:
int nfBU(int n)
{
  // initalize array with results for the known cases:
  std::vector<int> mem{0, 1, 1, 2, 4};

  for (int i{5}; i <= n; i++)
  {
    mem.push_back(mem.at(i - 1) + mem.at(i - 3) + mem.at(i - 4));
  }

  return mem.at(n);
}

int main()
{
  std::cout << "Number Factor of 4 - Top Down: " << nfTD(4) << "\tBottom Up: " << nfBU(4) << "\n";
  std::cout << "Number Factor of 5 - Top Down: " << nfTD(5) << "\tBottom Up: " << nfBU(5) << "\n";
  std::cout << "Number Factor of 7 - Top Down: " << nfTD(7) << "\tBottom Up: " << nfBU(7) << "\n";
  std::cout << "Number Factor of 9 - Top Down: " << nfTD(9) << "\tBottom Up: " << nfBU(9) << "\n";
  std::cout << "Number Factor of 7 - Top Down: " << nfTD(11) << "\tBottom Up: " << nfBU(11) << "\n";
  std::cout << "Number Factor of 9 - Top Down: " << nfTD(13) << "\tBottom Up: " << nfBU(13) << "\n";

  return 0;
}