/********************************************************************************************************/
/* Problem: Number of Paths to reach last cell given the total cost - Divide & Conquer Approach   *******/
/********************************************************************************************************/
/*
-- Problem Statement:
  Given a 2D matrix and a total cost, knowing that each cell value represents the cost of accessing that cell,
  find out the amount of paths that is possible to use to go from the first cell in the matrix to the last cell
  in the exact cost given.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

int numberOfPathsHelper(std::vector<std::vector<int>> mat, int row, int col, int totalCost)
{
  // ---------------- base cases ----------------:

  // a. totalCost is negative, which means that current
  // path cost more than our given cost, so it's not a
  // valid path, return 0:
  if (totalCost < 0)
  {
    return 0;
  }
  // b. we got to the first cell, we need to check if our current
  // budget minus the cost of this cell is inside of our given cost,
  // if it is, this is a valid path, return 1, if not, this path
  // costs more than our budget, return 0:
  if (row == 0 && col == 0)
  {
    return ((totalCost - mat.at(row).at(col) == 0) ? 1 : 0);
  }

  // ---------------- edge cases ----------------:

  // a. row is out of bounds, not possible to move up anymore, move left:
  if (row < 0)
  {
    return numberOfPathsHelper(mat, row + 1, col - 1, totalCost);
  }
  // b. col is out of bounds, not possible to move left anymore, move up:
  if (col < 0)
  {
    return numberOfPathsHelper(mat, row - 1, col + 1, totalCost);
  }
  // c. we are already at the first row, it's only possible to move left:
  if (row == 0)
  {
    return numberOfPathsHelper(mat, row, col - 1, totalCost - mat.at(row).at(col));
  }
  // d. we are already at the first column, it's only possible to move up:
  if (col == 0)
  {
    return numberOfPathsHelper(mat, row - 1, col, totalCost - mat.at(row).at(col));
  }

  // ---------------- recursive cases ----------------:

  // a. move up and check if path is valid:
  int goUp = numberOfPathsHelper(mat, row - 1, col, totalCost - mat.at(row).at(col));
  // b. move left and check if path is valid:
  int goLeft = numberOfPathsHelper(mat, row, col - 1, totalCost - mat.at(row).at(col));

  // the sum of the results of going in both directions gives the number
  // os paths we can take while remaing within the threshold of the given cost:
  return (goUp + goLeft);
}

int numberOfPathsToMinCost(std::vector<std::vector<int>> mat, int totalCost)
{
  int rows = mat.size() - 1;
  int cols = mat.at(0).size() - 1;

  return numberOfPathsHelper(mat, rows, cols, totalCost);
}

int main()
{
  std::vector<std::vector<int>> matrix{{4, 7, 8, 6, 4},
                                       {6, 7, 3, 9, 2},
                                       {3, 8, 1, 2, 4},
                                       {7, 1, 7, 3, 7},
                                       {2, 9, 8, 9, 3}};
  int cost{36};
  std::cout << "Number of possible ways to go from first cell to last cell with cost "
            << cost << ": "
            << numberOfPathsToMinCost(matrix, cost) << "\n";

  matrix = {{1, 6, 7, 9},
            {3, 8, 1, 2},
            {9, 5, 7, 4},
            {2, 8, 3, 1}};
  cost = 20;
  std::cout << "Number of possible ways to go from first cell to last cell with cost "
            << cost << ": "
            << numberOfPathsToMinCost(matrix, cost) << "\n";

  matrix = {{4, 7, 1, 6},
            {5, 7, 3, 9},
            {3, 2, 1, 2},
            {7, 1, 6, 3}};
  cost = 25;
  std::cout << "Number of possible ways to go from first cell to last cell with cost "
            << cost << ": "
            << numberOfPathsToMinCost(matrix, cost) << "\n";

  matrix = {{1, 1, 1, 7},
            {1, 9, 1, 1},
            {1, 2, 1, 1},
            {1, 1, 1, 1}};
  cost = 7;
  std::cout << "Number of possible ways to go from first cell to last cell with cost "
            << cost << ": "
            << numberOfPathsToMinCost(matrix, cost) << "\n";

  return 0;
}