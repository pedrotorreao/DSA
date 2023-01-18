/*********************************************************************************************/
/* Problem: 1254. Number of Closed Islands   *************************************************/
/*********************************************************************************************/
/*
--Problem statement:
  Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally
  connected group of 0s and a closed island is an island totally (all left, top, right, bottom)
  surrounded by 1s.

  Return the number of closed islands.

  > Example 1:
  Input: grid = [[1,1,1,1,1,1,1,0],
  `````````````` [1,0,0,0,0,1,1,0],
                 [1,0,1,0,1,1,1,0],
                 [1,0,0,0,0,1,0,1],
                 [1,1,1,1,1,1,1,0]]
  Output: 2
  Explanation:
    Islands are completely surrounded by water (group of 1s).

  > Example 2:
  Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
  Output: 1

  > Example 3:
  Input: grid = [[1,1,1,1,1,1,1],
                 [1,0,0,0,0,0,1],
                 [1,0,1,1,1,0,1],
                 [1,0,1,0,1,0,1],
                 [1,0,1,1,1,0,1],
                 [1,0,0,0,0,0,1],
                 [1,1,1,1,1,1,1]]
  Output: 2

--Inputs:
  -int[][]: 2D grid consisting of 0s (land) and 1s (water)

--Output:
  -int: number of closed islands

--Constraints:
  :: 0 <= grid[i][j] <=1
  :: 1 <= grid.length, grid[0].length <= 100

--Reasoning: See comments below

--Time complexity: O(R*C), where
    R: # of rows
    C: # of columns
    Since we need to traverse the whole 2D grid to find the closed islands;

--Space complexity: O(R*C), where
    R: # of rows
    C: # of columns
    Due to the recursive calls for the worst case where the whole grid is filled with 1s.

*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename T>
void display2D(const std::vector<std::vector<T>> &grid) {
  for (int i{0}; i < grid.size(); ++i) {
    for (int j{0}; j < grid.at(0).size(); ++j) {
      std::cout << grid.at(i).at(j) << "  ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

int dfsCount(std::vector<std::vector<int>> &grid, int row, int col, const int R, const int C) {
  // base case - current cell is beyond grid limits, i.e. invalid:
  if (row >= R || row < 0 || col >= C || col < 0)
    return false;

  // base case - current cell is water:
  if (grid[row][col] == 1 || grid[row][col] == 2)
    return true;

  // set current cell as visited:
  grid[row][col] = 2;

  bool closedIsland{true};

  closedIsland &= dfsCount(grid, row + 1, col, R, C);
  closedIsland &= dfsCount(grid, row - 1, col, R, C);
  closedIsland &= dfsCount(grid, row, col + 1, R, C);
  closedIsland &= dfsCount(grid, row, col - 1, R, C);

  return closedIsland;
}

int closedIsland(std::vector<std::vector<int>> &grid) {
  const int ROWS = grid.size();
  const int COLS = grid.at(0).size();

  int closedIslandCount{0};

  for (int r{0}; r < ROWS; ++r) {
    for (int c{0}; c < COLS; ++c) {
      if (grid.at(r).at(c) == 0 && grid.at(r).at(c) != 2) {
        if (dfsCount(grid, r, c, ROWS, COLS))
          ++closedIslandCount;
      }
    }
  }

  return closedIslandCount;
}

int main() {
  std::vector<std::vector<int>> mat{};
  int closedIslands{0};

  mat = {{1, 1, 0, 0, 0},
         {0, 1, 0, 0, 0},
         {0, 0, 1, 1, 0},
         {0, 1, 1, 0, 0},
         {0, 0, 0, 0, 0}};
  std::cout << "-- Original matrix:\n";
  display2D(mat);
  closedIslands = closedIsland(mat);
  std::cout << "Number of closed islands: " << closedIslands << "\n";
  std::cout << "-- -- -- -- --\n\n";

  mat = {{0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0},
         {0, 1, 0, 0, 0},
         {0, 0, 1, 0, 0},
         {0, 0, 0, 0, 0}};
  std::cout << "-- Original matrix:\n";
  display2D(mat);
  closedIslands = closedIsland(mat);
  std::cout << "Number of closed islands: " << closedIslands << "\n";
  std::cout << "-- -- -- -- --\n\n";

  mat = {{1, 1, 1, 1, 1, 1, 1, 0},
         {1, 0, 0, 0, 0, 1, 1, 0},
         {1, 0, 1, 0, 1, 1, 1, 0},
         {1, 0, 0, 0, 0, 1, 0, 1},
         {1, 1, 1, 1, 1, 1, 1, 0}};
  std::cout << "-- Original matrix:\n";
  display2D(mat);
  closedIslands = closedIsland(mat);
  std::cout << "Number of closed islands: " << closedIslands << "\n";
  std::cout << "-- -- -- -- --\n\n";

  mat = {{0, 0, 1, 0, 0},
         {0, 1, 0, 1, 0},
         {0, 1, 1, 1, 0}};
  std::cout << "-- Original matrix:\n";
  display2D(mat);
  closedIslands = closedIsland(mat);
  std::cout << "Number of closed islands: " << closedIslands << "\n";
  std::cout << "-- -- -- -- --\n\n";

  return 0;
}