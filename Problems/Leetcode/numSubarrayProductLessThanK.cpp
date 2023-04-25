/*********************************************************************************************/
/* Problem: 713. Subarray Product Less Than K ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array of integers 'nums' and an integer 'k', return the number of contiguous subarrays
  where the product of all the elements in the subarray is strictly less than 'k'.

  > Example 1:
  Input: nums = [10,5,2,6], k = 100
  Output: 8
  Explanation: The 8 subarrays that have product less than 100 are:
    [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
    Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

  > Example 2:
  Input: nums = [1,2,3], k = 0
  Output: 0

--Inputs:
  -int arr[n]: integer array arr, of unsorted numbers
  -int: targetSum

--Output:
  -int: target sum

--Constraints:
  :: 1 <= nums.length <= 3 * 104
  :: 1 <= nums[i] <= 1000
  :: 0 <= k <= 106

--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <vector>

int numSubarrayProductLessThanK(std::vector<int> &nums, int k) {
  int result{};

  const int N = nums.size();
  if (N == 0)
    return result;

  // ...

  return result;
}

int main() {
  std::vector<int> nums;
  int k{0}, expected{0}, res{0};

  nums = {10, 5, 2, 6};
  k = 100;
  expected = 8;
  res = numSubarrayProductLessThanK(nums, k);
  std::cout << "Subarrays with product less than " << k << ": "
            << res << (res == expected ? "     --PASSED" : "     --FAILED") << "\n";

  nums = {1, 2, 3};
  k = 0;
  expected = 0;
  res = numSubarrayProductLessThanK(nums, k);
  std::cout << "Subarrays with product less than " << k << ": "
            << res << (res == expected ? "     --PASSED" : "     --FAILED") << "\n";
}