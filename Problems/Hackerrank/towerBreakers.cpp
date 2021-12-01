/*********************************************************************************************/
/* Problem: Tower Breakers (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Two players are playing a game of Tower Breakers! Player 1 always moves first, and both players
  always play optimally.The rules of the game are as follows:
    >> Initially there are n towers.
    >> Each tower is of height m.
    >> The players move in alternating turns.
    >> In each turn, a player can choose a tower of height x and reduce its height to y, where
    1<=y<x and y evenly divides x.
    >> If the current player is unable to make a move, they lose the game.
  Given the values of n and m, determine which player will win. If the first player wins, return 1.
  Otherwise, return 2.

  > Example: n = 2, m = 6
    There are 2 towers, each 6 units tall. Player has a choice of two moves:
      - remove 3 pieces from a tower to leave 3 as 6mod3=0.
      - remove 5 pieces to leave 1.
    Let Player 1 remove 3. Now the towers are 3 and 6 units tall.
    Player 2 matches the move. Now the towers are both 3 units tall.
    Now Player 1 has only one move. Player 1 removes 2 pieces leaving 1. Towers are 1 and 2 units tall.
    Player 2 matches again. Towers are both 1 unit tall.
    Player 1 has no move and loses. Return 2.

--Reasoning:
  The approach is quite simple. As Player 1 always makes the first move and both players always play
  optimally, if the number of towers is odd, Player 1 will always make the last move unless that the
  initial height of the towers is already m=1. Otherwise, if the total number of towers is even,
  Player 2 will be the winner.

--Time complexity: O(1)

--Space complexity: O(1)
*/

#include <iostream>

int towerBreakers(int n, int m)
{
  if ((n % 2 != 0) && (m != 1))
  {
    return 1;
  }
  return 2;
}

int main()
{
  int n{2}, m{6};
  std::cout << "The Winner is Player " << towerBreakers(n, m) << "\n"; // Expected P2

  n = 1;
  m = 4;
  std::cout << "The Winner is Player " << towerBreakers(n, m) << "\n"; // Expected P1

  n = 100000;
  m = 1;
  std::cout << "The Winner is Player " << towerBreakers(n, m) << "\n"; // Expected P2

  n = 100001;
  m = 1;
  std::cout << "The Winner is Player " << towerBreakers(n, m) << "\n"; // Expected P1

  return 0;
}