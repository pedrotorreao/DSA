/*********************************************************************************************/
/* Problem: 1559. Detect Cycles in 2D Grid  **************************************************/
/*********************************************************************************************/
/*
--Problem statement:
  Given a 2D array of characters "grid" of size m x n, you need to find if there exists any cycle
  consisting of the same value in "grid". A cycle is a path of length 4 or more in the "grid"
  that starts and ends at the same cell. From a given cell, you can move to one of the cells
  adjacent to it - in one of the four directions (up, down, left, or right), if it has the same
  value of the current cell.

  Also, you cannot move to the cell that you visited in your last move. For example, the cycle
  (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last
  visited cell.

  Return true if any cycle of the same value exists in "grid", otherwise, return false.

  > Example 1:
    Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
    Output: true
    Explanation: There are two valid cycles.

  > Example 2:
    Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
    Output: true
    Explanation: There is only one valid cycle.

  > Example 3:
    Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
    Output: false


--Inputs:
  -char[][]: 2D grid consisting of characters.

--Output:
  -bool: boolean indicating whether a cycle of the same value exists in "grid".

--Constraints:
  :: m == grid.length
  :: n == grid[i].length
  :: 1 <= m, n <= 500
  :: grid consists only of lowercase English letters.

--Reasoning: See comments below.

--Time complexity: O(R*C), where
    R: # of rows
    C: # of columns
    Since we need to traverse the whole 2D grid looking for a cycle.

--Space complexity: O(R*C), where
    R: # of rows
    C: # of columns
    Due to the recursive calls for the worst case where the whole grid is filled with the same character.

*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

template <typename T>
void display2D(const std::vector<std::vector<T>> &grid);

class GridCycleDetector {
public:
  static bool containsCycle(const std::vector<std::vector<char>> &grid);

private:
  static void cycleDetectorDFS(const std::vector<std::vector<char>> &grid,
                               std::vector<std::vector<bool>> &visited,
                               const int ROWS, const int COLS,
                               int currRow, int currCol, int prevRow, int prevCol,
                               char currentChar,
                               bool &hasCycle);

  static void cycleDetectorBFS(const std::vector<std::vector<char>> &grid,
                               std::vector<std::vector<bool>> &visited,
                               const int ROWS, const int COLS,
                               int currRow, int currCol, int prevRow, int prevCol,
                               char currentChar,
                               bool &hasCycle);
};

bool GridCycleDetector::containsCycle(const std::vector<std::vector<char>> &grid) {
  const int ROWS = grid.size();
  const int COLS = grid.at(0).size();

  if (ROWS <= 1 || COLS <= 1)
    return false;

  std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

  char currentCharacter{' '};
  bool hasCycle{false};

  for (int r{0}; r < ROWS; ++r) {
    for (int c{0}; c < COLS; ++c) {
      if (!visited.at(r).at(c)) {
        currentCharacter = grid.at(r).at(c);
        cycleDetectorBFS(grid, visited, ROWS, COLS, r, c, -1, -1, currentCharacter, hasCycle);

        if (hasCycle)
          break;
      }
    }
  }

  return hasCycle;
}

void GridCycleDetector::cycleDetectorDFS(const std::vector<std::vector<char>> &grid,
                                         std::vector<std::vector<bool>> &visited,
                                         const int ROWS, const int COLS,
                                         int currRow, int currCol, int prevRow, int prevCol,
                                         char currentChar,
                                         bool &hasCycle) {
  // base case - current cell is outside of limits:
  if (currRow < 0 || currRow >= ROWS || currCol < 0 || currCol >= COLS)
    return;

  // base case - current cell contains a different character:
  if (grid.at(currRow).at(currCol) != currentChar)
    return;

  // base case - we got to the same cell again, we've found a cycle:
  if (visited.at(currRow).at(currCol)) {
    hasCycle = true;
    return;
  }

  // mark current cell as visited:
  visited.at(currRow).at(currCol) = true;

  // make sure we don't recurse to the predecessor node, as this would result in a false positive:
  if (currRow + 1 != prevRow)
    cycleDetectorDFS(grid, visited, ROWS, COLS, currRow + 1, currCol, currRow, currCol, currentChar, hasCycle); // down
  if (currRow - 1 != prevRow)
    cycleDetectorDFS(grid, visited, ROWS, COLS, currRow - 1, currCol, currRow, currCol, currentChar, hasCycle); // up
  if (currCol + 1 != prevCol)
    cycleDetectorDFS(grid, visited, ROWS, COLS, currRow, currCol + 1, currRow, currCol, currentChar, hasCycle); // right
  if (currCol - 1 != prevCol)
    cycleDetectorDFS(grid, visited, ROWS, COLS, currRow, currCol - 1, currRow, currCol, currentChar, hasCycle); // left
}

void GridCycleDetector::cycleDetectorBFS(const std::vector<std::vector<char>> &grid,
                                         std::vector<std::vector<bool>> &visited,
                                         const int ROWS, const int COLS,
                                         int currR, int currC, int prevRow, int prevCol,
                                         char currentChar,
                                         bool &hasCycle) {

  std::queue<std::pair<int, int>> neighbors;
  neighbors.push({currR, currC});

  while (!neighbors.empty()) {
    auto p = neighbors.front();
    neighbors.pop();

    int currRow = p.first;
    int currCol = p.second;

    // base case - current cell is outside of limits:
    if (currRow < 0 || currRow >= ROWS || currCol < 0 || currCol >= COLS)
      continue;

    // base case - current cell contains a different character:
    if (grid.at(currRow).at(currCol) != currentChar)
      continue;

    // base case - we got to the same cell again, we've found a cycle:
    if (visited.at(currRow).at(currCol)) {
      hasCycle = true;
      return;
    }

    // mark current cell as visited:
    visited.at(currRow).at(currCol) = true;

    // make sure we don't recurse to the predecessor node, as this would result in a false positive:
    if (currRow + 1 != prevRow)
      neighbors.push({currRow + 1, currCol}); // down
    if (currRow - 1 != prevRow)
      neighbors.push({currRow - 1, currCol}); // up
    if (currCol + 1 != prevCol)
      neighbors.push({currRow, currCol + 1}); // right
    if (currCol - 1 != prevCol)
      neighbors.push({currRow, currCol - 1}); // left

    prevRow = currRow;
    prevCol = currCol;
  }
}

int main() {
  std::cout << std::boolalpha;

  std::vector<std::vector<char>> mat{};
  bool isThereACycle{false};

  mat = {{'a', 'a', 'a', 'a'},
         {'b', 'a', 'c', 'a'},
         {'b', 'a', 'c', 'a'},
         {'b', 'a', 'a', 'a'}};
  std::cout << "-- Grid:\n";
  display2D(mat);
  isThereACycle = GridCycleDetector::containsCycle(mat);
  std::cout << "There is a cycle is the grid above: " << isThereACycle << "\n";
  std::cout << "-- -- -- -- --\n\n";

  mat = {{'a', 'a', 'a', 'a'},
         {'a', 'b', 'b', 'a'},
         {'a', 'b', 'a', 'a'},
         {'a', 'a', 'a', 'c'}};
  std::cout << "-- Grid:\n";
  display2D(mat);
  isThereACycle = GridCycleDetector::containsCycle(mat);
  std::cout << "There is a cycle is the grid above: " << isThereACycle << "\n";
  std::cout << "-- -- -- -- --\n\n";

  mat = {{'a', 'b', 'e', 'b'},
         {'b', 'b', 'c', 'b'},
         {'b', 'c', 'c', 'd'},
         {'d', 'c', 'd', 'd'}};
  std::cout << "-- Grid:\n";
  display2D(mat);
  isThereACycle = GridCycleDetector::containsCycle(mat);
  std::cout << "There is a cycle is the grid above: " << isThereACycle << "\n";
  std::cout << "-- -- -- -- --\n\n";

  mat = {{'a', 'a', 'a', 'a'},
         {'a', 'b', 'b', 'a'},
         {'a', 'b', 'b', 'a'},
         {'a', 'a', 'a', 'a'}};
  std::cout << "-- Grid:\n";
  display2D(mat);
  isThereACycle = GridCycleDetector::containsCycle(mat);
  std::cout << "There is a cycle is the grid above: " << isThereACycle << "\n";
  std::cout << "-- -- -- -- --\n\n";

  mat = {{'c', 'c', 'c', 'a'},
         {'c', 'd', 'c', 'c'},
         {'c', 'c', 'e', 'c'},
         {'f', 'c', 'c', 'c'}};
  std::cout << "-- Grid:\n";
  display2D(mat);
  isThereACycle = GridCycleDetector::containsCycle(mat);
  std::cout << "There is a cycle is the grid above: " << isThereACycle << "\n";
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