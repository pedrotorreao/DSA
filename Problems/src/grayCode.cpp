/****************************************************************/
/* Problem: Gray Code ********/
/****************************************************************/
/*
-- Summary:
An n-bit gray code sequence is a sequence of 2^n integers where:
    - Every integer is in the inclusive range [0, 2^n - 1],
    - The first integer is 0,
    - An integer appears no more than once in the sequence,
    - The binary representation of every pair of adjacent integers differs by exactly one bit, and
    - The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.
-- Input(s):
n: number of bits in the sequence
-- Expected output(s):
valid n-bit gray code sequence
-- Example:
Input: n = 2
Output: [0,1,3,2]
*/
#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> grayCode(int n)
{
  std::vector<int> grayCodeRes;
  int seqRange = pow(2, n); // or (1 << n), ex. n=3: (1<<3)=8, sequence = [0, 2^3-1] = [0,7]

  // the i-th bit of the gray code Gray(n) equals 1 only when i-th bit of n equals 1 and
  // (i+1)-th bit equals 0 (or i-th bit of n equals 0 and (i+1)-th bit equals 1).
  // therefore, Gray(n) = n XOR (n>>1).
  for (int i = 0; i < seqRange; i++)
  {
    grayCodeRes.push_back(i ^ (i >> 1));
  }
  return grayCodeRes;
}

void displayCodes(std::vector<int> grayCodesVec)
{
  for (size_t i{0}; i < grayCodesVec.size(); i++)
  {
    std::cout << grayCodesVec.at(i) << "  ";
  }

  std::cout << "\n";
}

int main()
{
  int n = 3;

  std::vector<int> grayCodes = grayCode(n);

  displayCodes(grayCodes);

  return 0;
}