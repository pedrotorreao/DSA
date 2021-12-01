/*********************************************************************************************/
/* Problem: Minimum Absolute Difference in an Array (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  The absolute difference is the positive difference between two values 'a' and 'b', is written
  |a-b| or |b-a| and they are equal. If a=3 and b=2, |3-2|=|2-3|=1. Given an array of integers,
  find the minimum absolute difference between any two elements in the array.

  > Example: arr=[-2,2,4]
    There are pairs of numbers: [-2,2], [-2,4] and [2,4]. The absolute differences for these
    pairs are |(-2)-2|=4, |(-2)-4|=6 and |2-4|=2. The minimum absolute difference is 2.

--Reasoning:
  First, we sort the array, so the closest numbers will be neighbors and we just need to iterate
  over the array once. After sorting, we iterate over the sequence calculating the absolute
  difference between adjacent elements keeping track of the minimum difference.

--Time complexity:
  O(N*logN), due to the sorting algorithm.

--Space complexity:
  O(1), no input dependent allocated space.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

int minimumAbsoluteDifference(std::vector<int> arr)
{
  long int minDiff = INT_MAX;

  std::sort(arr.begin(), arr.end());

  for (int i{1}; i < arr.size(); ++i)
  {
    long int currDiff = abs(arr.at(i) - arr.at(i - 1));
    if (currDiff < minDiff)
    {
      minDiff = currDiff;
    }
  }
  return minDiff;
}

int main()
{
  std::vector<int> vec{3, -7, 0};
  std::cout << "Minimum difference: " << minimumAbsoluteDifference(vec) << "\n"; // Expected: 3

  vec = {-59, -36, -13, 1, -53, -92, -2, -96, -54, 75};
  std::cout << "Minimum difference: " << minimumAbsoluteDifference(vec) << "\n"; // Expected: 1

  vec = {1, -3, 71, 68, 17};
  std::cout << "Minimum difference: " << minimumAbsoluteDifference(vec) << "\n"; // Expected: 3

  return 0;
}