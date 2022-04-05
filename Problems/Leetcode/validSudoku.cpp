/*********************************************************************************************/
/* Problem: Valid Sudoku (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated
  according to the following rules:
    - Each row must contain the digits 1-9 without repetition.
    - Each column must contain the digits 1-9 without repetition.
    - Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

  Note:
    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

  > Example 1:
    Input: board =
              [["5","3",".",".","7",".",".",".","."]
              ,["6",".",".","1","9","5",".",".","."]
              ,[".","9","8",".",".",".",".","6","."]
              ,["8",".",".",".","6",".",".",".","3"]
              ,["4",".",".","8",".","3",".",".","1"]
              ,["7",".",".",".","2",".",".",".","6"]
              ,[".","6",".",".",".",".","2","8","."]
              ,[".",".",".","4","1","9",".",".","5"]
              ,[".",".",".",".","8",".",".","7","9"]]
    Output: true

  > Example 2:
    Input: board =
              [["8","3",".",".","7",".",".",".","."]
              ,["6",".",".","1","9","5",".",".","."]
              ,[".","9","8",".",".",".",".","6","."]
              ,["8",".",".",".","6",".",".",".","3"]
              ,["4",".",".","8",".","3",".",".","1"]
              ,["7",".",".",".","2",".",".",".","6"]
              ,[".","6",".",".",".",".","2","8","."]
              ,[".",".",".","4","1","9",".",".","5"]
              ,[".",".",".",".","8",".",".","7","9"]]
    Output: false
    Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8.
      Since there are two 8's in the top left 3x3 sub-box, it is invalid.

--Inputs:
  - char[][]: 2D character' array representing the board

--Output:
  - boolean: whether the board represents a valid sudoku board or not

--Constraints:
  board.length == 9
  board[i].length == 9
  board[i][j] is a digit 1-9 or '.'.

--Reasoning:
  Iterate over the entire board and, for each cell, check whether that cell is valid or not by
  checking if the value filling that cell can be there or not. The way this validation is done
  is by storing seen values in hash sets and checking if the current value is repeated. If it
  is, the sudoku is not valid, if it's not, keep going.

--Time complexity:
  O(N^2), since we're checking all the elements in the board. However,
  if the lengths of the rows and columns are always 9, one could argue
  that since this lenght is constant, the runtime is always the same,
  O(N*N)=O(9*9)=O(81)->O(1).

--Space complexity:
  O(N), since we store as many elements as there are in each row. However,
  if the lengths of the rows and columns are always 9, one could argue
  that since this lenght is constant, the amount of space allocated is always
  the same.

*/

#include <iomanip>
#include <iostream>
#include <unordered_set>
#include <vector>

