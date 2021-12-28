/*********************************************************************************************/
/* Problem: Bomberman (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:

  > Example:

  > Input:

  > Output:

  > Constraints:

--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
#include <vector>

void fillBombs(std::vector<std::string> &grid, std::vector<std::string> &res);
void locateBombs(std::vector<std::pair<int, int>> &bombs, std::vector<std::string> &grid);
void detonateBombs(std::vector<std::pair<int, int>> &bombs, std::vector<std::string> &grid);

std::vector<std::string> bomberMan(int n, std::vector<std::string> grid);

void displayGrid(const std::vector<std::string> &grid);

int main()
{
  std::vector<std::string> grid{"...", ".O.", "..."};
  int n{3};
  std::vector<std::string> res = bomberMan(n, grid);
  displayGrid(res);
  /*
            ...                   O.O
  Initial:  .O.   --> Expected:   ...
            ...                   O.O
  */

  grid = {".......", "...O...", "....O..", ".......", "OO.....", "OO....."};
  n = 3;
  res = bomberMan(n, grid);
  displayGrid(res);
  /*
            .......                   OOO.OOO
  Initial:  ...O...   --> Expected:   OO...OO
            ....O..                   OOO...O
            .......                   ..OO.OO
            OO.....                   ...OOOO
            OO.....                   ...OOOO
  */

  grid = {".......", "...O.O.", "....O..", "..O....", "OO...OO", "OO.O..."};
  n = 9;
  res = bomberMan(n, grid);
  displayGrid(res);
  /*
            .......                   .......
  Initial:  ...O.O.   --> Expected:   ...O.O.
            ....O..                   ...OO..
            ..O....                   ..OOOO.
            OO...OO                   OOOOOOO
            OO.O...                   OOOOOOO

  */

  return 0;
}

void displayGrid(const std::vector<std::string> &grid)
{
  for (const auto &line : grid)
  {
    std::cout << line << "\n";
  }
  std::cout << "\n";
}

std::vector<std::string> bomberMan(int n, std::vector<std::string> grid)
{
  std::vector<std::string> grid_even{grid}; // for N even
  std::vector<std::string> grid_init{grid}; // for N=1
  std::vector<std::string> grid_odd{grid};  // for N odd

  if (n == 1)
    return grid_init;

  if (n % 2 == 0)
  {
    fillBombs(grid, grid_even);

    return grid_even;
  }

  std::vector<std::pair<int, int>> bombsLocation;

  locateBombs(bombsLocation, grid_odd);
  fillBombs(grid, grid_odd);
  detonateBombs(bombsLocation, grid_odd);

  if (n % 4 == 3)
    return grid_odd;

  locateBombs(bombsLocation, grid_odd);
  fillBombs(grid, grid_odd);
  detonateBombs(bombsLocation, grid_odd);

  return grid_odd;
}

void fillBombs(std::vector<std::string> &grid, std::vector<std::string> &res)
{
  size_t rows{grid.size()};
  size_t cols{grid.at(0).size()};

  res.clear();

  std::string allBombs(cols, 'O');

  for (int r{0}; r < rows; ++r)
  {
    res.push_back(allBombs);
  }
}

void locateBombs(std::vector<std::pair<int, int>> &bombs, std::vector<std::string> &grid)
{
  bombs.clear();
  for (int row{0}; row < grid.size(); ++row)
  {
    for (int col{0}; col < grid.at(0).size(); ++col)
    {
      if (grid.at(row).at(col) == 'O')
      {
        auto location = std::make_pair(row, col);
        bombs.push_back(location);
      }
    }
  }
}

void detonateBombs(std::vector<std::pair<int, int>> &bombs, std::vector<std::string> &grid)
{
  auto it = bombs.begin();

  while (it != bombs.end())
  {
    int r = it->first;
    int c = it->second;

    grid.at(r).at(c) = '.';
    if (r + 1 < grid.size())
      grid.at(r + 1).at(c) = '.';
    if (r - 1 >= 0)
      grid.at(r - 1).at(c) = '.';
    if (c + 1 < grid.at(0).size())
      grid.at(r).at(c + 1) = '.';
    if (c - 1 >= 0)
      grid.at(r).at(c - 1) = '.';

    ++it;
  }
}