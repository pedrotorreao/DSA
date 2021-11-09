/*********************************************************************************************/
/* Problem: Flipping Bits (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  You will be given a list of 32 bit unsigned integers. Flip all the bits (1->0) and (0->1)
  and return the result as an unsigned integer.
  > Example:
      n=9dec: 9dec = 1001bin
    Since we're working with 32 bits, so:
      000000000000000000000000001001bin = 9dec
      111111111111111111111111110110bin = 4294967286dec
  Return 4294967286dec
  Function Description: Complete the flippingBits function in the editor below.
    flippingBits has the following parameter(s): int n: an integer
  > Returns:
    int: the unsigned decimal integer result

--Reasoning:
  Invert the bits so we don't get incorrect negative results, negate the input integer and cast
  it to an uint to avoid wrong negative resultados.

--Time complexity: O(1)

--Space complexity: O(1)
*/

#include <iostream>

long flippingBits(long n)
{
  // return (UINT_MAX - n);
  return (uint)~n;
}

int main()
{
  // ...code

  return 0;
}
