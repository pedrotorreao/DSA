/*********************************************************************************************/
/* Problem: 694. Number of Distinct Islands (BFS)  *******************************************/
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
#include <queue>
#include <string>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>

template <typename T>
void display2D(const std::vector<std::vector<T>> &grid);

class DistinctIslands {
public:
  static int getDistinctIslands(const std::vector<std::vector<int>> &grid);

private:
  static void bfsDistinctIslands(const std::vector<std::vector<int>> &grid,
                                 const int ROWS, const int COLS,
                                 int curr_r, int curr_c,
                                 std::vector<std::vector<bool>> &visited,
                                 std::string &path, std::string direction);
};

int DistinctIslands::getDistinctIslands(const std::vector<std::vector<int>> &grid) {
  if (!grid.size())
    return 0;

  const int R = grid.size();       // # of rows in the grid
  const int C = grid.at(0).size(); // # of cols in the grid

  // boolean grid to mark visited cells:
  std::vector<std::vector<bool>> visitedCells(R, std::vector<bool>(C, false));
  // hashset to store the unique paths traversed:
  std::unordered_set<std::string> islandPath;

  for (int r{0}; r < R; ++r) {
    for (int c{0}; c < C; ++c) {
      // explore land cells which are unvisited:
      if (grid.at(r).at(c) == 1 && !visitedCells.at(r).at(c)) {
        // string to store the path directions:
        std::string traversalPath;

        DistinctIslands::bfsDistinctIslands(grid, R, C, r, c, visitedCells, traversalPath, "O"); // "O": origin cell for the current island

        // add traversal path to hash set:
        islandPath.insert(traversalPath);
      }
    }
  }

  return islandPath.size();
}

void DistinctIslands::bfsDistinctIslands(const std::vector<std::vector<int>> &grid,
                                         const int ROWS, const int COLS,
                                         int curr_r, int curr_c,
                                         std::vector<std::vector<bool>> &visited,
                                         std::string &path, std::string direction) {

  //  store nodes be to visited next in a queue of tuples, where:
  //  tuple<int, int, string> {row, col, direction}
  std::queue<std::tuple<int, int, std::string>> neighbors;

  // add first land cell to the queue:
  neighbors.push(std::make_tuple(curr_r, curr_c, direction));

  while (!neighbors.empty()) {
    // current cell:
    auto curr = neighbors.front();
    neighbors.pop();

    int row = std::get<0>(curr);
    int col = std::get<1>(curr);
    std::string dir = std::get<2>(curr);

    // base case - current cell is beyond grid limits, i.e. invalid:
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
      continue;

    // base case - we've reached the water or the cell have been visited already:
    if (grid.at(row).at(col) == 0 || visited.at(row).at(col))
      continue;

    // mark current cell as visited:
    visited.at(row).at(col) = true;

    // add current cell' direction the traversal path:
    path += dir;

    neighbors.push(std::make_tuple(row + 1, col, "D")); // down
    neighbors.push(std::make_tuple(row - 1, col, "U")); // up
    neighbors.push(std::make_tuple(row, col + 1, "R")); // right
    neighbors.push(std::make_tuple(row, col - 1, "L")); // left
  }

  path += "B"; // "B": back, marks the end of the current island
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