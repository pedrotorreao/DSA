/*********************************************************************************************/
/* Problem: 16. 3Sum Closest (mod. for multiple possible solutions) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an integer array "arr" of length 'n' and an integer "targetSum", find three integers in
  "arr" such that the sum is closest to "targetSum".
  Return the sum of the three integers.

  Mod.:
    If there are more than one such triplet, return the sum of the triplet with the smallest sum.

  Example 1:
    Input: nums = [-1,2,1,-4], target = 1
    Output: 2
    Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

  Example 2:
    Input: nums = [0,0,0], target = 1
    Output: 0
    Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

--Inputs:
  -int arr[n]: integer array arr
  -int: targetSum

--Output:
  -int: closest sum

--Constraints:
  :: 3 <= nums.length <= 500
  :: -1000 <= nums[i] <= 1000
  :: -10^4 <= target <= 10^4

--Reasoning: See comments below.

--Time complexity:
    > O(N*log(N)), due to the sorting
    > O(N^2), for the search
    --> O(N*log(N) + N^2) --> O(N^2)

--Space complexity: O(N), worst case scenario.

*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <limits>
#include <vector>

int threeSumClosest(std::vector<int> &arr, int targetSum) {
  const int N = arr.size();

  // sort the input array:
  std::sort(arr.begin(), arr.end());
  // initial value for the sum:
  int closestSum = arr.at(0) + arr.at(1) + arr.at(2);

  // we're going to search by using the two-pointers approach:
  //  - left_ptr:   leftmost pointer, defined the first element in the search window
  //  - mid_ptr:    middle pointer, it's moved when the current sum is smaller than target's
  //                and needs to be increased.
  //  - right_ptr:  righmost pointer, it's moved when the current sum is greater than target's
  //                and needs to be reduced.
  for (int left_ptr{0}; left_ptr < N - 2; ++left_ptr) {
    int mid_ptr = left_ptr + 1, right_ptr = N - 1;

    // iterate while the pointers do not meet:
    while (mid_ptr < right_ptr) {
      int currentSum = arr.at(left_ptr) + arr.at(mid_ptr) + arr.at(right_ptr);

      // if we got an exact match, no need to keep searching, return the result:
      if (currentSum == targetSum) {
        closestSum = currentSum;
        break;
      }

      if ((std::abs(targetSum - closestSum) > std::abs(targetSum - currentSum))      // 1. a closer sum was found, or
          || ((std::abs(targetSum - closestSum) == std::abs(targetSum - currentSum)) // 2. a sum with the same diff was found:
              && (currentSum < closestSum)                                           //    2.1. update answer in case the current sum is smaller
              ))
        closestSum = currentSum;

      // current sum is smaller than target, move mid pointer right by 1 to increase sum:
      if (currentSum < targetSum)
        ++mid_ptr;
      // current sum is greater than target, move right pointer left by 1 to reduce sum:
      else
        --right_ptr;
    }
  }

  return closestSum;
}

int main() {
  std::vector<int> vec{};

  vec = {-1, 0, 2, 3};
  std::cout << threeSumClosest(vec, 3) << "\n";

  vec = {-3, -1, 1, 2};
  std::cout << threeSumClosest(vec, 1) << "\n";

  vec = {1, 0, 1, 1};
  std::cout << threeSumClosest(vec, 100) << "\n";

  vec = {0, 0, 1, 1, 2, 6};
  std::cout << threeSumClosest(vec, 5) << "\n";
}