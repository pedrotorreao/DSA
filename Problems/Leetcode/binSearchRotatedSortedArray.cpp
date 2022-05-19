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

--Reasoning:
  As the array is rotated around a pivot, we cannot run a standard binary search because  we may come across
  the situation where the 'mid' position and the 'target' value are in different halves of the array (sides
  here refers to the values before and after the pivot). If both 'mid' and 'target' are in the same half,
  we can simply continue with a regular binary search because we'll eventually converge towards the 'target'.
  However, if we have 'mid' and 'target' at different halves, we'll "invalidate" the elements that do not
  matter to our search by setting them to its max/min possible value dependending on the side it is.
    Ex.: nums=[4, 5, 6, 7, 0, 1, 2]
      - If 'target' is in the left half, then when searching we'll make the numbers nums[mid] at the right half
      to be INT_MAX:
            --> [4, 5, 6, 7, INT_MAX, INT_MAX, INT_MAX]

      - If 'target' is in the right half, then when searching we'll make the numbers nums[mid] at the left half
      to be INT_MIN:
            --> [INT_MIN, INT_MIN, INT_MIN, INT_MIN, 0, 1, 2]

      In this way, the array is kinda of "sorted" as we go. We don't actually modify the array, but make the mid
      point value to be INT_MAX/INT_MIN instead of nums[mid] in the current iteration based on which side the
      'target' is and which side the mid point number is.

      - If 'target' and nums[mid] are on the same half side (left or right half). The mid point and 'target' are
      on the same half and you are converging towards the 'target', so mid point will be nums[mid] and we perform
      a regular binary search.

      In order to check if both 'nums[mid]' and 'target' are on the same half, we check if they're both greater
      than the pivot number (the number where the rotation began, nums[0]) or both smaller than pivot number:
          if(   ((nums[mid] > nums[0]) && (target > nums[0]))
            || ((nums[mid] <= nums[0]) && (target <= nums[0]))
            )

      Then, if 'nums[mid]' and 'target' are on different halves, we don't use 'nums[mid]' as mid point, and we use
      INT_MIN or INT_MAX for comparing with 'target' value in order to find out in which half 'target' is.

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
    // m: mid position
    int m = l + (r - l) / 2; // prevent (l + r) overflow

    /* same as
          if(    ((nums[mid] > nums[0]) && (target > nums[0])) --> same half, i.e, left
              || ((nums[mid] <= nums[0]) && (target <= nums[0])) --> same half, i.e, right
            )
    */
    // n: mid point/value
    auto n = ((nums.at(m) < nums.at(0)) == (target < nums.at(0)))                                             // nums[m] and target are on the same half?
                 ? nums.at(m)                                                                                 // yes, regular binary search
                 : (target < nums.at(0) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max()); // no, find out 'target's half

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

/*



*/