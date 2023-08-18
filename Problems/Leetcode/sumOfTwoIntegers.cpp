/*********************************************************************************************/
/* Problem: LC 371. Sum Of Two Integers ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given two integers a and b, return the sum of the two integers without using the operators
  + and -.

  > Example 1:
      Input: a = 1, b = 2
      Output: 3

  > Example 2:
      Input: a = 2, b = 3
      Output: 5

--Inputs:
  -int: the two integers to be added.

--Output:
  -int: resulting sum

--Constraints:
  :: -1000 <= a, b <= 1000

--Reasoning: See comments below.

--Time complexity:  O(1), given our range.

--Space complexity: O(1), no input dependent space is allocated.

*/

#include <iostream>

int getSumOfTwoIntegers(int a, int b) {
  while (b) {
    // calculate carry, i.e. identify the bit positions where carry happens:
    int carry = a & b;
    // calculate sum (logical XOR operation):
    a = a ^ b;
    // shift carry bit to the correct position:
    b = carry << 1;
  }
  return a;
}

int main() {
  int a{6}, b{7};
  printf("--> %d + %d = %d\n", a, b, getSumOfTwoIntegers(a, b));

  a = 123;
  b = 534;
  printf("--> %d + %d = %d\n", a, b, getSumOfTwoIntegers(a, b));

  a = 65535;
  b = 253425;
  printf("--> %d + %d = %d\n", a, b, getSumOfTwoIntegers(a, b));

  return 0;
}