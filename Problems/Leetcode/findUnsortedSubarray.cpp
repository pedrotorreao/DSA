/******************************************************************************
Problem: LC 581. Shortest Unsorted Continuous Subarray
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
    Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

  > Example 2:
    Input: nums = [1,2,3,4]
    Output: 0

  > Example 3:
    Input: nums = [1]
    Output: 0






Constraints:





Follow up: Can you solve it in O(n) time complexity?

--Inputs:
  int[]: integer array nums

--Output:
  int[]: array of the indexes k corresponding to the ranges flipped until arr is sorted.

--Constraints:
    :: 1 <= nums.length <= 104
    :: -105 <= nums[i] <= 105

*/
#include <algorithm>
#include <iostream>
#include <vector>

/*
--Reasoning:

--Time complexity:

--Space complexity:
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

/*
--Reasoning:

--Time complexity:

--Space complexity:
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
