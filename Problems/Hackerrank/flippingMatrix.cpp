/*********************************************************************************************/
/* Problem: Flipping Matrix (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Sean invented a game involving a 2nx2n matrix where each cell of the matrix contains an integer.
  He can reverse any of its rows or columns any number of times. The goal of the game is to
  maximize the sum of the elements in the nxn submatrix located in the upper-left quadrant of
  the matrix.

  > Example:
    matrix = [[1,2],[3,4]]
    Since it is a 2x2 matrix, the top left quadrant will be a 1x1 matrix.
    Reversing row 1 and then column 0 would give us the maximum possible sum:
    matrix = [[1,2],[3,4]] -> [[1,2],[4,3]] -> [[4,2],[1,3]] --> 4

  > Input: int matrix[2n][2n]: a 2-dimensional array of integers

  > Output: int: the maximum sum possible.

  > Constraints:
      1 <= n <= 128
      0 <= matrix[i][j] <= 4096, where 0 <= i,j < 2*n

--Reasoning:
  For each position in the upper left quadrant, there are 4 possible values
  that could fill that position:
    - the current value itself
    - its row counterpart (upper right - 1 flip)
    - its column counterpart (bottom left - 1 flip)
    - its diagonal counterpart (bottom right - 2 flips)
  For each possible position in the quadrant, calculate these 4 elements, take
  the maximum value and add it to the running result.

--Time complexity: O(n^2), where n is the size of the input matrix.
    f(n) = (n/2)*(n/2) = (n^2)/4 -- drop the constants, O(n^2)

--Space complexity: O(1), no additional space dependent on the input size is needed.

*/

#include <iostream>
#include <vector>
#include <algorithm>

int flippingMatrix(std::vector<std::vector<int>> matrix)
{
  int total_sum{0};

  // calculate the size of the upper quadrant:
  int n_m = matrix.size() / 2;

  // iterate over all elements in the quadrant and for each
  // position check which of the 4 possible values to be flipped would
  // maximize the total sum:
  for (size_t row{0}; row < n_m; row++)
  {
    for (size_t col{0}; col < n_m; col++)
    {
      // all 4 elements that could be flipped to current position in the
      // quadrant:
      int pos_1 = matrix.at(row).at(col);                                 // current element
      int pos_2 = matrix.at(row).at((2 * n_m) - col - 1);                 // upper right
      int pos_3 = matrix.at((2 * n_m) - row - 1).at(col);                 // bottom left
      int pos_4 = matrix.at((2 * n_m) - row - 1).at((2 * n_m) - col - 1); // bottom right (2 flips)

      // take the value that would maximize the sum and add it to the result:
      total_sum += std::max(pos_1, std::max(pos_2, std::max(pos_3, pos_4)));
    }
  }

  return total_sum;
}

int main()
{
  std::vector<std::vector<int>> m{{112, 42, 83, 119},
                                  {56, 125, 56, 49},
                                  {15, 78, 101, 43},
                                  {62, 98, 114, 108}};

  std::cout << "Max sum upper quadrant: " << flippingMatrix(m) << "\n";

  return 0;
}