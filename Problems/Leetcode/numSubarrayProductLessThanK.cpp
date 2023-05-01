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

--Reasoning: See comments below.

--Time complexity:
    O(N), where N is the size of the input array, since we only need to traverse the whole
    array once.

--Space complexity:
    O(1), since no input-dependent space is allocated.

*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

int numSubarrayProductLessThanK(std::vector<int> &nums, int k) {
  const int N = nums.size();
  int result{};

  if (N == 0)
    return result;

  int l_ptr = 0, r_ptr = 0, curr_prod = 1;

  // Expand the sliding window until we've included and analyzed all the array elements:
  while (r_ptr < N) {
    // Calculate the current product, 'curr_prod':
    curr_prod *= nums.at(r_ptr);
    // In case the current product is greater than our target value, 'k', shrink the current
    // window by moving the left pointer, 'l_ptr', and updating the current product to reflect
    // the removal of 'nums[l_ptr]' from the product. Here, 'l_ptr' will be incremented until
    // the current product is less than 'k' again or it reaches the end of the array:
    while (curr_prod >= k && l_ptr < N) {
      curr_prod /= nums.at(l_ptr);
      ++l_ptr;
    }
    // If current product is less than threshold, i.e. the product of all the values between
    // the pointers is less than 'k', all subarrays from 'l_ptr' to 'r_ptr' will meet this
    // condition and can be added to the result:
    if (curr_prod < k)
      result += r_ptr - l_ptr + 1;

    // Expand the window by moving the right pointer:
    ++r_ptr;
  }

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