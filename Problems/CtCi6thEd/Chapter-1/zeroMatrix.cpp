/*********************************************************************************************/
/* Problem: Zero Matrix (CtCi 1.8) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Write an algorithm such as that if an element in an MxN matrix is 0, its entira row and column
  are set to zero.

--Reasoning:
  Scan the matrix using function 'findZeroes' to get the indexes (rows and columns) of elements
  equal to zero and store these pairs into a list. After that, while the list is not empty, get 
  a new pair of ids, pop it from the list, fix the row and clear the column, and fix the column
  and clear the row.

Solution 1: 
--Time complexity: O(M*N) if P < M and P < N
    'findZeroes': O(M*N)
    'zeroMatrix': O(P*M), or O(P*N) if N > M. P is the size of the list of ids of elements equal to zero.
    The total running time will depend on the size of P:
      O(M*N): 
          P < M and P < N (i.e. number of zero elements is less than the size of the rows and columns)
      O(M*P): 
          P < M and P > N (i.e. number of zero elements is less than the size of the rows)
      O(P*N):
          P > M and P < N (i.e. number of zero elements is less than the size of the columns)
          
--Space complexity: O(P), we use P additional space for storing the ids of the element equal to zero.

Solution 2:
--Time complexity: O(M*N), where M is the number of rows and N is the number of columns
    'setColToZero': O(M)
    'setRowToZero': O(N)

--Space complexity: O(1), no additional space needed.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>

/* ---------------- FORWARD DECLARATIONS ---------------- */
/* Helper method - Find matrix positions of the zeroes: */
void findZeroes(const std::vector<std::vector<int>> &m, std::list<std::pair<int, int>> &zp);
/* Helper method - Set column elements to zero: */
void setColToZero(std::vector<std::vector<int>> &m, int colID, int R);
/* Helper method - Set row elements to zero: */
void setRowToZero(std::vector<std::vector<int>> &m, int rowID, int C);
/* Helper method - Display matrix data: */
void displayMatrix(const std::vector<std::vector<int>> &m);

/* Solution 1 - Uses extra space: */
void zeroMatrix(std::vector<std::vector<int>> &m);

/* Solution 2 - No extra space used: */
void setMatrixZeros(std::vector<std::vector<int>> &m);
/* ------------------------------------------------------ */

/* --------------------- DRIVER CODE -------------------- */
int main()
{
  std::vector<std::vector<int>> matrix = {{1, 2, 3, 4},
                                          {5, 6, 7, 0},
                                          {9, 0, 11, 12},
                                          {13, 14, 15, 16}};

  std::cout << "----original matrix: \n";
  displayMatrix(matrix);

  std::cout << "---- matrix zeroed: \n";
  //zeroMatrix(matrix);
  setMatrixZeros(matrix);
  displayMatrix(matrix);

  return 0;
}
/* ------------------------------------------------------ */

/* ---------------- FUNCTION DEFINITIONS ---------------- */
/* Solution 1 (forward declaration) - Uses extra space: */
void zeroMatrix(std::vector<std::vector<int>> &m)
{
  std::list<std::pair<int, int>> zeroPosList; // list for storing the pairs of ids
  std::pair<int, int> ids;

  findZeroes(m, zeroPosList); // get the positions of the zeroes

  while (!zeroPosList.empty()) // run while there are still rows and columns to be zeroed
  {
    ids = zeroPosList.front();
    zeroPosList.pop_front();

    // zero row:
    for (int j{0}; j < m.at(0).size(); j++)
    {
      m.at(ids.first).at(j) = 0;
    }

    // zero column:
    for (int i{0}; i < m.size(); i++)
    {
      m.at(i).at(ids.second) = 0;
    }
  }
}

/* Solution 2 (forward declaration) - No extra space used: */
void setMatrixZeros(std::vector<std::vector<int>> &m)
{
  const int numOfRows = m.size();
  const int numOfCols = m.at(0).size();

  bool zeroInTheFirstRow = false;

  // ---- 1. Analyze the first row ----
  // Look for zeros in the first row, if there is any, set the
  // flag 'zeroInTheFirstRow' to indicate that this row should
  // be cleared at the end:
  for (int c{0}; c < numOfCols; c++)
  {
    if (m.at(0).at(c) == 0)
    {
      zeroInTheFirstRow = true;
      break;
    }
  }
  // ---- 2. Clearing the rows except the first ----
  // Look for zeros in the rest of the matrix. If there is any,
  // set the first element (1st row) of its column to zero and
  // set the flag that indicate that the row is to be cleared:
  for (int r{1}; r < numOfRows; r++)
  {
    bool rowHasZero = false;
    for (int c{0}; c < numOfCols; c++)
    {
      if (m.at(r).at(c) == 0)
      {
        m.at(0).at(c) = 0;
        rowHasZero = true;
      }
    }
    if (rowHasZero)
    {
      setRowToZero(m, r, numOfCols);
    }
  }
  // ---- 3. Clearing the columns ----
  // Iterate through the first row and look for the elements set
  // to zero (to indicate that the column has to be cleared) at
  // the previous step. If any zero is found, clear column:
  for (int c{0}; c < numOfCols; c++)
  {
    bool colHasZero = false;
    if (m.at(0).at(c) == 0)
    {
      colHasZero = true;
    }
    if (colHasZero)
    {
      setColToZero(m, c, numOfRows);
    }
  }
  // ---- 4. Clearing the first row ----
  // The first row was used in step 2. to indicate the columns that
  // must be cleared. Now, it is time to clear this row if it is the
  // case:
  if (zeroInTheFirstRow)
  {
    setRowToZero(m, 0, numOfCols);
  }
}

/* Helper method - Find matrix positions of the zeroes: */
void findZeroes(const std::vector<std::vector<int>> &m, std::list<std::pair<int, int>> &zp)
{
  for (int i{0}; i < m.size(); i++)
  {
    for (int j{0}; j < m.at(0).size(); j++)
    {
      if (m.at(i).at(j) == 0)
      {
        zp.push_back(std::make_pair(i, j));
      }
    }
  }
}

/* Helper method (forward declaration) - Set row elements to zero: */
void setRowToZero(std::vector<std::vector<int>> &m, int rowID, int C)
{
  for (int j{0}; j < C; j++)
  {
    m.at(rowID).at(j) = 0;
  }
}

/* Helper method (forward declaration) - Set column elements to zero: */
void setColToZero(std::vector<std::vector<int>> &m, int colID, int R)
{
  for (int i{0}; i < R; i++)
  {
    m.at(i).at(colID) = 0;
  }
}

/* Helper method - Display matrix data: */
void displayMatrix(const std::vector<std::vector<int>> &m)
{
  for (int i{0}; i < m.size(); i++)
  {
    for (int j{0}; j < m.size(); j++)
    {
      std::cout << std::setw(3) << std::left << m.at(i).at(j) << " ";
    }
    std::cout << "\n";
  }
}
/* ------------------------------------------------------ */