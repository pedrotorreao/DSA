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

--Output:
  - string: either 'First' or 'Second'.

--Reasoning:
  More about the Nim game: https://en.wikipedia.org/wiki/Nim#Mathematical_theory
  (1) In case we have a single pile, if there is more than one stone, then the first player will always win by leaving the last stone for the second player.
  (2) In case the sum of all the stones is equal to the number of piles, that means that every pile has only one stone. If this is the case, for an even number of piles the first player will win, since the last pile containing exactly one stone will be left to the second player.
  (3) For all remaining cases, the XOR value between all the piles determines the winner. If the XOR value is 0, that means that the piles can be paired and the second player will be the winner.

--Constraints:
  1<=T<=100;  1<=n<=100;  1<=s[i]<=10^9

--Time complexity: O(N), where N is the length of the input array.

--Space complexity: O(1), no input-dependent space is allocated.

*/

#include <iostream>
#include <string>
#include <vector>

std::string misereNim(std::vector<int> s)
{
  int total_sum{0}, nim_sum{0};

  for (const auto &pile : s)
  {
    total_sum += pile;
    nim_sum ^= pile;
  }

  bool all_piles_have_one_stone = (total_sum == s.size());

  if (all_piles_have_one_stone)
  {
    if (s.size() % 2 == 0)
    {
      return "First";
    }
    return "Second";
  }
  else
  {
    if (nim_sum == 0)
    {
      return "Second";
    }
    return "First";
  }
}

int main()
{
  std::vector<int> vec{1, 1, 1};
  std::cout << "The winner is: " << misereNim(vec) << "\n"; // Expected: Second

  vec = {1, 2, 2};
  std::cout << "The winner is: " << misereNim(vec) << "\n"; // Expected: First

  return 0;
}