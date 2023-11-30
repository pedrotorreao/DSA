/****************************************************/
/* Problem: LC 448. Find All Missing Numbers ********/
/****************************************************/
/*
--Problem statement:
  Given an array nums of 'n' integers where nums[i] is in the range [1, n], return an array
  of all the integers in the range [1, n] that do not appear in 'nums'.

  Example 1:
    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [5,6]

  Example 2:
    Input: nums = [1,1]
    Output: [2]

--Inputs:
  -int[]: array of integers

--Output:
  -int[]: array of integer missing in range [1,n].

--Constraints:
  :: n == nums.length
  :: 1 <= n <= 105
  :: 1 <= nums[i] <= n

--Time complexity: O(N)

--Space complexity: O(1)

*/
#include <iostream>
#include <vector>

std::vector<int> findDisappearedNumbers(std::vector<int> &nums) {
  std::vector<int> missingNumbers;

  for (int i{0}; i < nums.size(); i++) {
    if (nums.at(i) != nums.at(nums.at(i) - 1)) {
      std::swap(nums.at(i), nums.at(nums.at(i) - 1));
      --i;
    }
  }

  for (int i{0}; i < nums.size(); i++) {
    if (nums.at(i) != i + 1)
      missingNumbers.push_back(i + 1);
  }

  return missingNumbers;
}

void display1D(const std::vector<int> &vec);

int main() {
  std::vector<int> nums{};

  nums = {4, 3, 2, 7, 8, 2, 3, 1};
  std::cout << "Missing numbers: ";
  display1D(findDisappearedNumbers(nums));

  nums = {2, 3, 1, 8, 2, 3, 5, 1};
  std::cout << "Missing numbers: ";
  display1D(findDisappearedNumbers(nums));
}

void display1D(const std::vector<int> &vec) {
  std::cout << "[ ";
  for (const auto &num : vec) {
    std::cout << num << " ";
  }
  std::cout << "]\n";
}