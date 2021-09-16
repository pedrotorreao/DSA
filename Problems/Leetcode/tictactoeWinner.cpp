/****************************************************************/
/* Problem: Find Winner on a Tic Tac Toe Game (LC) ********/
/****************************************************************/
/*
Tic-tac-toe is played by two players A and B on a 3 x 3 grid.
Here are the rules of Tic-Tac-Toe:
  - Players take turns placing characters into empty squares (" ").
  - The first player A always places "X" characters, while the second player B always places "O" characters.
  - "X" and "O" characters are always placed into empty squares, never on filled ones.
  - The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
  - The game also ends if all squares are non-empty.
  - No more moves can be played if the game is over.
Given an array moves where each element is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which A and B play.
Return the winner of the game if it exists (A or B), in case the game ends in a draw return "Draw", if there are still movements to play return "Pending".
You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the grid is initially empty and A will play first.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string tictactoe(vector<vector<int>> &moves)
{
  if (moves.size() < 3)
  {
    return "Pending";
  }

  int size = 3;
  vector<vector<string>> mat(size, vector<string>(size, "-"));

  // fill the board:
  for (int i{0}; i < moves.size(); i++)
  {
    int rowNumber = moves.at(i).at(0);
    int colNumber = moves.at(i).at(1);

    if (i % 2 == 0)
    {
      mat.at(rowNumber).at(colNumber) = "X";
    }
    else
    {
      mat.at(rowNumber).at(colNumber) = "O";
    }
  }

  for (size_t i{0}; i < size; i++)
  {
    // check columns:
    if (mat[i][0] == mat[i][1] && mat[i][0] == mat[i][2])
    {
      if (mat[i][0] != "-")
      {
        return (mat.at(i).at(0) == "X" ? "A" : "B");
      }
    }
    // check rows:
    if (mat[0][i] == mat[1][i] && mat[0][i] == mat[2][i])
    {
      if (mat[0][i] != "-")
      {
        return (mat.at(0).at(i) == "X" ? "A" : "B");
      }
    }
  }

  // check diagonals:
  if ((mat[0][0] == mat[1][1] && mat[0][0] == mat[2][2]) || (mat[2][0] == mat[1][1] && mat[2][0] == mat[0][2]))
  {
    if (mat[1][1] != "-")
    {
      return (mat[1][1] == "X" ? "A" : "B");
    }
  }

  // a tic tac toe game has at most 9 possible moves, if no solution was found
  // and there are moves left, return "Pending":
  if (moves.size() < 9)
  {
    return "Pending";
  }

  // otherwise, if no solution was found and there are no movements left, it's a draw:
  return "Draw";
}

int main()
{
  vector<vector<int>> moves1 = {{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}};
  cout << "Result of game 1: " << tictactoe(moves1) << "\n";

  vector<vector<int>> moves2 = {{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}};
  cout << "Result of game 2: " << tictactoe(moves2) << "\n";

  vector<vector<int>> moves3 = {{0, 0}, {1, 1}, {2, 0}, {1, 0}, {1, 2}, {2, 1}, {0, 1}, {0, 2}, {2, 2}};
  cout << "Result of game 3: " << tictactoe(moves3) << "\n";

  vector<vector<int>> moves4 = {{0, 0}, {1, 1}};
  cout << "Result of game 4: " << tictactoe(moves4) << "\n";

  vector<vector<int>> moves5 = {{0, 2}, {0, 1}, {2, 1}};
  cout << "Result of game 5: " << tictactoe(moves5) << "\n";

  vector<vector<int>> moves6 = {{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}};
  cout << "Result of game 6: " << tictactoe(moves6) << "\n";

  return 0;
}