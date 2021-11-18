/*********************************************************************************************/
/* Problem: Maximum Perimeter Triangle (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array of stick lengths, use 3 of them to construct a non-degenerate triangle with the
  maximum possible perimeter. Return an array of the lengths of its sides as 3 integers in
  non-decreasing order. If there are several valid triangles having the maximum perimeter:
    1. Choose the one with the longest maximum side.
    2. If more than one has that maximum, choose from them the one with the longest minimum side.
    3. If more than one has that maximum as well, print any one them.

  If no non-degenerate triangle exists, return [-1].
  > Example:
    arr = [1,2,3,4,5,10]
    The triplet (1,2,3) will not form a triangle. Neither will (4,5,10) or (2,3,5), so the problem
    is reduced to (2,3,4) and (3,4,5). The longer perimeter is 3+4+5=12.

  > Input:
    int sticks[n]: the lengths of sticks available

  > Output:
    int[3] or int[1]: the side lengths of the chosen triangle in non-decreasing order or -1

  > Constraints:
      3 <= n <= 50
      1 <= sticks[i] <= 10^9

--Reasoning:
  Sort the input array in decreasing order. After that, iterate over the sorted array and check
  whether the condition for a non-degenerate triangle is satisfied. Once a triplet that satisfies
  the condition is found, since the sticks are ordered, that's the solution.

--Time complexity: O(n*log(n)), due to the sorting of the input array.

--Space complexity: O(1), no additional space is needed which is dependent on the input size.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> maximumPerimeterTriangle2(std::vector<int> &sticks)
{
  // For a non-degenerate triangle, its sides should
  // follow these constraints, A + B > C and B + C > A
  // and C + A > B where A, B and C are length of sides of the triangle.
  std::vector<int> sides{-1};
  uint perimeter{0};
  bool done{false};
  int count{0};

  std::sort(sticks.begin(), sticks.end(), std::greater<int>());

  for (size_t i{0}; (i < sticks.size() - 2) && !done; i++)
  {
    int side_A = sticks.at(i);
    int side_B = sticks.at(i + 1);
    int side_C = sticks.at(i + 2);

    bool condition_1 = (side_A + side_B) > side_C;
    bool condition_2 = (side_B + side_C) > side_A;
    bool condition_3 = (side_A + side_C) > side_B;

    if (condition_1 && condition_2 && condition_3)
    {
      uint temp = (side_A + side_B + side_C);

      sides.clear();

      sides.push_back(side_C);
      sides.push_back(side_B);
      sides.push_back(side_A);

      done = true;
    }
  }

  return sides;
}

int main()
{
  std::vector<int> vec{1, 2, 3, 4, 5, 10};

  std::vector<int> sides = maximumPerimeterTriangle2(vec);

  for (const auto &s : sides)
  {
    std::cout << s << "  ";
  }

  std::cout << "\n";

  vec = {
      1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000,
      1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000,
      1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000,
      1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000,
      1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000};

  sides = maximumPerimeterTriangle2(vec);

  for (const auto &s : sides)
  {
    std::cout << s << "  ";
  }

  std::cout << "\n";

  return 0;
}