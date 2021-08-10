/***********************************************************************************/
/* Problem: Min. Cost to Find End of 2D Matrix - Dynamic Programming Approach ******/
/***********************************************************************************/
/*
-- Proble Statement:
  Given a 2D array M where each cell represents the cost associated with going through
  this cell, what is the minimum cost possible in which we can go from the first cell
  M[0][0] to the last cell M[m-1][n-1] in the array considering that traversal is only 
  possible in the down and right directions?
-- Reasoning:
  We'll begin from the end of the array, cell M[m-1][n-1], where m is the number of rows
  and n is the number os columns. Since we are beginning from the last cell, our movements
  now are restricted to the up and left directions. For each cell, we calculate the cost of
  going both possible ways, recurring until we get to the first cell M[0][0], which 
  represents our base case and we just return its value. The end result will be the minimum
  value between both directions.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

// ---- Top Down Approach - Memoization ----:
int minCostToEndHelper(std::vector<std::vector<int>> mat, std::vector<std::vector<int>> &dp, int row, int col)
{
  // base case: got to mat[0][0], return its value:
  if (row == 0 && col == 0)
  {
    return mat.at(row).at(col);
  }
  // edge case: row is out of bounds, not possible to move up anymore,
  // so move left:
  if (row < 0)
  {
    return minCostToEndHelper(mat, dp, row + 1, col - 1);
  }
  // edge case: col is out of bounds, not possible to move left anymore,
  // so move up:
  if (col < 0)
  {
    return minCostToEndHelper(mat, dp, row - 1, col + 1);
  }
  // in case we have not solved this problem previously:
  if (!dp.at(row).at(col))
  {
    // recursive case: calculate the cost of going in both directions
    // - going up:
    int goUp = mat.at(row).at(col) + minCostToEndHelper(mat, dp, row - 1, col);
    // - going left:
    int goLeft = mat.at(row).at(col) + minCostToEndHelper(mat, dp, row, col - 1);

    // store the minimum value between both results:
    dp.at(row).at(col) = std::min(goUp, goLeft);
  }

  return dp.at(row).at(col);
}

int minCostToEndTD(std::vector<std::vector<int>> mat)
{
  int rows = mat.size() - 1;
  int cols = mat.at(0).size() - 1;

  std::vector<std::vector<int>> memo(rows + 1, std::vector<int>(cols + 1));

  return minCostToEndHelper(mat, memo, rows, cols);
}

// ---- Bottom Up Approach - Tabulation ----:
int minCostToEndBU(std::vector<std::vector<int>> mat)
{
  int rows = mat.size();
  int cols = mat.at(0).size();

  std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1));

  for (int i{0}; i <= cols; i++)
  {
    dp.at(0).at(i) = INT_MAX;
  }

  for (int i{0}; i <= rows; i++)
  {
    dp.at(i).at(0) = INT_MAX;
  }

  dp.at(0).at(1) = 0; // make sure that first comparison goes through successfully

  for (int r{1}; r <= rows; r++)
  {
    for (int c{1}; c <= cols; c++)
    {
      // current min value is the minimum value between going down and going left plus
      // the cost associated with the current cell:
      dp.at(r).at(c) = std::min(dp.at(r - 1).at(c), dp.at(r).at(c - 1)) + mat.at(r - 1).at(c - 1);
    }
  }

  return dp.at(rows).at(cols);
}

// ---- Driver code: ----:
int main()
{
  std::vector<std::vector<int>> matrix{{4, 7, 8, 6, 4},
                                       {6, 7, 3, 9, 2},
                                       {3, 8, 1, 2, 4},
                                       {7, 1, 7, 3, 7},
                                       {2, 9, 8, 9, 3}};

  std::cout << "Cost to reach the end of the matrix:\n"
            << "\tTop Down: " << minCostToEndTD(matrix) << "\n"
            << "\tBottom Up: " << minCostToEndBU(matrix) << "\n"; //36

  matrix = {{1, 6, 7, 9},
            {3, 8, 1, 2},
            {9, 5, 7, 4},
            {2, 8, 3, 1}};

  std::cout << "Cost to reach the end of the matrix:\n"
            << "\tTop Down: " << minCostToEndTD(matrix) << "\n"
            << "\tBottom Up: " << minCostToEndBU(matrix) << "\n"; //20

  return 0;
}