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

--Space complexity:

*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int numIslands(std::vector<std::vector<char>> &grid) {
  if (grid.size() == 1)
    return (grid.at(0).at(0) == '1');

  const int ROWS = grid.size();       // number of ROWS
  const int COLS = grid.at(0).size(); // number of COLS

  std::queue<std::pair<int, int>> q_pos; // queue to store the positions to be processed
  q_pos.push(std::make_pair(0, 0));      // start position: [row,col] = [0,0]

  int num_of_islands{0}; // result: number of islands found

  bool water_up{false}, water_down{false}, water_right{false}, water_left{false};
  std::vector<std::pair<int, int>> neighbors;

  while (!q_pos.empty()) {
    std::pair<int, int> curr_pos = q_pos.front();
    q_pos.pop();

    int curr_row_id = curr_pos.first;
    int curr_col_id = curr_pos.second;

    if ((curr_row_id == ROWS - 1) && (curr_col_id == COLS - 1))
      break;

    // ...
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

  // test case #1:
  grid = {{'0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '1'}};
  exp = 1;
  res = numIslands(grid);
  std::cout << ":: Test case #6: " << res << " islands found\t-Expected " << exp
            << ((exp == res) ? "\t[PASSED]" : "\t[FAILED]") << "\n";

  return 0;
}