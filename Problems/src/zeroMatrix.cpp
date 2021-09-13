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
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>

/* Helper method (forward declaration) - Find matrix positions of the zeroes: */
void findZeroes(const std::vector<std::vector<int>> &m, std::list<std::pair<int, int>> &zp);

/* Solution (forward declaration): */
void zeroMatrix(std::vector<std::vector<int>> &m);

/* Helper method (forward declaration) - Display matrix data: */
void displayMatrix(const std::vector<std::vector<int>> &m);

/* Driver code */
int main()
{
  std::vector<std::vector<int>> matrix = {{1, 2, 3, 4},
                                          {5, 6, 7, 0},
                                          {9, 0, 11, 12},
                                          {13, 14, 15, 16}};

  std::cout << "----original matrix: \n";
  displayMatrix(matrix);

  std::cout << "---- matrix zeroed: \n";
  zeroMatrix(matrix);
  displayMatrix(matrix);

  return 0;
}

/* Solution: */
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