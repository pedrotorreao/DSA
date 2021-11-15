/*********************************************************************************************/
/* Problem: Flipping Matrix (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Two children, Lily and Ron, want to share a chocolate bar. Each of the squares has an integer on it.
  Lily decides to share a contiguous segment of the bar selected such that:
  - The length of the segment matches Ron's birth month, and,
  - The sum of the integers on the squares is equal to his birth day.
  Determine how many ways she can divide the chocolate.
  > Example:
    s = [2,2,1,3,2]     d = 4       m = 2
    A valid A', B' is A' = [1,0] and B' = [0,2]. Return 'YES'.
    Lily wants to find segments summing to Ron's birth day, d=4 with a length equalling his birth month,
    m=2. In this case, there are two segments meeting her criteria: [2,2] and [1,3].

  > Input:
    int s[n]: the numbers on each of the squares of chocolate
    int d: Ron's birth day
    int m: Ron's birth month

  > Output: int: the number of ways the bar can be divided

  > Constraints:
      1 <= n <= 100
      0 <= s[i] <= 5, where 0 <= i < n
      1 <= d <= 31
      1 <= m <= 12

--Reasoning:
  Iterate over the input array and use a moving window to calculate the sums and compare the results.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

// Solution 1 - Nested for loops
// -- time complexity:
//      O(n*m), where n is the size of the array and m the size of the window.
// -- space complexity: O(1), no additional space dependent on the input size is needed.
int birthday_1(std::vector<int> s, int d, int m)
{
  int window_size{m};
  int numOfWays{0};

  for (int i{0}; i < s.size(); i++)
  {
    int currWindowSum{0};
    for (int j{i}; (j < i + window_size) && (i + window_size <= s.size()); j++)
    {
      currWindowSum += s.at(j);
    }
    if (currWindowSum == d)
    {
      numOfWays++;
    }
  }

  return numOfWays;
}

// Solution 2 - Using C++ STL accumulate function
// -- time complexity:
//      O(n*m), where n is the size of the array and m the size of the window.
// -- space complexity: O(1), no additional space dependent on the input size is needed.
int birthday_2(std::vector<int> s, int d, int m)
{
  int window_size{m};
  int numOfWays{0};

  for (uint i{0}; i < s.size(); i++)
  {
    int sum = 0;
    auto start = s.begin() + i;
    auto end = start + window_size;

    if ((i + window_size <= s.size()) && std::accumulate(start, end, sum) == d)
    {
      numOfWays++;
    }
  }

  return numOfWays;
}

// Solution 3 - Optimized, linear running time
// -- time complexity: O(n), where n is the size of the array.
// -- space complexity: O(n), worst case.
int birthday_3(std::vector<int> s, int d, int m)
{
  int window_size{m};
  int numOfWays{0};
  int currWindowSum{0};
  std::vector<int> windowSums;

  windowSums.reserve(s.size() - window_size + 1);

  // Sum of the elements in the first window:
  for (int i{0}; i < window_size; i++)
  {
    currWindowSum += s.at(i);
  }

  windowSums.push_back(currWindowSum);

  // Go through the array moving the window and summing each window elements and pushing the results
  // into the 'currWindowSum' array:
  for (int i{1}; i < (s.size() - window_size + 1); i++)
  {
    currWindowSum = windowSums.at(i - 1) - s.at(i - 1) + s.at(i + window_size - 1);

    windowSums.push_back(currWindowSum);
  }

  // Loop through the results array and compare the stored results with the target 'd':
  for (const auto &sum : windowSums)
  {
    if (sum == d)
    {
      numOfWays++;
    }
  }

  return numOfWays;
}

int main()
{
  std::vector<int> vec{2, 2, 1, 3, 2};
  int d{4};
  int m{2};

  std::cout << "Number of possible solutions: " << birthday_1(vec, d, m) << "\n";
  std::cout << "Number of possible solutions: " << birthday_2(vec, d, m) << "\n";
  std::cout << "Number of possible solutions: " << birthday_3(vec, d, m) << "\n";

  vec = {4};
  d = 4;
  m = 1;

  std::cout << "Number of possible solutions: " << birthday_1(vec, d, m) << "\n";
  std::cout << "Number of possible solutions: " << birthday_2(vec, d, m) << "\n";
  std::cout << "Number of possible solutions: " << birthday_3(vec, d, m) << "\n";

  return 0;
}