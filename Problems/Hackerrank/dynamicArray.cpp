/*********************************************************************************************/
/* Problem: Dynamic Array (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:

-- Inputs:

--Outputs:

--Reasoning:

--Time complexity:

--Space complexity:

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