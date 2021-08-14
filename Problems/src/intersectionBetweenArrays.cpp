/*******************************************************************/
/* Problem: Calculate the intersection of two arrays (CtCi) ********/
/*******************************************************************/
/*
Problem statement:
    Compute the intersection (the number of elements in common) of two
    arrays. Assume that neither array has duplicates.
Reasoning:
    Compute the intersection by sorting one of the arrays and then iterating
    through the other array and checking (via binary search) if each value is 
    in the sorted array.
Runtime:
    O(Na*logB + Nb*logB) = O((Na+Nb)*logB)
*/

#include <iostream>
#include <vector>
#include <algorithm>

int intersection(std::vector<int> vec_A, std::vector<int> vec_B)
{
  std::sort(vec_B.begin(), vec_B.end());

  int intersect = 0;

  for (auto &i : vec_A)
  {
    if (std::binary_search(vec_B.begin(), vec_B.end(), i))
    {
      intersect++;
    }
  }

  return intersect;
}

int main()
{
  std::vector<int> v_a{1, 3, 21, 92, 0, 7, 33};
  std::vector<int> v_b{0, 9, 33, 1, 73, 99, 101, 3};

  std::cout << "There are " << intersection(v_a, v_b) << " elements in common.\n";

  return 0;
}