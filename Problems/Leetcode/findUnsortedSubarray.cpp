/******************************************************************************
Problem: LC 581. Shortest Unsorted Continuous Subarray (Minimum Window Sort Problem)
*******************************************************************************/
/*
--Problem statement:
  Given an integer array nums, you need to find one continuous subarray that if
  you only sort this subarray in ascending order, then the whole array will be
  sorted in ascending order.

  Return the shortest such subarray and output its length.

  > Example 1:
    Input: nums = [2,6,4,8,10,9,15]
    Output: 5
    Explanation:
      You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array
      sorted in ascending order.

  > Example 2:
    Input: nums = [1,2,3,4]
    Output: 0

  > Example 3:
    Input: nums = [1]
    Output: 0

--Inputs:
  int[]: integer array nums

--Output:
  int: length of the shortest subarray that, if sorted, sorts the original array.

--Constraints:
    :: 1 <= nums.length <= 104
    :: -105 <= nums[i] <= 105

*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

/* -- APPROACH #1:
--Reasoning:
  In this approach we create a copy of the input array and sort this copy. After
  that, we traverse both arrays twice comparing the elements at each position. In
  the first loop, we begin from the start of the array and traverse until we find
  the position, 'l', of the smallest element that has changed positions during sorting,
  i.e. the smallest element that was out of order in the original array. In the
  second pass, we begin the traversal from the end of the array and continue backwards
  until we find the position, 'r', of the largest element that has changed positions
  during sorting, i.e. the largest element that was out of order in the original array.
  The result, the length of the sorted subarray, is the difference between these two
  pointers.

--Time complexity:
    O(N*log(N)), due to the use of the sorting algorithm, where N is the size of the
    input array.

--Space complexity: O(N), due to the copy of the input array of size N.
*/
int findUnsortedSubarray_1(std::vector<int> &nums) {
  // create a copy of the input array to sort it and compare:
  std::vector<int> sorted_cp(nums);

  std::sort(sorted_cp.begin(), sorted_cp.end());

  const int N = nums.size();
  int l = 0, r = N - 1;

  while (l < N && (nums.at(l) == sorted_cp.at(l)))
    ++l;

  while (r > l && (nums.at(r) == sorted_cp.at(r)))
    --r;

  return r - l + 1;
}

/* -- APPROACH #2:
--Reasoning:
  In this approach, we traverse the array twice. In the first loop, we begin from
  the end of the array and traverse backwards until we find the position, 'l', of
  the smallest element that is out of order. In the second pass, we begin the
  traversal from the start of the array and continue forward until we find the
  position, 'r', of the largest element that is out of order. The result, the length
  of the sorted subarray, is the difference between these two pointers.

--Time complexity: O(N), where N is the size of the input array.

--Space complexity: O(1), no input dependent space was allocated.
*/
int findUnsortedSubarray_2(std::vector<int> &nums) {
  int max_now = std::numeric_limits<int>::min(),
      min_now = std::numeric_limits<int>::max(),
      l = 0,
      r = 0;

  const int N = nums.size();

  for (int i = N - 1; i >= 0; --i) {
    min_now = std::min(min_now, nums.at(i));

    if (min_now != nums.at(i))
      l = i;
  }

  for (int i = 0; i < N; ++i) {
    max_now = std::max(max_now, nums.at(i));

    if (max_now != nums.at(i))
      r = i;
  }

  return (r != l) ? r - l + 1 : 0;
}

/* -- APPROACH #3:
--Reasoning:
  This approach is similar to the previous one (#2), but we only do a single traversal
  using two pointers, 'r' and 'l'. Also, we have two variable tracking the current
  max and min elements, i.e. 'max_now' and 'min_now' respectively. During the traversal:
    -> the pointer 'l', which begins at index 0, checks at every position if the current
    element is larger than the previous max value found, 'max_now'. If it is, it means
    that the current segment of the array is sorted so we just update 'max_now' to be the
    current element. Otherwise, we know that the current element at nums[l] is out of
    order, so we set the variable that will assume the index of the rightmost element
    out of order to be 'l', i.e. 'end=l'.
    -> the pointer 'r', which begins at index N-1, works in a similar way, but instead checks
    the descending order of the elements and gets the index of the leftmost element out of
    order, which will be the final value assumed by 'r', i.e. 'start=r'.
  The result, the length of the sorted subarray, is the difference between the two variables,
  'end' and 'start'.

--Time complexity: O(N), where N is the size of the input array.

--Space complexity: O(1), no input dependent space was allocated.
*/
int findUnsortedSubarray(std::vector<int> &nums) {
  const int N = nums.size();
  int max_now = std::numeric_limits<int>::min(),
      min_now = std::numeric_limits<int>::max(),
      l = 0, r = N - 1, start = 0, end = -1;

  while (r >= 0) {
    if (nums.at(l) >= max_now)
      max_now = nums.at(l);
    else
      end = l;

    if (nums.at(r) <= min_now)
      min_now = nums.at(r);
    else
      start = r;

    ++l;
    --r;
  }

  return (end - start + 1);
}

int main() {
  std::vector<int> nums{};
  int expec{0}, res{0};

  nums = {1, 3, 7, 4, 6, 9, 5, 11, 23};
  expec = 5;
  res = findUnsortedSubarray(nums);
  std::cout << "Subarray length: " << res
            << "    --Expected: " << expec
            << (res == expec ? "     [PASSED]\n" : "     [FAILED]\n")
            << "\n";

  nums = {1, 2, 3, 4};
  expec = 0;
  res = findUnsortedSubarray(nums);
  std::cout << "Subarray length: " << res
            << "    --Expected: " << expec
            << (res == expec ? "     [PASSED]\n" : "     [FAILED]\n")
            << "\n";

  nums = {2, 6, 4, 8, 10, 9, 15};
  expec = 5;
  res = findUnsortedSubarray(nums);
  std::cout << "Subarray length: " << res
            << "    --Expected: " << expec
            << (res == expec ? "     [PASSED]\n" : "     [FAILED]\n")
            << "\n";

  nums = {1};
  expec = 0;
  res = findUnsortedSubarray(nums);
  std::cout << "Subarray length: " << res
            << "    --Expected: " << expec
            << (res == expec ? "     [PASSED]\n" : "     [FAILED]\n")
            << "\n";

  nums = {1, 3, 2, 2, 2};
  expec = 4;
  res = findUnsortedSubarray(nums);
  std::cout << "Subarray length: " << res
            << "    --Expected: " << expec
            << (res == expec ? "     [PASSED]\n" : "     [FAILED]\n")
            << "\n";

  nums = {2, 3, 2, 2, 4};
  expec = 3;
  res = findUnsortedSubarray(nums);
  std::cout << "Subarray length: " << res
            << "    --Expected: " << expec
            << (res == expec ? "     [PASSED]\n" : "     [FAILED]\n")
            << "\n";

  nums = {1, 1};
  expec = 0;
  res = findUnsortedSubarray(nums);
  std::cout << "Subarray length: " << res
            << "    --Expected: " << expec
            << (res == expec ? "     [PASSED]\n" : "     [FAILED]\n")
            << "\n";

  return 0;
}