bool isValidSudoku(std::vector<std::vector<char>> &board) {
  std::unordered_set<char> row, col;
  std::unordered_set<char> upperL, upperM, upperR;
  std::unordered_set<char> middleL, middleM, middleR;
  std::unordered_set<char> bottomL, bottomM, bottomR;

  for (int r{0}; r < board.size(); ++r) {
    for (int c{0}; c < board.at(0).size(); ++c) {
      // validate rows:
      if (board.at(r).at(c) != '.') {
        char curr = board.at(r).at(c);
        if (row.count(curr) > 0)
          return false;
        else
          row.insert(curr);
      }

      // validate columns:
      if (board.at(c).at(r) != '.') {
        char curr = board.at(c).at(r);
        if (col.count(curr) > 0)
          return false;
        else
          col.insert(curr);
      }

      // validade upper left square:
      if (r < 3 && c < 3 && board.at(r).at(c) != '.') {
        char curr = board.at(r).at(c);
        if (upperL.count(curr) > 0)
          return false;
        else
          upperL.insert(curr);
      }

      // validate upper middle square:
      if (r < 3 && (c > 2 && c < 6) && board.at(r).at(c) != '.') {
        char curr = board.at(r).at(c);
        if (upperM.count(curr) > 0)
          return false;
        else
          upperM.insert(curr);
      }

      // validate upper right square:
      if (r < 3 && c > 5 && board.at(r).at(c) != '.') {
        char curr = board.at(r).at(c);
        if (upperR.count(curr) > 0)
          return false;
        else
          upperR.insert(curr);
      }

      // validate middle left square:
      if ((r > 2 && r < 6) && c < 3 && board.at(r).at(c) != '.') {
        char curr = board.at(r).at(c);
        if (middleL.count(curr) > 0)
          return false;
        else
          middleL.insert(curr);
      }

      // validate middle mid square:
      if ((r > 2 && r < 6) && (c > 2 && c < 6) && board.at(r).at(c) != '.') {
        char curr = board.at(r).at(c);
        if (middleM.count(curr) > 0)
          return false;
        else
          middleM.insert(curr);
      }

      // validate middle right square:
      if ((r > 2 && r < 6) && c > 5 && board.at(r).at(c) != '.') {
        char curr = board.at(r).at(c);
        if (middleR.count(curr) > 0)
          return false;
        else
          middleR.insert(curr);
      }

      // validate bottom left square:
      if (r > 5 && c < 3 && board.at(r).at(c) != '.') {
        char curr = board.at(r).at(c);
        if (bottomL.count(curr) > 0)
          return false;
        else
          bottomL.insert(curr);
      }

      // validate bottom middle square:
      if (r > 5 && (c > 2 && c < 6) && board.at(r).at(c) != '.') {
        char curr = board.at(r).at(c);
        if (bottomM.count(curr) > 0)
          return false;
        else
          bottomM.insert(curr);
      }

      // validate bottom right square:
      if (r > 5 && c > 5 && board.at(r).at(c) != '.') {
        char curr = board.at(r).at(c);
        if (bottomR.count(curr) > 0)
          return false;
        else
          bottomR.insert(curr);
      }
    }
    row.clear();
    col.clear();
  }

  return true;
}

int main() {
  std::cout << std::boolalpha;

  std::vector<std::vector<char>> b{{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
                                   {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
                                   {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
                                   {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
                                   {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
                                   {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
                                   {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};
  std::cout << "Valid Sudoku: " << isValidSudoku(b) << "\n";

  return 0;
}

/* -- Better solutions [Community]:

Solution 1: Hash Set
    The idea is super easy.
    For each row, we create a HashSet to check for duplicates in each row.
    For each column, we also create a HashSet to check for duplicates in each column.
    For each square, we also create a HashSet to check for duplicates in each square, but we need to convert the position (r, c) in the board to square by:
        Square row: sr = r / 3.
        Square col: sc = c / 3.
        Square position: sPos = sr * 3 + sc.

    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        unordered_set<char> rowSet[N];
        unordered_set<char> colSet[N];
        unordered_set<char> squareSet[N];

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char val = board[r][c];
                if (val == '.') continue;
                int sPos = (r / 3) * 3 + c / 3;
                if (rowSet[r].count(val) || colSet[c].count(val) || squareSet[sPos].count(val))
                    return false;
                rowSet[r].insert(val);
                colSet[c].insert(val);
                squareSet[sPos].insert(val);
            }
        }
        return true;
    }

    Complexity:
        Time: O(N^2), where N = 9.
        Space: O(N^2)

*/

/*
 Solution 2: Bitmasking (Beat 100%)
    Since we only need to store 2 states (exist, not exist) and store up to 9 positions.
    So to save space, we can store in the bitmask, i th bit represent the existence of the number i.

    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        vector<int> rows(N), cols(N), squares(N);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (board[r][c] == '.') continue;
                int val = board[r][c] - '0';
                int sPos = (r / 3) * 3 + (c / 3);
                if (getBit(rows[r], val) || getBit(cols[c], val) || getBit(squares[sPos], val))
                    return false;
                rows[r] |= 1 << val;
                cols[c] |= 1 << val;
                squares[sPos] |= 1 << val;
            }
        }
        return true;
    }
    int getBit(int x, int k) {
        return (x >> k) & 1;
    }

    Complexity:
        Time: O(N^2), where N = 9.
        Space: O(N)

*/
