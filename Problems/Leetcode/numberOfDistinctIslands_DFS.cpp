/*********************************************************************************************/
/* Problem: 694. Number of Distinct Islands (DFS)  *******************************************/
/*********************************************************************************************/
/*
--Problem statement:
  You are given a 2D matrix containing only 1s (land) and 0s (water). An island is a connected
  set of 1s (land) and is surrounded by either an edge or 0s (water). Each cell is considered
  connected to other cells horizontally or vertically (not diagonally).
  Two islands are considered the same if and only if they can be translated (not
  rotated or reflected) to equal each other.
  Write a function to find the number of distinct islands in the given matrix.

--Inputs:
  -int[][]: 2D grid consisting of 0s (land) and 1s (water)

--Output:
  -int: number of distinct islands found.

--Reasoning:
  We use DFS to traverse the island and record the path taken to traverse each island.
  Then, we use a hashset DS to only store this recorded path unique entries. This way, since
  equal islands will have the same traversed paths and hashsets do not allow duplicate entries,
  even if we try to add them to the set, it will keep one instance stored. The hashset will
  then contain all the distinct paths. Thus, the amount of distinct islands will be equal to
  the size of the hashset.

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
#include <set>
#include <utility>
#include <vector>

template <typename T>
void display2D(const std::vector<std::vector<T>> &grid);

class DistinctIslands {
public:
  static int getDistinctIslands(const std::vector<std::vector<int>> &grid);

private:
  static void dfsDistinctIslands(const std::vector<std::vector<int>> &grid,
                                 const int ROWS, const int COLS,
                                 int base_r, int base_c,
                                 int curr_r, int curr_c,
                                 std::vector<std::vector<bool>> &visited,
                                 std::vector<std::pair<int, int>> &coord);
};

int DistinctIslands::getDistinctIslands(const std::vector<std::vector<int>> &grid) {
  if (!grid.size())
    return 0;

  const int R = grid.size();       // # of rows in the grid
  const int C = grid.at(0).size(); // # of cols in the grid

  // boolean grid to mark visited cells:
  std::vector<std::vector<bool>> visitedCells(R, std::vector<bool>(C, false));
  // hashset to store the unique paths traversed:
  std::set<std::vector<std::pair<int, int>>> islandCoordinates;

  for (int r{0}; r < R; ++r) {
    for (int c{0}; c < C; ++c) {
      // explore land cells which are unvisited:
      if (grid.at(r).at(c) == 1 && !visitedCells.at(r).at(c)) {
        // vector to store the pairs of coordenates:
        std::vector<std::pair<int, int>> coordinates;

        DistinctIslands::dfsDistinctIslands(grid, R, C, r, c, r, c, visitedCells, coordinates);

        // add traversal path to hash set:
        islandCoordinates.insert(coordinates);
      }
    }
  }

  return islandCoordinates.size();
}

void DistinctIslands::dfsDistinctIslands(const std::vector<std::vector<int>> &grid,
                                         const int ROWS, const int COLS,
                                         int base_r, int base_c,
                                         int curr_r, int curr_c,
                                         std::vector<std::vector<bool>> &visited,
                                         std::vector<std::pair<int, int>> &coord) {

  // base case - current cell is outside of limits:
  if (curr_r < 0 || curr_r >= ROWS || curr_c < 0 || curr_c >= COLS)
    return;
  // base case - current cell is water or have been visited before:
  if (grid.at(curr_r).at(curr_c) == 0 || visited.at(curr_r).at(curr_c))
    return;
  // mark cell as visited:
  visited.at(curr_r).at(curr_c) = true;

  int x = curr_r - base_r;
  int y = curr_c - base_c;

  // add current cell to the path:
  coord.push_back({x, y});

  dfsDistinctIslands(grid, ROWS, COLS, base_r, base_c, curr_r + 1, curr_c, visited, coord); // down
  dfsDistinctIslands(grid, ROWS, COLS, base_r, base_c, curr_r - 1, curr_c, visited, coord); // up
  dfsDistinctIslands(grid, ROWS, COLS, base_r, base_c, curr_r, curr_c + 1, visited, coord); // right
  dfsDistinctIslands(grid, ROWS, COLS, base_r, base_c, curr_r, curr_c - 1, visited, coord); // left
}

int main() {
  std::vector<std::vector<int>> mat{};
  int distinctIslands{0};

  mat = {{1, 1, 0, 1, 1},
         {1, 1, 0, 1, 1},
         {0, 0, 0, 0, 0},
         {0, 1, 1, 0, 1},
         {0, 1, 1, 0, 1}};
  std::cout << "-- Grid:\n";
  display2D(mat);
  distinctIslands = DistinctIslands::getDistinctIslands(mat);
  std::cout << "Number of distinct islands: " << distinctIslands << "\n";
  std::cout << "-- -- -- -- --\n\n";

  mat = {{1, 1, 0, 1},
         {0, 1, 1, 0},
         {0, 0, 0, 0},
         {1, 1, 0, 0},
         {0, 1, 1, 0}};
  std::cout << "-- Grid:\n";
  display2D(mat);
  distinctIslands = DistinctIslands::getDistinctIslands(mat);
  std::cout << "Number of distinct islands: " << distinctIslands << "\n";
  std::cout << "-- -- -- -- --\n\n";

  mat = {{1, 1, 0, 1, 1},
         {1, 0, 0, 0, 0},
         {0, 0, 0, 0, 1},
         {1, 1, 0, 1, 1}};
  std::cout << "-- Grid:\n";
  display2D(mat);
  distinctIslands = DistinctIslands::getDistinctIslands(mat);
  std::cout << "Number of distinct islands: " << distinctIslands << "\n";
  std::cout << "-- -- -- -- --\n\n";

  return 0;
}

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