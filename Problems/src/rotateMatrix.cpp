/*********************************************************************************************/
/* Problem: Rotate Matrix (CtCi 1.7) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write
  a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <iostream>
#include <vector>

/* Solution #1:
  method: std::vector<std::vector<int>> rotateMatrix_Copy(const std::vector<std::vector<int>> &m)

--Time complexity: O(n^2), where n is the number of elements in each line of the matrix.
--Space complexity: O(n^2).

Slow solution as we iterate over all the elements in the nxn matrix. Also, as we create a new nxn
matrix for the rotated elements, memory usage can also get heavy.
*/
std::vector<std::vector<int>> rotateMatrix_Copy(const std::vector<std::vector<int>> &m);

/* Solution #2: TO BE ADDED
  method: void rotateMatrix_InPlace(std::vector<std::vector<int>> &m)

--Time complexity: 
--Space complexity: 

*/

void displayMatrix(const std::vector<std::vector<int>> &m);

int main()
{
  std::vector<std::vector<int>> matrix{{1, 2, 3},
                                       {4, 5, 6},
                                       {7, 8, 9}};

  std::cout << "original matrix: \n";
  displayMatrix(matrix);

  std::cout << "matrix rotated 90deg: \n";
  displayMatrix(rotateMatrix_Copy(matrix));

  matrix = {{1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}};

  std::cout << "original matrix: \n";
  displayMatrix(matrix);

  std::cout << "matrix rotated 90deg: \n";
  displayMatrix(rotateMatrix_Copy(matrix));

  return 0;
}

std::vector<std::vector<int>> rotateMatrix_Copy(const std::vector<std::vector<int>> &m)
{
  std::vector<std::vector<int>> m_90;

  int n = m.size();

  for (int c{0}; c < n; c++)
  {
    std::vector<int> new_line;

    for (int r{n - 1}; r >= 0; r--)
    {
      new_line.push_back(m.at(r).at(c));
    }

    m_90.push_back(new_line);
  }

  return m_90;
}

void displayMatrix(const std::vector<std::vector<int>> &m)
{
  for (int i{0}; i < m.size(); i++)
  {
    for (int j{0}; j < m.size(); j++)
    {
      std::cout << m.at(i).at(j) << " ";
    }
    std::cout << "\n";
  }
}
