/* * * * * * * * * * * * * * * * * *
 Problem: LC 41. First Missing Positive

--Problem statement:
  Given an unsorted integer array nums, return the smallest missing positive integer.
  You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

  > Example 1:
    Input: nums = [1,2,0]
    Output: 3
    Explanation: The numbers in the range [1,2] are all in the array.

  > Example 2:
    Input: nums = [3,4,-1,1]
    Output: 2
    Explanation: 1 is in the array but 2 is missing.

  > Example 3:
    Input: nums = [7,8,9,11,12]
    Output: 1
    Explanation: The smallest positive integer 1 is missing.

--Constraints:
    :: 1 <= nums.length <= 10^5
    :: -2^31 <= nums[i] <= 23^1 - 1
--Inputs:
  - int arr[n]: unsorted integer array 'nums'

--Outputs:
  - int: smallest missing positive integer

--Reasoning:
  See comments below.

--Time complexity: O(N), where N is the size of the array 'nums'.

--Space complexity: O(1), no extra space is allocated.

* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <vector>

void display1D(const std::vector<int> &vec);

int firstMissingPositive(std::vector<int> &nums) {
  int missingPositive{-1};

  // cyclic sort to put each positive value 'nums[i]' at its correct position 'i-1'
  // ignoring all numbers that are outside the range of the array (i.e., all
  // negative numbers and all numbers greater than the length of the array):
  for (int i{0}; i < nums.size(); ++i) {
    if (nums.at(i) > 0 && nums.at(i) <= nums.size() && nums.at(i) != nums.at(nums.at(i) - 1)) {
      std::swap(nums.at(i), nums.at(nums.at(i) - 1));
      --i;
    }
  }

  // iterate over the array and the first index that does not have the correct
  // number will be the smallest missing positive number:
  for (int i{0}; i < nums.size(); ++i) {
    if (nums.at(i) != i + 1) {
      missingPositive = i + 1;
      break;
    }
  }

  return missingPositive != -1 ? missingPositive : nums.size() + 1;
}

int main() {
  std::vector<int> nums{};

  nums = {1, 2, 0};
  std::cout << "> Array: ";
  display1D(nums);
  std::cout << "> Smallest missing positive number: " << firstMissingPositive(nums) << "\n\n";

  nums = {3, 4, -1, 1};
  std::cout << "> Array: ";
  display1D(nums);
  std::cout << "> Smallest missing positive number: " << firstMissingPositive(nums) << "\n\n";

  nums = {7, 8, 9, 11, 12};
  std::cout << "> Array: ";
  display1D(nums);
  std::cout << "> Smallest missing positive number: " << firstMissingPositive(nums) << "\n\n";
}

void display1D(const std::vector<int> &vec) {
  std::cout << "[ ";
  for (const auto &num : vec) {
    std::cout << num << " ";
  }
  std::cout << "]\n";
}