/*********************************************************************************************/
/* Problem: 33. Search in Rotated Sorted Array ********/
/*********************************************************************************************/
/*
--Problem statement:
  There is an integer array nums sorted in ascending order (with distinct values).

  Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k
  (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1],
  nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated
  at pivot index 3 and become [4,5,6,7,0,1,2].

  Given the array 'nums' after the possible rotation and an integer target, return the index of
  target if it is in nums, or -1 if it is not in nums.

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
  -int[]: array 'nums' sorted in ascending order
  -int: integer 'target'

--Output:
  -int[][]: unique combinations of candidates where the chosen numbers sum to 'target'

--Constraints:
  :: 1 <= nums.length <= 5000
  :: -10^4 <= nums[i] <= 10^4
  :: All values of nums are unique.
  :: nums is an ascending array that is possibly rotated.
  :: -10^4 <= target <= 10^4

--Reasoning: See comments below.

--Time complexity: O(log N), where N is the size of the array.

--Space complexity: O(1), no additional input dependent space is allocated.

*/

#include <iostream>
#include <limits>
#include <vector>

int searchInRotatedSortedArray(std::vector<int> &nums, int target) {
  int l = 0,
      r = nums.size() - 1,
      true_mid = 0,
      pivot = nums.at(0);

  while (l <= r) {
    int m = l + (r - l) / 2;

    if (((nums.at(m) < pivot) && (target < pivot))    // nums[m] and target are both at left half
        || (nums.at(m) >= pivot) && (target >= pivot) // nums[m] and target are both at right half
    ) {
      true_mid = nums.at(m);
    }
    // nums[m] and target belong to different halves:
    else {
      if (target < pivot) // target is at the right half, minimize mid value:
        true_mid = std::numeric_limits<int>::min();
      else // target is at the left half, maximize mid value:
        true_mid = std::numeric_limits<int>::max();
    }

    // standard binary search algo:
    if (target > true_mid)
      l = m + 1;
    else if (target < true_mid)
      r = m - 1;
    else
      return m;
  }
  return -1;
}

int main() {
  std::vector<int> nums{};
  int target{}, expec{}, res{};

  nums = {4, 5, 6, 7, 0, 1, 2};
  target = 0;
  expec = 4;
  res = searchInRotatedSortedArray(nums, target);
  std::cout << "Index of " << target << ": " << res
            << (res == expec ? "    [PASSED]" : "    [FAILED]")
            << "\n\n";

  nums = {4, 5, 6, 7, 0, 1, 2};
  target = 3;
  expec = -1;
  res = searchInRotatedSortedArray(nums, target);
  std::cout << "Index of " << target << ": " << res
            << (res == expec ? "    [PASSED]" : "    [FAILED]")
            << "\n\n";

  nums = {1};
  target = 0;
  expec = -1;
  res = searchInRotatedSortedArray(nums, target);
  std::cout << "Index of " << target << ": " << res
            << (res == expec ? "    [PASSED]" : "    [FAILED]")
            << "\n\n";

  return 0;
}