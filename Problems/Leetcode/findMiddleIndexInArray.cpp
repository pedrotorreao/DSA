/***
Problem: LC 1991. Find the Middle Index in Array
(https://leetcode.com/problems/132-pattern/description/)

--Problem statement:
Given a 0-indexed integer array 'nums', find the leftmost 'middleIndex' (i.e., the smallest amongst all the possible ones).

A 'middleIndex' is an index where:
    nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side
sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.

    > Example 1:
        Input: nums = [2,3,-1,8,4]
        Output: 3
        Explanation:
            The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
            The sum of the numbers after index 3 is: 4 = 4

    > Example 2:
        Input: nums = [1,-1,4]
        Output: 2
        Explanation:
            The sum of the numbers before index 2 is: 1 + -1 = 0
            The sum of the numbers after index 2 is: 0

    > Example 3:
        Input: nums = [2,5]
        Output: -1
        Explanation: There is no valid middleIndex.

--Inputs:
    int[]: integer array 'nums'

--Output:
    int: leftmost middleIndex that satisfies the condition

--Constraints:
    :: 1 <= nums.length <= 100
    :: -1000 <= nums[i] <= 1000

--Reasoning: Use the prefix sum pattern.

--Time complexity: O(n), where 'n' is the input size. We traverse the array twice and, for in both times,
we perform constant time work.

--Space complexity: O(1), no input dependent space needs to be allocated.

*/
#include <iostream>
#include <vector>

class Solution {
public:
  int findMiddleIndex(std::vector<int> &nums) {
    // Calculate the total sum of all elements in the array
    int totalSum = 0;
    for (int num : nums) {
      totalSum += num;
    }
    // Initialize the sum of elements to the left
    int leftSum = 0;
    // Iterate through each element in the array
    for (int i = 0; i < nums.size(); i++) {
      // Calculate the sum of elements to the right
      int rightSum = totalSum - leftSum - nums[i];
      // Check if the sum of elements to the left equals the sum of elements to the right
      if (leftSum == rightSum) {
        return i;
      }
      // Update the sum of elements to the left
      leftSum += nums[i];
    }
    return -1;
  }
};

int main() {
  std::cout << std::boolalpha;

  Solution sol;

  std::vector<int> nums{};
  int res{-1}, expected{-1};

  nums = {2, 3, -1, 8, 4};
  res = sol.findMiddleIndex(nums);
  expected = 3;
  std::cout << ">> Middle index in 'nums': " << res << (res == expected ? "\t--PASSED\n" : "\t--FAILED\n");

  nums = {1, -1, 4};
  res = sol.findMiddleIndex(nums);
  expected = 2;
  std::cout << ">> Middle index in 'nums': " << res << (res == expected ? "\t--PASSED\n" : "\t--FAILED\n");

  nums = {2, 5};
  res = sol.findMiddleIndex(nums);
  expected = -1;
  std::cout << ">> Middle index in 'nums': " << res << (res == expected ? "\t--PASSED\n" : "\t--FAILED\n");

  return 0;
}
