/*********************************************************************************************/
/* Problem: Castle on the grid (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are given a square grid with some cells open (.) and some blocked (X). Your playing piece
  can move along any row or column until it reaches the edge of the grid or a blocked cell.
  Given a grid, a start and a goal, determine the minimum number of moves to get to the goal.
  Example:
    grid = ['...','.X.','...']
    startX = 0
    startY = 0
    goalX = 1
    goalY = 2
    The starting position (startX, startY) = (0,0) so start in the top left corner. The goal is
    (goalX, goalY) = (1,2). The path is (0,0) -> (0,2) -> (1,2). It takes 2 moves to reach the
    goal.

--Reasoning:

--Time complexity:

--Space complexity:

*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <limits.h>

// --------------- HELPERS: FORWARD DECLARATIONS -----------------:

void buildAdjMatrix(std::vector<std::string> &gridVec, std::vector<std::vector<char>> &gridMat, const int &r, const int &c);

void displayMatrix(std::vector<std::vector<int>> &gridMat);

bool positionIsValid(const std::vector<std::vector<bool>> &visited, const std::vector<std::vector<char>> &gridMat, const int &r, const int &c);

// ---------------------------------------------------------------

// --------------------------- SOLUTION --------------------------:
int minimumMoves(std::vector<std::string> grid, int src_X, int src_Y, int end_X, int end_Y)
{
  // check if source and destination are not the same position:
  if ((src_X == end_X) && (src_Y == end_Y))
  {
    return 0;
  }
  // variable to track the number of moves taken:
  int move_count{1};

  // number of rows and columns in the grid:
  const int ROWS = grid.size();
  const int COLS = grid.at(0).size();

  // queues for storing elements coordinates:
  std::queue<int> q_rows;
  std::queue<int> q_cols;

  // build the 2D matrix (is there a way around this?):
  std::vector<std::vector<char>> gridMatrix(ROWS, std::vector<char>(COLS, ' '));
  buildAdjMatrix(grid, gridMatrix, ROWS, COLS);

  // matrix for tracking the visited nodes:
  std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

  // direction vectors:
  const std::vector<int> dir_row{-1, 1, 0, 0};
  const std::vector<int> dir_col{0, 0, 1, -1};

  // boolean to indicate if we found a path to the destination:
  bool pathFound{false};

  // enqueue source coordinates:
  q_rows.push(src_X);
  q_cols.push(src_Y);

  // mark source element as visited:
  visited.at(src_X).at(src_Y) = true;

  int prev_row{src_X};
  int prev_col{src_Y};

  // while neither one of the queues are empty:
  while (!q_rows.empty() && !q_cols.empty())
  {
    // enqueue the next cell to be explored:
    int curr_row = q_rows.front();
    int curr_col = q_cols.front();

    q_rows.pop();
    q_cols.pop();

    // check if the new coordinates matches destination:
    if ((curr_row == end_X) && (curr_col == end_Y))
    {
      pathFound = true;
      break;
    }

    // explore neighbour nodes (4 movement directions possible):
    for (int i{0}; i < 4; i++)
    {
      int new_row = curr_row + dir_row.at(i);
      int new_col = curr_col + dir_col.at(i);

      if (positionIsValid(visited, gridMatrix, new_row, new_col))
      {
        q_rows.push(new_row);
        q_cols.push(new_col);

        visited.at(new_row).at(new_col) = true;
      }
    }
    if ((prev_row != curr_row) && (prev_col != curr_col))
    {
      move_count++;
      prev_row = curr_row;
      prev_col = curr_col;
    }
  }

  if (pathFound)
    return move_count;
  else
    return -1;
}
// ---------------------------------------------------------------

// ----------------------- DRIVER CODE ---------------------------:
int main()
{
  std::vector<std::string> grid{"...", ".X.", "..."};
  int sx{0}, sy{0}, gx{1}, gy{2};

  // std::vector<std::vector<std::string>> mat(grid.size(), std::vector<std::string>(grid.size()));

  // std::cout << "grid:\n";
  // displayMatrix(mat);
  // std::cout << "min. number of moves from ["
  //           << sx << "," << sy << "] to ["
  //           << gx << "," << gy << "]: " << minimumMoves(grid, sx, sy, gx, gy);
  std::cout << "minimum moves: " << minimumMoves(grid, sx, sy, gx, gy) << "\n";

  grid = {".X.", ".X.", "..."};
  sx = 0;
  sy = 0;
  gx = 0;
  gy = 2;

  std::cout << "minimum moves: " << minimumMoves(grid, sx, sy, gx, gy) << "\n";

  return 0;
}
// ---------------------------------------------------------------:

// -------------------- HELPERS: DEFINITIONS ---------------------:

/**
 * @brief buildMatrix: processes the input vector and lays its
 * data on a adjacency matrix format/grid.
 *
 * @param gridVec
 * @param gridMat
 */
void buildAdjMatrix(std::vector<std::string> &gridVec, std::vector<std::vector<char>> &gridMat, const int &r, const int &c)
{
  for (int i{0}; i < r; i++)
  {
    for (int j{0}; j < c; j++)
    {
      gridMat.at(i).at(j) = gridVec.at(i).at(j);
    }
  }
}

/**
 * @brief positionIsValid: checks if the current grid position is valid to be explored.
 *
 * @param visited
 * @param r
 * @param c
 * @return true
 * @return false
 */
bool positionIsValid(const std::vector<std::vector<bool>> &visited, const std::vector<std::vector<char>> &gridMat, const int &r, const int &c)
{
  // number of rows and columns in the grid:
  const int R = visited.size();
  const int C = visited.at(0).size();

  // cell is out of bounds:
  if (r < 0 || c < 0 || r >= R || c >= C)
  {
    return false;
  }

  // cell is blocked:
  if (gridMat.at(r).at(c) == 'X')
  {
    return false;
  }

  // cell has already been visited:
  if (visited.at(r).at(c) == true)
  {
    return false;
  }

  return true;
}

/**
 * @brief displayMatrix: simple helper for printing out matrices to the console
 *
 * @param gridMat
 */
void displayMatrix(std::vector<std::vector<int>> &gridMat)
{
  auto rows = gridMat.size();
  auto cols = gridMat.at(0).size();

  for (auto i{0}; i < rows; i++)
  {
    for (auto j{0}; j < cols; j++)
    {
      std::cout << gridMat.at(i).at(j) << "  ";
    }
    std::cout << "\n";
  }
}
