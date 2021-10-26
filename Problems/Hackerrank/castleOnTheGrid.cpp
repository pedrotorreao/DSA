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

void buildMatrix(std::vector<std::string> &gridVec, std::vector<std::vector<std::string>> &gridMat);

void displayMatrix(std::vector<std::vector<std::string>> &gridMat);

int minimumMoves(std::vector<std::string> grid, int startX, int startY, int goalX, int goalY)
{
  // build matrix from grid:
  std::vector<std::vector<std::string>> mat(grid.size(), std::vector<std::string>(grid.size()));
  buildMatrix(grid, mat);

  // .. code
}

int main()
{
  std::vector<std::string> grid{"...", ".X.", "..."};
  int sx{0}, sy{0}, gx{1}, gy{2};

  std::vector<std::vector<std::string>> mat(grid.size(), std::vector<std::string>(grid.size()));

  std::cout << "grid:\n";
  displayMatrix(mat);
  std::cout << "min. number of moves from ["
            << sx << "," << sy << "] to ["
            << gx << "," << gy << "]: " << minimumMoves(grid, sx, sy, gx, gy);

  return 0;
}

void buildMatrix(std::vector<std::string> &gridVec, std::vector<std::vector<std::string>> &gridMat)
{
  int n = gridVec.size();
  int i{0};

  for (int i{0}; i < n; i++)
  {
    for (int j{0}; j < n; j++)
    {
      std::string currentLine = gridVec.at(i);
      char currentStep = currentLine.at(j);

      gridMat.at(i).at(j) = currentStep;
    }
  }
}

void displayMatrix(std::vector<std::vector<std::string>> &gridMat)
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
