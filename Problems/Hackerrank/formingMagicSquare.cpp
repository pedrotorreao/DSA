/*********************************************************************************************/
/* Problem: Forming a Magic Square (HR) ********/
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
#include <vector>
#include <limits>

void matrixToVector(std::vector<std::vector<int>> &matrix, std::vector<int> &vec);

int formingMagicSquare(std::vector<std::vector<int>> s)
{
  int min_cost = std::numeric_limits<int>::max();

  // all 8 possible magic squares stored in linear format:
  std::vector<std::vector<int>> magicSquares{{8, 3, 4, 1, 5, 9, 6, 7, 2},
                                             {4, 3, 8, 9, 5, 1, 2, 7, 6},
                                             {6, 7, 2, 1, 5, 9, 8, 3, 4},
                                             {6, 1, 8, 7, 5, 3, 2, 9, 4},
                                             {2, 7, 6, 9, 5, 1, 4, 3, 8},
                                             {4, 9, 2, 3, 5, 7, 8, 1, 6},
                                             {2, 9, 4, 7, 5, 3, 6, 1, 8},
                                             {8, 1, 6, 3, 5, 7, 4, 9, 2}};

  std::vector<int> linearS;
  // transform original matrix from 2D to 1D:
  matrixToVector(s, linearS);

  // compare the linear matrix with the cached magic squares and calculate the cost
  // for each of them:
  for (int i{0}; i < magicSquares.size(); ++i)
  {
    int curr_cost{0};
    for (int j{0}; j < linearS.size(); ++j)
    {
      curr_cost += abs(magicSquares.at(i).at(j) - linearS.at(j));
    }
    min_cost = std::min(curr_cost, min_cost);
  }

  return min_cost;
}

int main()
{
  std::vector<std::vector<int>> mat{{5, 3, 4},
                                    {1, 5, 8},
                                    {6, 4, 2}};
  std::cout << "Min. cost: " << formingMagicSquare(mat) << "\n"; // Expected: 7

  return 0;
}

void matrixToVector(std::vector<std::vector<int>> &matrix, std::vector<int> &vec)
{
  for (int i{0}; i < matrix.size(); ++i)
  {
    for (int j{0}; j < matrix.size(); ++j)
    {
      vec.push_back(matrix.at(i).at(j));
    }
  }
}