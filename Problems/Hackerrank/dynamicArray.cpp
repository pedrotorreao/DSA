/*********************************************************************************************/
/* Problem: Dynamic Array (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  - Declare a 2-dimensional array, 'arr', of 'n' empty arrays. All arrays are zero indexed.
  - Declare an integer, 'lastAnswer', and initialize it to 0.
  - There are 2 types of queries, given as an array of strings for you to parse:
    1. Query: 1 x y
        a. Let "idx = ((x^lastAnswer)%n)".
        b. Append the integer y to arr[idx].
    2. Query: 2 x y
        a. Let "idx = ((x^lastAnswer)%n)".
        b. Assign the value "arr[idx][y%size(arr[idx])]" to lastAnswer.
        c. Store the new value of lastAnswer to an answers array.
    Note:
      - ^ is the bitwise XOR operation. is the modulo operator.
      - % is the modulo operator.
    Finally, size(arr[idx]) is the number of elements in arr[idx]

-- Inputs:
  - int n: the number of empty arrays to initialize in 'arr'.
  - string queries[q]: query strings that contain 3 space-separated integers.

--Outputs:
  - int[]: the results of each type 2 query in the order they are presented.

--Reasoning:

--Time complexity:
  O(N), where N is the size of the 'queries' array.

--Space complexity:
  O(A*B), where A and B are the number of rows and columns of the matrix used to process the queries.

*/

#include <iostream>
#include <unordered_map>
#include <vector>

void display(const std::vector<int> &vec);

// Solution #1 - Using a Hash Table to simulate a 2D array:
std::vector<int> dynamicArray_1(int n, std::vector<std::vector<int>> queries)
{
  std::unordered_map<int, std::vector<int>> mat;
  std::vector<int> res;
  int lastAnswer{0};

  for (size_t i{0}; i < queries.size(); ++i)
  {
    int queryType = queries.at(i).at(0);
    int x = queries.at(i).at(1);
    int y = queries.at(i).at(2);

    int idx = ((x ^ lastAnswer) % n);

    switch (queryType)
    {
    case 1:
    {
      mat[idx].push_back(y);
    }
    break;
    case 2:
    {
      int idy = ((y % mat[idx].size()));

      lastAnswer = mat[idx].at(idy);
      res.push_back(lastAnswer);
    }
    break;
    }
  }

  return res;
}

// Solution #2 - Using a C++ vector
std::vector<int> dynamicArray_2(int n, std::vector<std::vector<int>> queries)
{
  std::vector<std::vector<int>> mat(n);
  std::vector<int> res;
  int lastAnswer{0};

  for (size_t i{0}; i < queries.size(); ++i)
  {
    int queryType = queries.at(i).at(0);
    int x = queries.at(i).at(1);
    int y = queries.at(i).at(2);

    int idx = ((x ^ lastAnswer) % n);

    switch (queryType)
    {
    case 1:
    {
      mat[idx].push_back(y);
    }
    break;
    case 2:
    {
      int idy = ((y % mat[idx].size()));

      lastAnswer = mat[idx].at(idy);
      res.push_back(lastAnswer);
    }
    break;
    }
  }

  return res;
}

int main()
{
  int n{2};
  std::vector<std::vector<int>> q{
      {1, 0, 5},
      {1, 1, 7},
      {1, 0, 3},
      {2, 1, 0},
      {2, 1, 1}};

  std::vector<int> res = dynamicArray_1(n, q);
  display(res); // Expected: [7 3]

  res = dynamicArray_2(n, q);
  display(res); // Expected: [7 3]

  return 0;
}

void display(const std::vector<int> &vec)
{
  for (const auto &v : vec)
  {
    std::cout << v << "  ";
  }
  std::cout << "\n";
}