/***
Problem: LC 90. Subsets II
(https://leetcode.com/problems/subsets-ii/description/)

--Problem statement:
  Given an integer array 'nums' that may contain duplicates, return all possible
  subsets (the power set).

  The solution set must not contain duplicate subsets. Return the solution in any
  order.

  > Example 1:
    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

  > Example 2:
    Input: nums = [0]
    Output: [[],[0]]

  > Example 3:
    Input: nums = [1, 5, 3]
    Output: [[], [1], [5], [1,5], [3], [1,3], [5,3], [1,5,3]]

--Inputs:
    int[]: integer array 'nums'

--Output:
    int[][]: all possible subsets

--Constraints:
    :: 1 <= nums.length <= 10
    :: -10 <= nums[i] <= 10

--Time complexity: O(n*(2^n))
  In each step, the number of subsets doubles (if not duplicate) as we add each element to all the existing subsets,
  therefore, we'll have a total of O(2^n) subsets, where 'n' is the total number of elements in the input array.
  And since we construct a new subset from an existing set, therefore, the time complexity of the above algorithm
  will be O(n*(2^n)).
    -> outer loop: O(n)
    -> inner loop: O(2^n)

--Space complexity:
  For the worst case, we'll have a total of O(2^n) subsets, and each subset can take up to O(n) space, therefore, the
  space complexity of our algorithm will be O(n*(2^n)).

*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

void display2D(const std::vector<std::vector<int>> &res);

class Solution {
public:
  static std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    std::vector<std::vector<int>> subsets;
    int numOfSubsetsAddedPreviousIter = 0;

    // sort input data to make sure that duplicate values are adjacent:
    std::sort(nums.begin(), nums.end());

    // add empty subset:
    subsets.push_back(std::vector<int>());

    for (int i{0}; i < nums.size(); ++i) {
      // add the current number, i.e. 'nums.at(i)', to all existing subsets, creating new subsets:
      int currNum = nums.at(i), existingSubsets = subsets.size();

      for (int j{0}; j < existingSubsets; ++j) {
        // a. skip repeated values to avoid duplicate subsets: 'i > 0 && currNum == nums.at(i - 1)';
        // b. keep track of the number of sets created in the previous step to avoid adding the current number
        // to all the existing subsets whenever we are about to process a duplicate and only add it to the
        // newly created subsets: 'j < existingSubsets - numOfSubsetsAddedPreviousIter'
        if (i > 0 && currNum == nums.at(i - 1) && j < existingSubsets - numOfSubsetsAddedPreviousIter)
          continue;

        std::vector<int> temp = subsets.at(j);

        temp.push_back(currNum);
        subsets.push_back(temp);
      }

      numOfSubsetsAddedPreviousIter = subsets.size() - existingSubsets;
    }
    return subsets;
  }
};

int main() {
  std::vector<int> nums{};
  std::vector<std::vector<int>> res{};

  nums = {1, 2, 2};
  res = Solution::subsetsWithDup(nums);
  display2D(res);

  nums = {0};
  res = Solution::subsetsWithDup(nums);
  display2D(res);

  nums = {1, 5, 3};
  res = Solution::subsetsWithDup(nums);
  display2D(res);

  nums = {1, 5, 3, 3};
  res = Solution::subsetsWithDup(nums);
  display2D(res);
}

void display2D(const std::vector<std::vector<int>> &res) {
  std::cout << "-> ";
  for (int i{0}; i < res.size(); i++) {
    std::cout << "[ ";
    for (int j{0}; j < res.at(i).size(); j++) {
      std::cout << res.at(i).at(j) << " ";
    }
    std::cout << "]";
  }
  std::cout << "\n\n";
}