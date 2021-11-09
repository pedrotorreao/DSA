/*********************************************************************************************/
/*Problem: Diagonal Difference (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a square matrix, calculate the absolute difference between the sums of its diagonals.
  For example, the square matrix arr is shown below:
      1  2  3
      4  5  6
      9  8  9
  The left-to-right diagonal = (1 + 5 + 9) = 15. The right to left diagonal = (3 + 5 + 9) = 17.
  Their absolute difference is |15 - 17| = 2.

--Input:
  Complete the 'diagonalDifference' function that takes the following parameter:
    > int arr[n][m]: an array of integers

--Output:
    > int: the absolute diagonal difference

--Reasoning:
  Simply iterate over the matrix using two variables to account for the sum of each of the
  diagonals.
    > 'sum_diag1' accounts for the diagonal top-left --> bottom-right
    > 'sum_diag2' accounts for the diagonal top-right --> bottom-left

--Time complexity: O(n), where n is the number of lines/columns in the matrix.

--Space complexity: O(1), no additional space dependent on the input size is used,

*/

#include <iostream>
#include <vector>
#include <cstdlib>

int diagonalDifference(std::vector<std::vector<int>> arr)
{
  int r = arr.size();
  int sum_diag1{0}, sum_diag2{0};

  for (int i{0}; i < r; i++)
  {
    sum_diag1 += arr.at(i).at(i);
    sum_diag2 += arr.at(i).at(r - 1 - i);
  }

  return (abs(sum_diag1 - sum_diag2));
}

int main()
{
  std::vector<std::vector<int>> vec{{1, 2, 3},
                                    {4, 5, 6},
                                    {9, 8, 9}};

  std::cout << "Diagonal Difference: " << diagonalDifference(vec) << "\n"; // Expected: 2

  vec = {{11, 2, 4},
         {4, 5, 6},
         {10, 8, -12}

  };

  std::cout << "Diagonal Difference: " << diagonalDifference(vec) << "\n"; // Expected: 15

  return 0;
}