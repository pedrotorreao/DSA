/*********************************************************************************************/
/* Problem: Sqrt(x) (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a non-negative integer x, compute and return the square root of x. Since the return type
  is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
  Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5)
  or x ** 0.5.
  > Example 1:
      Input: x = 4
      Output: 2
  > Example 2:
      Input: x = 8
      Output: 2
      Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated,
      2 is returned.

 --Inputs:
  -int: non-negative integer x

--Outputs:
  -int: non-negative integer r, truncated/only the integer part.

--Constraints:
   0 <= x <= 2^31 - 1

--Reasoning: See comments below.

--Time complexity: O(Log(N)), where N is the size of the 'unsorted' array.

--Space complexity: O(1), no additional input-dependent space is allocated.

*/

#include <iostream>

// we want a value y such as (y*y < x) and (y+1)*(y+1) > x
int mySqrt(int x) {
  if (x < 2)
    return x;

  int l = 1, r = x / 2;

  while (true) {
    int mid = l + (r - l) / 2;
    if (mid > (x / mid)) // mid*mid > x: mid value too large, decrement
      r = mid - 1;
    else {
      if ((mid + 1) > x / (mid + 1)) // (mid*mid <= x) and (mid+1)*(mid+1) > x: mid is our guy
        return mid;
      l = mid + 1; // (mid+1)*(mid+1) < x: mid is still too small
    }
  }
}

int main() {
  int x{8};
  std::cout << "Sqrt(" << x << ") is: " << mySqrt(x) << "\n";

  x = 24;
  std::cout << "Sqrt(" << x << ") is: " << mySqrt(x) << "\n";

  x = 50;
  std::cout << "Sqrt(" << x << ") is: " << mySqrt(x) << "\n";

  return 0;
}