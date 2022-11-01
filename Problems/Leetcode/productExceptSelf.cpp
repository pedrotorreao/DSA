/******************************************************************************
Problem: LC 238. Product of Array Except Self
*******************************************************************************/
/*
--Problem statement:
  Given an integer array nums, return an array answer such that answer[i] is equal
  to the product of all the elements of nums except nums[i]. The product of any
  prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
  You must write an algorithm that runs in O(n) time and without using the division
  operation.

  > Example 1:
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

   > Example 2:
    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]

--Inputs:
  int[]: array of integers

--Output:
  int[]: array of products

--Constraints:
    :: 2 <= nums.length <= 105
    :: -30 <= nums[i] <= 30
    :: The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

--Reasoning:

--Time complexity:

--Space complexity:

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does
not count as extra space for space complexity analysis.)

*/

#include <cmath>
#include <iostream>
#include <vector>

void display1D(const std::vector<int> &arr);

std::vector<int> productExceptSelf(std::vector<int> &nums) {
  const int N = nums.size();
  std::vector<int> ans{};

  // .. solution

  return ans;
}

int main() {
  std::vector<int> nums{}, res{};

  nums = {1, 2, 3, 4};
  res = productExceptSelf(nums);
  std::cout << "Expected: [24,12,8,6]\n"
            << "Result: ";
  display1D(res);

  nums = {-1, 1, 0, -3, 3};
  res = productExceptSelf(nums);
  std::cout << "Expected: [0,0,9,0,0]\n"
            << "Result: ";
  display1D(res);

  nums = {0, 0};
  res = productExceptSelf(nums);
  std::cout << "Expected: [0,0]\n"
            << "Result: ";
  display1D(res);

  nums = {2, 3, 0, 0};
  res = productExceptSelf(nums);
  std::cout << "Expected: [0,0,0,0]\n"
            << "Result: ";
  display1D(res);

  nums = {1, 2, 3, 0, 0};
  res = productExceptSelf(nums);
  std::cout << "Expected: [0,0,0,0]\n"
            << "Result: ";
  display1D(res);

  nums = {1, 0};
  res = productExceptSelf(nums);
  std::cout << "Expected: [0,1]\n"
            << "Result: ";
  display1D(res);

  return 0;
}

void display1D(const std::vector<int> &arr) {
  std::cout << "[ ";
  for (const auto &a : arr)
    std::cout << a << " ";

  std::cout << "]\n\n";
}