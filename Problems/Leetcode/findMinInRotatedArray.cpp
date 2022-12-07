/*********************************************************************************************/
/* Problem: 153. Find Minimum in Rotated Sorted Array ********/
/*********************************************************************************************/
/*
--Problem statement:
  Suppose an array of length 'n' sorted in ascending order is rotated between 1 and 'n' times.
  For example, the array nums = [0,1,2,4,5,6,7] might become:
    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.

  Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array
  [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

  Given the sorted rotated array nums of unique elements, return the minimum element of this array.

  You must write an algorithm that runs in O(log n) time.

    > Example 1:
    Input: nums = [3,4,5,1,2]
    Output: 1
    Explanation: The original array was [1,2,3,4,5] rotated 3 times.

    > Example 2:
    Input: nums = [4,5,6,7,0,1,2]
    Output: 0
    Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

    > Example 3:
    Input: nums = [11,13,15,17]
    Output: 11
    Explanation: The original array was [11,13,15,17] and it was rotated 4 times.

--Inputs:
  -int[]: array 'nums' sorted in ascending order
  -int: integer 'target'

--Output:
  -int[][]: unique combinations of candidates where the chosen numbers sum to 'target'

--Constraints:
  :: n == nums.length
  :: 1 <= n <= 5000
  :: -5000 <= nums[i] <= 5000
  :: All the integers of nums are unique.
  :: nums is sorted and rotated between 1 and n times.

--Reasoning: See comments below.

--Time complexity: O(log N), where N is the size of the array.

--Space complexity: O(1), no additional input dependent space is allocated.

*/

#include <iostream>
#include <vector>

int findMin(std::vector<int> &nums) {
  int lo = 0,
      hi = nums.size() - 1;

  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;

    if (nums.at(mid) > nums.at(hi)) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return nums.at(lo);
}

int main() {
  std::vector<int> vec{};
  int res{};

  vec = {3, 4, 5, 1, 2};
  res = findMin(vec);
  std::cout << "Min. element: " << res << "\n\n";

  vec = {4, 5, 6, 7, 0, 1, 2};
  res = findMin(vec);
  std::cout << "Min. element: " << res << "\n\n";

  vec = {11, 13, 15, 17};
  res = findMin(vec);
  std::cout << "Min. element: " << res << "\n\n";

  return 0;
}