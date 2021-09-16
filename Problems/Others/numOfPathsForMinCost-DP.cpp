/********************************************************************************************************/
/* Problem: Number of Paths to reach last cell given the total cost - Dynamic Programming Approach  *****/
/********************************************************************************************************/
/*
-- Problem Statement:
  Given a 2D matrix and a total cost, knowing that each cell value represents the cost of accessing that cell,
  find out the amount of paths that is possible to use to go from the first cell in the matrix to the last cell
  in the exact cost given considering that traversal is only possible in the down and right directions.
*/
#include <iostream>
#include <vector>

// ---- Top Down Approach - Memoization ----:

int numberOfPathsToMinCostTD(std::vector<std::vector<int>> mat, int r, int c, int cost);

int numOfPathsToLastCellHelper(std::vector<std::vector<int>> mat, std::vector<std::vector<int>> &dp, int r, int c, int cost)
{
  if (cost < 0)
    return 0;

  if (r == 0 && c == 0)
    return ((mat[r][c] - cost) == 0) ? 1 : 0;

  if (dp[r][c] == 0)
  {
    if (r == 0)
      dp[r][c] = numberOfPathsToMinCostTD(mat, 0, c - 1, cost - mat[r][c]);

    else if (c == 0)
      dp[r][c] = numberOfPathsToMinCostTD(mat, r - 1, 0, cost - mat[r][c]);

    else
    {
      int up = numberOfPathsToMinCostTD(mat, r - 1, c, cost - mat[r][c]);
      int down = numberOfPathsToMinCostTD(mat, r, c - 1, cost - mat[r][c]);

      dp[r][c] = up + down;
    }
  }

  return dp[r][c];
}

int numberOfPathsToMinCostTD(std::vector<std::vector<int>> mat, int r, int c, int cost)
{
  std::vector<std::vector<int>> mem(r + 1, std::vector<int>(c + 1));

  return numOfPathsToLastCellHelper(mat, mem, r, c, cost);
}

// ---- Bottom Up Approach - Tabulation ----:

// ---- Driver code: ----:
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
            << numberOfPathsToMinCostTD(matrix, matrix.size() - 1, matrix.at(0).size() - 1, cost) << "\n"; //1

  matrix = {{1, 6, 7, 9},
            {3, 8, 1, 2},
            {9, 5, 7, 4},
            {2, 8, 3, 1}};
  cost = 20;
  std::cout << "Number of possible ways to go from first cell to last cell with cost "
            << cost << ": "
            << numberOfPathsToMinCostTD(matrix, matrix.size() - 1, matrix.at(0).size() - 1, cost) << "\n"; //1

  matrix = {{4, 7, 1, 6},
            {5, 7, 3, 9},
            {3, 2, 1, 2},
            {7, 1, 6, 3}};
  cost = 25;
  std::cout << "Number of possible ways to go from first cell to last cell with cost "
            << cost << ": "
            << numberOfPathsToMinCostTD(matrix, matrix.size() - 1, matrix.at(0).size() - 1, cost) << "\n"; //2

  matrix = {{1, 1, 1, 7},
            {1, 9, 1, 1},
            {1, 2, 1, 1},
            {1, 1, 1, 1}};
  cost = 7;
  std::cout << "Number of possible ways to go from first cell to last cell with cost "
            << cost << ": "
            << numberOfPathsToMinCostTD(matrix, matrix.size() - 1, matrix.at(0).size() - 1, cost) << "\n"; //4

  return 0;
}