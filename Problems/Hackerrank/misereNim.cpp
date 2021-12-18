/*********************************************************************************************/
/* Problem: Misere Nim (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Two people are playing game of Misère Nim. The basic rules for this game are as follows:
    a.  The game starts with 'n' piles of stones indexed from 0 to 'n-1'. Each pile 'i' (where
        0<=i<n) has 'si' stones.
    b.  The players move in alternating turns. During each move, the current player must remove
        one or more stones from a single pile.
    c.  The player who removes the last stone loses the game.
  Given the value of 'n' and the number of stones in each pile, determine whether the person who
  wins the game is the first or second person to move. If the first player to move wins, print
  'First' on a new line; otherwise, print 'Second'. Assume both players move optimally.
    > Example:
      a. s = [1,1,1]:
        In this case, player 1 picks a pile, player 2 picks a pile and player 1 has to choose the
        last pile. Player 2 wins so return 'Second'.
      b. s = [1,2,2]:
        There is no permutation of optimal moves where player 2 wins. For example, player 1 chooses
        the first pile. If player 2 chooses 1 from another pile, player 1 will choose the pile with
        2 left. If player 2 chooses a pile of 2, player 1 chooses 1 from the remaining pile leaving
        the last stone for player 2. Return 'First'.

--Inputs:
  - int s[n]: the number of stones in each pile.

--Reasoning:
  - string: either 'First' or 'Second'.

--Constraints:
  1<=T<=100;  1<=n<=100;  1<=s[i]<=10^9

--Time complexity:


--Space complexity:

*/

#include <iostream>
#include <string>
#include <vector>

std::string misereNim(std::vector<int> s)
{
  // ...code
}

int main()
{
  // ...driver code
  return 0;
}