/***
Problem: LC 2574. Left And Right Sum Differences
(https://leetcode.com/problems/left-and-right-sum-differences/description/)

--Problem statement:
Given a 0-indexed integer array 'nums', find a 0-indexed integer array answer where:
    answer.length == nums.length.
    answer[i] = |leftSum[i] - rightSum[i]|.
Where:
    leftSum[i] is the sum of elements to the left of the index i in the array 'nums'. If there is no such element, leftSum[i] = 0.
    rightSum[i] is the sum of elements to the right of the index i in the array 'nums'. If there is no such element, rightSum[i] = 0.
Return the array answer.

  > Example 1:
      Input: nums = [10,4,8,3]
      Output: [15,1,11,22]
      Explanation:
        The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
        The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].

  > Example 2:
      Input: nums = [1]
      Output: [0]
      Explanation:
        The array leftSum is [0] and the array rightSum is [0].
        The array answer is [|0 - 0|] = [0].

--Inputs:
    int[]: integer array 'nums'

--Output:
    int[]: integer array 'answer' which satisfies the conditions given.

--Constraints:
    :: 1 <= nums.length <= 1000
    :: 1 <= nums[i] <= 10^5

--Reasoning: Use the prefix sum pattern.

--Time complexity: O(n), where 'n' is the input size. We traverse the array twice and, for in both times,
we perform constant time work.

--Space complexity: O(1), no input dependent space needs to be allocated outside of the output array.

*/
#include <iostream>
#include <numeric>
#include <vector>

void display1D(const std::vector<int> &nums);
bool comp1D(const std::vector<int> &a, const std::vector<int> &b);

class Solution {
public:
  std::vector<int> leftRightDifference(std::vector<int> &nums) {
    const int N = nums.size();

    if (N == 0)
      return std::vector<int>();
    if (N == 1)
      return std::vector<int>(1, 0);

    // output array:
    std::vector<int> differencesArray(N);

    // calculate the sum of all the elements in the array and use it to calculate the running sum
    // for both sides of the array as we iterate over the array:
    int totalSum = std::accumulate(nums.begin(), nums.end(), 0),
        leftSum = 0,
        rightSum = 0;

    // since we're iterating from left to right, leftSum is initially 0:
    for (int i{0}; i < N; i++) {
      rightSum = totalSum - leftSum - nums[i];

      differencesArray[i] = abs(rightSum - leftSum);

      // update the leftSum value to account for the current nums[i] in the next iteration:
      leftSum += nums[i];
    }

    return differencesArray;
  }
};

int main() {
  std::cout << std::boolalpha;

  Solution sol;

  std::vector<int> nums{}, res{}, expected{};

  nums = {10, 4, 8, 3};
  res = sol.leftRightDifference(nums);
  expected = {15, 1, 11, 22};
  std::cout << ">> Answer: ";
  display1D(res);
  std::cout << (comp1D(res, expected) ? "\t--PASSED\n" : "\t--FAILED\n");

  nums = {1};
  res = sol.leftRightDifference(nums);
  expected = {0};
  std::cout << ">> Answer: ";
  display1D(res);
  std::cout << (comp1D(res, expected) ? "\t--PASSED\n" : "\t--FAILED\n");

  nums = {1, 2, 3, 4, 5};
  res = sol.leftRightDifference(nums);
  expected = {14, 11, 6, 1, 10};
  std::cout << ">> Answer: ";
  display1D(res);
  std::cout << (comp1D(res, expected) ? "\t--PASSED\n" : "\t--FAILED\n");

  return 0;
}

void display1D(const std::vector<int> &nums) {
  std::cout << "[ ";
  for (const auto &num : nums) {
    std::cout << num << " ";
  }
  std::cout << "] ";
}

bool comp1D(const std::vector<int> &a, const std::vector<int> &b) {
  if (a.size() != b.size()) {
    return false;
  }

  int id = 0;
  const int N = a.size();

  for (; id < N; ++id) {
    if (a.at(id) != b.at(id)) {
      return false;
    }
  }

  return true;
}