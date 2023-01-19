/*********************************************************************************************/
/* Problem: 463. Island Perimeter  ***********************************************************/
/*********************************************************************************************/
/*
--Problem statement:
  You are given row x col 'grid' representing a map where grid[i][j] = 1 represents land and
  grid[i][j] = 0 represents water. Grid cells are connected horizontally/vertically (not
  diagonally). The grid is completely surrounded by water, and there is exactly one island
  (i.e., one or more connected land cells). The island doesn't have "lakes", meaning the water
  inside isn't connected to the water around the island. One cell is a square with side length 1.
  The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the
  island.

  > Example 1:
    Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
    Output: 16
    Explanation: The perimeter is the 16 yellow stripes in the image above.

  > Example 2:
    Input: grid = [[1]]
    Output: 4

  > Example 3:
    Input: grid = [[1,0]]
    Output: 4

--Inputs:
  -int[][]: 2D grid consisting of 0s (land) and 1s (water)

--Output:
  -int: perimeter of the island.

--Constraints:
  :: row == grid.length
  :: col == grid[i].length
  :: 1 <= row, col <= 100
  :: grid[i][j] is 0 or 1.
  :: There is exactly one island in grid.

--Reasoning:
  We use DFS/BFS to traverse the island and find all of its connected land cells. To calculate
  the perimeter, we must only take into account the sides of the cells which are shared with
  water or sit on the edge of the grid, since shared sides between land cells are not part of
  the perimeter.

--Time complexity: O(R*C), where
    R: # of rows
    C: # of columns
    Since we may need to traverse the whole 2D grid to find the single island;

--Space complexity: O(R*C), where
    R: # of rows
    C: # of columns
    Due to the recursive calls for the worst case where the whole grid is filled with 1s.

*/

#include <iostream>
#include <vector>

class PerimeterCalculator {
public:
  static int getIslandPerimeter(const std::vector<std::vector<int>> &grid);

private:
  static int perimeterDFS(std::vector<std::vector<int>> &grid, const int R, const int C, int r, int c);
};

int PerimeterCalculator::getIslandPerimeter(const std::vector<std::vector<int>> &grid) {
  if (!grid.size())
    return 0;

  const int ROWS = grid.size();
  const int COLS = grid.at(0).size();

  std::vector<std::vector<int>> grid_cpy(grid);
  int islandPerimeter{0};

  for (int row{0}; row < ROWS; ++row) {
    for (int col{0}; col < COLS; ++col) {
      if (grid_cpy.at(row).at(col) == 1) {
        islandPerimeter = PerimeterCalculator::perimeterDFS(grid_cpy, ROWS, COLS, row, col);
      }
    }
  }

  return islandPerimeter;
}

int PerimeterCalculator::perimeterDFS(std::vector<std::vector<int>> &grid, const int R, const int C, int r, int c) {
  // base case - current cell is outside of limits, so previous cell was on the edge,
  // include this side:
  if (r < 0 || r >= R || c < 0 || c >= C)
    return 1;

  // base case - current cell is water, so previous cell shares a side with water,
  // include this side:
  if (grid[r][c] == 0)
    return 1;

  // base case - current was already visited, do not count it:
  if (grid[r][c] == 2)
    return 0;

  // mark cell as visited:
  grid[r][c] = 2;

  int perim{0};

  perim += perimeterDFS(grid, R, C, r + 1, c);
  perim += perimeterDFS(grid, R, C, r - 1, c);
  perim += perimeterDFS(grid, R, C, r, c + 1);
  perim += perimeterDFS(grid, R, C, r, c - 1);

  return perim;
}

int main() {
  std::vector<std::vector<int>> mat{};
  int islandPerimeter{0}, expectedRes{0};

  mat = {{1, 1, 0, 0, 0},
         {0, 1, 0, 0, 0},
         {0, 1, 0, 0, 0},
         {0, 1, 1, 0, 0},
         {0, 0, 0, 0, 0}};
  islandPerimeter = PerimeterCalculator::getIslandPerimeter(mat);
  expectedRes = 14;
  std::cout << "Island perimeter: " << islandPerimeter
            << (islandPerimeter == expectedRes ? "     [PASSED]\n\n" : "     [FAILED]\n\n");

  mat = {{0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0},
         {0, 1, 0, 0, 0},
         {0, 1, 1, 0, 0},
         {0, 1, 0, 0, 0}};
  islandPerimeter = PerimeterCalculator::getIslandPerimeter(mat);
  expectedRes = 12;
  std::cout << "Island perimeter: " << islandPerimeter
            << (islandPerimeter == expectedRes ? "     [PASSED]\n\n" : "     [FAILED]\n\n");

  return 0;
}