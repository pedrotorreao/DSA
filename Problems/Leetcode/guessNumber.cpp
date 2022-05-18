/*********************************************************************************************/
/* Problem: Guess Number Higher or Lower (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  We are playing the Guess Game. The game is as follows:
    - I pick a number from 1 to n. You have to guess which number I picked.
    - Every time you guess wrong, I will tell you whether the number I picked is higher or
    lower than your guess.

  You call a pre-defined API int guess(int num), which returns three possible results:
    -1: Your guess is higher than the number I picked (i.e. num > pick).
     1: Your guess is lower than the number I picked (i.e. num < pick).
     0: your guess is equal to the number I picked (i.e. num == pick).

  Return the number that I picked.

  > Example 1:
    Input: n = 10, pick = 6
    Output: 6

  > Example 2:
    Input: n = 1, pick = 1
    Output: 1

  > Example 3:
    Input: n = 2, pick = 1
    Output: 1

 --Inputs:
  -int: max limit

--Outputs:
  -int: picked integer.

--Constraints:
  1 <= n <= 231 - 1
  1 <= pick <= n

--Reasoning: See comments below.

--Time complexity: O(Log(N)), where N is the size of the 'unsorted' array.

--Space complexity: O(1), no additional input-dependent space is allocated.

*/

#include <iostream>

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

int guessNumber(int n) {
  int l = 1;
  int r = n;

  int pick{0};

  while (l <= r) {
    pick = l + (r - l) / 2;
    int howclose = guess(pick);

    if (howclose == 0) // guessed correctly
      break;
    else if (howclose == -1) // guessed a larger value
      r = pick - 1;
    else
      l = pick + 1;
  }
  return pick;
}

int main() {
  // ..

  return 0;
}