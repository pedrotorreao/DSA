/*********************************************************************************************/
/* Problem: Number Line Jumps (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are choreographing a circus show with various animals. For one act, you are given two
  kangaroos on a number line ready to jump in the positive direction (i.e, toward positive
  infinity).
   - The first kangaroo starts at location 'x1' and moves at a rate of 'v1' meters per jump.
   - The second kangaroo starts at location 'x2' and moves at a rate of 'v2' meters per jump.
  You have to figure out a way to get both kangaroos at the same location at the same time as
  part of the show. If it is possible, return YES, otherwise return NO.
  > Example:
      x1=2    v1=1    x2=1    v2=2
      After one jump, they are both at x=3, so the answer is YES.

  > Input:
    int x1, int v1: starting position and jump distance for kangaroo 1
    int x2, int v2: starting position and jump distance for kangaroo 2

  > Output - string: either YES or NO

  > Constraints:
      0<=x1<x2<=10000
      1<=v1<=10000
      1<=v2<=10000

--Reasoning:
  Basically, since 'x1 < x2', we need 'v1 > v2' so that the kangaroo1 at 'x1' have a chance to catch
  up to the kangaroo2 at 'x2', otherwise we can return "NO". After that, we iterate incrementing
  'x1' w/ 'v1' and 'x2' w/ 'v2' at each step until kangaroo1 initially at 'x1' catches up to kangaroo2
  initially at 'x2'. If they meet, they'll be at the same position 'x', otherwise, kangaroo1 will
  overtake kangaroo2 without being at the same position at the same time.
    If the kangaroos meet,
        x1 + (n*v1) = x2 + (n*v2) -> n*(v1 - v2) = (x2 - x1) -> n = (x2 - x1)/(v1 - v2)

--Time complexity:
  O(n), where n is the number of jumps needed until kangaroo1 meets/overtakes kangaroo2.

--Space complexity: O(1), there is memory allocation dependent on the input size.
*/

#include <iostream>
#include <string>

std::string kangaroo(int x1, int v1, int x2, int v2)
{
  if (v2 > v1)
    return "NO";

  int pos_1{x1}, pos_2{x2}, diff{0}, i{0};
  bool done{false};

  while (pos_1 < pos_2)
  {
    pos_1 += v1;
    pos_2 += v2;
  }

  if (pos_1 == pos_2)
    return "YES";

  return "NO";
}

int main()
{
  int x1{0}, v1{3}, x2{4}, v2{2};
  std::cout << "The kangaroos meet [Expected: YES]: " << kangaroo(x1, v1, x2, v2) << "\n";

  x1 = 4602;
  v1 = 8519;
  x2 = 7585;
  v2 = 8362;
  std::cout << "The kangaroos meet [Expected: YES]: " << kangaroo(x1, v1, x2, v2) << "\n";

  x1 = 1571;
  v1 = 4240;
  x2 = 9023;
  v2 = 4234;
  std::cout << "The kangaroos meet [Expected: YES]: " << kangaroo(x1, v1, x2, v2) << "\n";

  x1 = 3585;
  v1 = 7317;
  x2 = 6994;
  v2 = 9610;
  std::cout << "The kangaroos meet [Expected: NO]: " << kangaroo(x1, v1, x2, v2) << "\n";

  return 0;
}