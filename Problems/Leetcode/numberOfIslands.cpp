/*********************************************************************************************/
/* Problem: LC 200. Number of Islands ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
  return the number of islands. An island is surrounded by water and is formed by connecting
  adjacent lands horizontally or vertically. You may assume all four edges of the grid are all
  surrounded by water.

  > Example 1:
      Input: grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
      ]
      Output: 1

  > Example 2:
      Input: grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
      ]
      Output: 3

--Inputs:
  -char[][]: 2d array of characters.

--Output:
  -int: number of islands found.

--Constraints:
    :: m == grid.length
    :: n == grid[i].length
    :: 1 <= m, n <= 300
    :: grid[i][j] is '0' or '1'.

--Reasoning: See comments below.

--Time complexity:
  O(N), because in the worst case we'll traverse the same cell 5 times (once while processing the
  current cell itself and 4 times adjacent cell calls)

--Space complexity:
  O(1), considering that the recursive calls will not take any additional space. However, recursive
  calls require stack memory, so if stack memory is sufficient and it is possible to neglect it, then
  the space complexity is O(1). However, in this case, the memory used will be:
    number of recursive calls: O(R*C), for the worst case where all cells have '1'
    memory used for each rec. call, i.e. arguments, mem_used_each_call
      => O(R*C * mem_used_each_call)

*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void exploreDFS(std::vector<std::vector<char>> &grid, int row, int col, int R, int C) {
  // base case - out of bounds, i.e. water:
  if (row < 0 || row >= R || col < 0 || col >= C)
    return;
  // base case - cell is already visited:
  if (grid.at(row).at(col) == '2')
    return;
  // base case - cell is water, skip it:
  if (grid.at(row).at(col) == '0')
    return;

  // mark current cell as visited:
  grid.at(row).at(col) = '2';

  exploreDFS(grid, row - 1, col, R, C); // go up
  exploreDFS(grid, row + 1, col, R, C); // go down
  exploreDFS(grid, row, col - 1, R, C); // go left
  exploreDFS(grid, row, col + 1, R, C); // go right
}

int numIslands(std::vector<std::vector<char>> &grid) {
  // check for an empty grid:
  if (!grid.size())
    return 0;

  const int ROWS = grid.size();       // number of ROWS
  const int COLS = grid.at(0).size(); // number of COLS

  int num_of_islands{0}; // result: number of islands found

  for (int r{0}; r < ROWS; ++r) {
    for (int c{0}; c < COLS; ++c) {
      if (grid.at(r).at(c) == '1') {
        ++num_of_islands;
        exploreDFS(grid, r, c, ROWS, COLS);
      }
    }
  }

  return num_of_islands;
}

int main() {
  std::vector<std::vector<char>> grid;
  int exp{0}, res{0};

  // test case #1:
  grid = {{'1', '1', '1', '1', '0'},
          {'1', '1', '0', '1', '0'},
          {'1', '1', '0', '0', '0'},
          {'0', '0', '0', '0', '0'}};
  exp = 1;
  res = numIslands(grid);
  std::cout << ":: Test case #1: " << res << " islands found\t-Expected " << exp
            << ((exp == res) ? "\t[PASSED]" : "\t[FAILED]") << "\n";

  // test case #2:
  grid = {{'1', '1', '0', '0', '0'},
          {'1', '1', '0', '0', '0'},
          {'0', '0', '1', '0', '0'},
          {'0', '0', '0', '1', '1'}};
  exp = 3;
  res = numIslands(grid);
  std::cout << ":: Test case #2: " << res << " islands found\t-Expected " << exp
            << ((exp == res) ? "\t[PASSED]" : "\t[FAILED]") << "\n";

  // test case #3:
  grid = {{'1', '1', '1', '1', '1'},
          {'1', '1', '1', '1', '1'},
          {'1', '1', '1', '1', '1'},
          {'1', '1', '1', '1', '1'}};
  exp = 1;
  res = numIslands(grid);
  std::cout << ":: Test case #3: " << res << " islands found\t-Expected " << exp
            << ((exp == res) ? "\t[PASSED]" : "\t[FAILED]") << "\n";

  // test case #4:
  grid = {{'0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '0'}};
  exp = 0;
  res = numIslands(grid);
  std::cout << ":: Test case #4: " << res << " islands found\t-Expected " << exp
            << ((exp == res) ? "\t[PASSED]" : "\t[FAILED]") << "\n";

  // test case #5:
  grid = {{'1', '0', '1', '0', '1'},
          {'0', '1', '0', '1', '0'},
          {'1', '0', '1', '0', '1'},
          {'0', '1', '0', '1', '0'}};
  exp = 10;
  res = numIslands(grid);
  std::cout << ":: Test case #5: " << res << " islands found\t-Expected " << exp
            << ((exp == res) ? "\t[PASSED]" : "\t[FAILED]") << "\n";

  // test case #6:
  grid = {{'0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '1'}};
  exp = 1;
  res = numIslands(grid);
  std::cout << ":: Test case #6: " << res << " islands found\t-Expected " << exp
            << ((exp == res) ? "\t[PASSED]" : "\t[FAILED]") << "\n";

  // test case #7:
  grid = {{'1', '0', '1', '1', '0', '1', '1'}};
  exp = 3;
  res = numIslands(grid);
  std::cout << ":: Test case #6: " << res << " islands found\t-Expected " << exp
            << ((exp == res) ? "\t[PASSED]" : "\t[FAILED]") << "\n";

  return 0;
}