/*********************************************************************************************/
/* Problem: LC 695. Max Area Of Island ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
  connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid
  are surrounded by water.
  The area of an island is the number of cells with a value 1 in the island.
  Return the maximum area of an island in grid. If there is no island, return 0.

  > Example 1:
  Input:
    grid = [  [0,0,1,0,0,0,0,1,0,0,0,0,0],
              [0,0,0,0,0,0,0,1,1,1,0,0,0],
              [0,1,1,0,1,0,0,0,0,0,0,0,0],
              [0,1,0,0,1,1,0,0,1,0,1,0,0],
              [0,1,0,0,1,1,0,0,1,1,1,0,0],
              [0,0,0,0,0,0,0,0,0,0,1,0,0],
              [0,0,0,0,0,0,0,1,1,1,0,0,0],
              [0,0,0,0,0,0,0,1,1,0,0,0,0]
            ]
    Output: 6
    Explanation: The answer is not 11, because the island must be connected 4-directionally.

  > Example 2:
    Input: grid = [[0,0,0,0,0,0,0,0]]
    Output: 0

--Inputs:
  - int[][]: 2d matrix of integers

--Output:
  - int: maximum area calculated

--Constraints:
  :: m == grid.length
  :: n == grid[i].length
  :: 1 <= m, n <= 50
  :: grid[i][j] is either 0 or 1.

--Reasoning: See comments below.

--Time complexity: O(N*M), N being the number of rows and M the number of columns in the grid.

--Space complexity:
  O(N*M), due to the recursion stack for the worst case in which the whole matrix is filled with 1's.

*/

#include <iostream>
#include <vector>

class Solution {
public:
  static int maxAreaOfIsland(std::vector<std::vector<int>> &matrix) {
    const int ROWS = matrix.size(),
              COLS = matrix.at(0).size();

    int biggestIslandArea = 0, currentIslandArea = 0;

    for (int r{0}; r < ROWS; ++r) {
      for (int c{0}; c < COLS; ++c) {
        // perform a DFS in case we've reached an unvisited land cell:
        if (matrix.at(r).at(c) == 1) {
          measureIsland(matrix, r, c, ROWS, COLS, currentIslandArea);
        }
        // update max value in case we've found a larger island:
        biggestIslandArea = std::max(biggestIslandArea, currentIslandArea);
        currentIslandArea = 0;
      }
    }

    return biggestIslandArea;
  }

  static void measureIsland(std::vector<std::vector<int>> &m,
                            int r, int c, int R, int C,
                            int &area) {
    // base case - current cell is out of bounds:
    if (r < 0 || r >= R || c < 0 || c >= C)
      return;
    // base case - current cell is water:
    if (m.at(r).at(c) == 0)
      return;
    // base case - current cell has been visited:
    if (m.at(r).at(c) == 2)
      return;

    // mark cell is visited:
    m.at(r).at(c) = 2;
    // add current cell to current' island area:
    ++area;

    // move up:
    measureIsland(m, r - 1, c, R, C, area);
    // move left:
    measureIsland(m, r, c - 1, R, C, area);
    // move down:
    measureIsland(m, r + 1, c, R, C, area);
    // move right:
    measureIsland(m, r, c + 1, R, C, area);
  }
};

int main() {
  std::vector<std::vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  std::cout << "Max. area of island: " << Solution::maxAreaOfIsland(grid) << "\n\n";

  return 0;
}