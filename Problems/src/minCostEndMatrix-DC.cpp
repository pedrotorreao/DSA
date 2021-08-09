/***********************************************************************************/
/* Problem: Min. Cost to Find End of 2D Matrix - Divide & Conquer Approach   *******/
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

int minCostToEndHelper(std::vector<std::vector<int>> mat, int row, int col)
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
    return minCostToEndHelper(mat, row + 1, col - 1);
  }
  // edge case: col is out of bounds, not possible to move left anymore,
  // so move up:
  if (col < 0)
  {
    return minCostToEndHelper(mat, row - 1, col + 1);
  }
  // recursive case: calculate the cost of going in both directions
  // - going up:
  int goUp = mat.at(row).at(col) + minCostToEndHelper(mat, row - 1, col);
  // - going left:
  int goLeft = mat.at(row).at(col) + minCostToEndHelper(mat, row, col - 1);
  // return the minimum value between both results:
  return std::min(goUp, goLeft);
}

int minCostToEnd(std::vector<std::vector<int>> mat)
{
  int rows = mat.size() - 1;
  int cols = mat.at(0).size() - 1;

  return minCostToEndHelper(mat, rows, cols);
}

int main()
{
  std::vector<std::vector<int>> matrix{{4, 7, 8, 6, 4},
                                       {6, 7, 3, 9, 2},
                                       {3, 8, 1, 2, 4},
                                       {7, 1, 7, 3, 7},
                                       {2, 9, 8, 9, 3}};

  std::cout << "Cost to reach the end of the matrix: " << minCostToEnd(matrix) << "\n";

  matrix = {{1, 6, 7, 9},
            {3, 8, 1, 2},
            {9, 5, 7, 4},
            {2, 8, 3, 1}};

  std::cout << "Cost to reach the end of the matrix: " << minCostToEnd(matrix) << "\n";

  return 0;
}