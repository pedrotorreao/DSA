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

int mySqrt(int x) {
  // If x is smaller than 2, it can only be 0 or 1, since x is an
  // integer. As the square root of these numbers are themselves,
  // return x:
  if (x < 2)
    return x;

  // We'll use a binary search approach to find the square root of x.
  // The start and end positions for the search are represented by the
  // variables 'l', the lowest possible value for sqrt(x) which is 1,
  // and 'r', the greatest possible value for sqrt(x), which cannot be
  // greater than x/2:
  int l = 1;
  int r = x / 2;

  // We are looking for a value mid ~= sqrt(x) such as:
  //  -> (mid*mid < x), and
  //  -> (mid+1)*(mid+1) > x
  while (true) {
    // Let's divide the search interval in half and verify in which half
    // our square root value can be found:
    int mid = l + ((r - l) / 2); // avoid overflow for values of x too large

    // If (mid*mid > x):
    //  -> 'mid' value is too large, decrement it:
    if (mid > (x / mid))
      r = --mid;
    else {
      // If (mid*mid <= x) and (mid+1)*(mid+1) > x:
      //  -> 'mid' is our guy:
      if ((mid + 1) > (x / (mid + 1)))
        return mid;
      // Otherwise, if (mid+1)*(mid+1) < x:
      //  -> 'mid' is still too small, increment it:
      l = ++mid;
    }

    if (mid < 0)
      break;
  }

  return 0;
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