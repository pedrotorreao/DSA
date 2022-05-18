/*********************************************************************************************/
/* Problem: Search in Rotated Sorted Array (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  There is an integer array 'nums' sorted in ascending order (with distinct values).
  Prior to being passed to your function, 'nums' is possibly rotated at an unknown pivot index
  'k' (1 <= k < nums.length) such that the resulting array is:
      [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
  For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

  Given the array 'nums' after the possible rotation and an integer 'target', return the index of
  'target' if it is in 'nums', or -1 if it is not in 'nums'.

  You must write an algorithm with O(log n) runtime complexity.

  > Example 1:
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

  > Example 2:
    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1

  > Example 3:
    Input: nums = [1], target = 0
    Output: -1

--Inputs:
  -int nums[n]: possibly rotated array of size 'n'
  -int target: integer value being searched

--Output:
  -int: the index of 'target' if it is in 'nums', or -1 if it is not in 'nums'.

--Constraints:
  1 <= nums.length <= 5000
  -104 <= nums[i] <= 104
  All values of nums are unique.
  nums is an ascending array that is possibly rotated.
  -104 <= target <= 104

--Reasoning: See comments below.

--Time complexity: O(Log(N)), where N is the size of the input array.

--Space complexity: O(1), no additional input-dependent space is allocated.

*/

#include <iostream>
#include <limits>
#include <vector>

int binSearchRotatedSortedArray(std::vector<int> &nums, int target) {
  if (nums.size() == 0)
    return -1;

  int l = 0, r = nums.size() - 1;

  while (l <= r) {
    int m = l + (r - l) / 2;

    auto n = ((nums.at(m) < nums.at(0)) == (target < nums.at(0)))
                 ? nums.at(m)
                 : (target < nums.at(0) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max());

    if (n < target)
      l = m + 1;
    else if (n > target)
      r = m - 1;
    else
      return m;
  }

  return -1;
}

int main() {
  std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
  int target{0};
  std::cout << "Value " << target << " is at index " << binSearchRotatedSortedArray(nums, target) << "\n";

  target = 3;
  std::cout << "Value " << target << " is at index " << binSearchRotatedSortedArray(nums, target) << "\n";

  return 0;
}