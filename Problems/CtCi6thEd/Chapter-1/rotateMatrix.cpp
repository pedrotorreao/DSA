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

/* Solution #1 - Copy method: */
std::vector<std::vector<int>> rotateMatrix_Copy(const std::vector<std::vector<int>> &m);

/* Solution #2 - In-place method: */
void rotateMatrix_InPlace(std::vector<std::vector<int>> &m);

/* Helper method - Display matrix data: */
void displayMatrix(const std::vector<std::vector<int>> &m);

int main()
{
  std::vector<std::vector<int>> matrix{{1, 2, 3},
                                       {4, 5, 6},
                                       {7, 8, 9}};

  std::cout << "#### Rotate NxN Matrix 90deg ####\n";
  std::cout << "---- original matrix: \n";
  displayMatrix(matrix);

  std::cout << "---- matrix rotated 90deg - Copy method: \n";
  displayMatrix(rotateMatrix_Copy(matrix));
  std::cout << "---- matrix rotated 90deg - In-place method: \n";
  rotateMatrix_InPlace(matrix);
  displayMatrix(matrix);

  std::cout << "\n";

  matrix = {{1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}};

  std::cout << "\toriginal matrix: \n";
  displayMatrix(matrix);

  std::cout << "\tmatrix rotated 90deg - Copy method: \n";
  displayMatrix(rotateMatrix_Copy(matrix));
  std::cout << "\tmatrix rotated 90deg - In-place method: \n";
  rotateMatrix_InPlace(matrix);
  displayMatrix(matrix);

  return 0;
}

/* Solution #1 - Copy method:
  method: std::vector<std::vector<int>> rotateMatrix_Copy(const std::vector<std::vector<int>> &m)

--Reasoning: iterate through the matrix copying the columns to a new array, and as we finish copying
a column, we add this newly created array as a line in the matrix.

--Time complexity: O(n^2), where n is the number of elements in each line of the matrix.
--Space complexity: O(n^2).

Slow solution as we iterate over all the elements in the nxn matrix. Also, as we create a new nxn
matrix for the rotated elements, memory usage is heavy since it depends directly on the size of the
input matrix.
*/
std::vector<std::vector<int>> rotateMatrix_Copy(const std::vector<std::vector<int>> &m)
{
  std::vector<std::vector<int>> m_90; // 2d matrix to store rotated elements

  int n = m.size();

  for (int c{0}; c < n; c++)
  {
    std::vector<int> new_line; // array to store each column

    for (int r{n - 1}; r >= 0; r--)
    {
      new_line.push_back(m.at(r).at(c)); // copy column elements
    }

    m_90.push_back(new_line); // insert array as a new line
  }

  return m_90;
}

/* Solution #2 - In-place method: 
  method: void rotateMatrix_InPlace(std::vector<std::vector<int>> &m)

--Reasoning: The goal is to solve the question without using any extra space (space complexity O(1)).
In order to achieve that we're going to rotate the matrix by dividing it into squares or cycles,
beginning from the outer square (1st row, 1st column, last row, last column) and moving to inner squares.
At each cycle we rotate 4 elements of the current square until all elements have been rotated which is
when we move one level inside until all squares have been rotated. In the total, there will be n cycles
until completion.

--Time complexity: O(n^2), where n is the number of elements in each line of the matrix.
--Space complexity: O(1), since space used is independent from the input size (size of the matrix).

*/
void rotateMatrix_InPlace(std::vector<std::vector<int>> &m)
{
  int r = 0, c = 0, cycle = 0;
  int n = m.size() - 1;
  bool done = false;

  while (!done)
  {
    cycle++;

    int temp1 = m.at(r).at(c);         // stores element that will be replaced
    m.at(r).at(c) = m.at(n - c).at(r); // rotate

    int temp2 = m.at(c).at(n - r); // stores element that will be replaced
    m.at(c).at(n - r) = temp1;     // rotate

    temp1 = m.at(n - r).at(n - c); // stores element that will be replaced
    m.at(n - r).at(n - c) = temp2; // rotate

    m.at(n - c).at(r) = temp1; // rotate

    if (cycle == m.size()) // if all cycles were performed, finish while loop
    {
      done = true;
    }
    else if (c == n - 1) // if current all elements in the current square were
    {                    // rotated, move one level deeper
      r++;
      c = r;
    }
    else
    { // move to the next 4 elements in the current square
      c++;
    }
  }
}

/* Helper method - Display matrix data: */
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

/*
  Step by step how the elements are rotated in the 4x4 matrix:

    r=0; c=0                                      r=0; c=1
  temp1 = m[r][c] = m[0][0] = 1                 temp1 = m[r][c] = m[0][1] = 2
  m[0][0] = m[n-c][r] = m[3][0] = 13            m[0][1] = m[n-c][r] = m[2][0] = 9
      
  temp2 = m[c][n-r] = m[0][3] = 4               temp2 = m[c][n-r] = m[1][3] = 8
  m[0][3] = temp1 = 1                           m[1][3] = temp1 = 2

  temp1 = m[n-r][n-c] = m[3][3] = 16            temp1 = m[n-r][n-c] = m[3][2] = 15
  m[3][3] = temp2 = 4                           m[3][2] = temp2 = 8

  m[n-c][r] = m[3][0] = temp1 = 16              m[n-c][r] = m[2][0] = temp1 = 15


    r=0; c=2                                      r=1; c=1
  temp1 = m[r][c] = m[0][2] = 3                 temp1 = m[r][c] = m[1][1] = 6
  m[0][2] = m[n-c][r] = m[1][0] = 5             m[1][1] = m[n-c][r] = m[2][1] = 10

  temp2 = m[c][n-r] = m[2][3] = 12              temp2 = m[c][n-r] = m[1][2] = 7
  m[2][3] = temp1 = 3                           m[1][2] = temp1 = 6

  temp1 = m[n-r][n-c] = m[3][1] = 14            temp1 = m[n-r][n-c] = m[2][2] = 11
  m[3][1] = temp2 = 12                          m[2][2] = temp2 = 7

  m[n-c][r] = m[1][0] = temp1 = 14              m[n-c][r] = m[2][1] = temp1 = 11

*/