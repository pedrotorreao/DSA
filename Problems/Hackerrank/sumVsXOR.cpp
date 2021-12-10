/*********************************************************************************************/
/* Problem: Sum and XOR (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an integer "n", find each "x" such that:
    . 0 <= x <= n
    . (n + x) = (n ^ x), where '^' denotes the bitwise XOR operator.

  > Example:
    n=4:
      - 4+0 = 4^0 = 4
      - 4+1 = 4^1 = 5
      - 4+2 = 4^2 = 6
      - 4+3 = 4^3 = 7
    return 4.

--Inputs:
  - int n: an integer

--Outputs:
  - int: the number of values found

--Reasoning:
  The XOR operation represents a binary addition that does not account for the carry over to the
  next digit. We want to know how many values of "x" will give us (n+x)=(n^x), which is when XOR
  is the same as SUM. This happens when there are no "carries". For the digits of "n" which are "0"
  (consider "n" in binary here), we can add either "1" or "0" without needing to deal with a carry,
  which means that XOR=SUM. Otherwise, if a digit of "n" is "1", the matching digit in "x" must be
  "0" to avoid the carry. So, for each "0" in "n", the matching digit in "x" can either be "1" or "0"
  with a total combination count of 2^(num. of zeros in bin(n)).

--Time complexity: O(log(p)), where p is the number of digits of "n" in binary notation.
    Since at each step we shift "n" to the right by 1 position in order to check the next binary
    digit, we are dividing "n" by at each step. So, if the binary notation of "n" has 4 digits,
    which could cover the range [0,15], i.e, 16 possibilities, we'd need 4 shifts to check all
    the digits of "n". Other examples:
      - n has 5 digits, i.e., n=10010 --> range [0,31], 32 possibilities --> 5 shifts needed
      - n has 2 digits, i.e., n=10 --> range [0,3], 4 possibilities --> 2 shifts needed
    So, in general, we need 2^shifts to cover a number with "p" digits, then:
      2^shifts = p --> log2(2^shifts) = log2(p), since loga(a^b) = b:
                   --> shifts = log2(p), where p is the number of digits of "n" in binary notation.
                   --> num. of operations = log(p)
                   --> time complexity = O(log(p))

--Space complexity: O(1), no additional space needed.

*/

#include <iostream>

long sumXor(long n)
{
  int numOfZeroes{0};
  long count{0};

  while (n > 0)
  {
    if ((n & 1) == 0)
    {
      ++numOfZeroes;
    }

    n = n >> 1;
  }

  count = (1L << numOfZeroes);

  return count;
}

int main()
{
  long n{10};
  std::cout << "Numbers for which SUM=XOR for " << n << ": " << sumXor(n) << "\n";

  n = 100;
  std::cout << "Numbers for which SUM=XOR for " << n << ": " << sumXor(n) << "\n";

  n = 1000;
  std::cout << "Numbers for which SUM=XOR for " << n << ": " << sumXor(n) << "\n";

  n = 10000;
  std::cout << "Numbers for which SUM=XOR for " << n << ": " << sumXor(n) << "\n";

  n = 16;
  std::cout << "Numbers for which SUM=XOR for " << n << ": " << sumXor(n) << "\n";

  n = 32;
  std::cout << "Numbers for which SUM=XOR for " << n << ": " << sumXor(n) << "\n";

  n = 5;
  std::cout << "Numbers for which SUM=XOR for " << n << ": " << sumXor(n) << "\n";

  n = 25;
  std::cout << "Numbers for which SUM=XOR for " << n << ": " << sumXor(n) << "\n";

  n = 19;
  std::cout << "Numbers for which SUM=XOR for " << n << ": " << sumXor(n) << "\n";

  return 0;
}