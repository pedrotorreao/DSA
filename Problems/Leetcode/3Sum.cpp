/*********************************************************************************************/
/* Problem: 3Sum (LC 15) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such
  that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
  Notice that the solution set must not contain duplicate triplets.

  > Example 1:
      Input: nums = [-1,0,1,2,-1,-4]
      Output: [[-1,-1,2],[-1,0,1]]
      Explanation:
        nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
        nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
        nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
        The distinct triplets are [-1,0,1] and [-1,-1,2].
        Notice that the order of the output and the order of the triplets does not matter.

  > Example 2:
      Input: nums = [0,1,1]
      Output: []
      Explanation: The only possible triplet does not sum up to 0.

  > Example 3:
      Input: nums = [0,0,0]
      Output: [[0,0,0]]
      Explanation: The only possible triplet sums up to 0.

--Inputs:
  -int nums[n]: integer array nums

--Output:
  -int arr[][]: array of triplets which satisfy the stated condition.

--Constraints:
  :: 3 <= nums.length <= 3000
  :: -10^5 <= nums[i] <= 10^5

--Reasoning: See comments below.

--Time complexity: O(N^2)

--Space complexity: O(N)

*/

#include <algorithm>
#include <iostream>
#include <vector>

void display2D(const std::vector<std::vector<int>> &arr);

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
  // store input size:
  const int SIZE = nums.size();
  // sort the input array (TC: O(N*log(N))):
  std::sort(nums.begin(), nums.end());
  // output array:
  std::vector<std::vector<int>> res;

  for (int i{0}; i < SIZE - 2; ++i) {
    // if the element at the leftmost position is greater than zero,
    // it's not possible to have a zero sum:
    if (nums.at(i) > 0)
      break;

    // in case of equal neighbors, advance pointer to avoid duplicated
    // triplets in the solution:
    if (i > 0 && nums.at(i - 1) == nums.at(i))
      continue;

    int j = i + 1;
    int k = SIZE - 1;

    while (j < k) {
      int curr_sum = nums.at(i) + nums.at(j) + nums.at(k);

      if (curr_sum < 0)      // *if sum is too low, we need bigger values, since i is fixed
        ++j;                 // and k is at the largest possible, we move the pointer j forward to a larger value.
      else if (curr_sum > 0) // *if sum is too large, we need smaller values, since i is fixed
        --k;                 // and j is at the lowest possible, we move k backwards to a smaller value.
      else {                 // *we have a matching triplet which sum is equal to zero, add it to the result:
        res.push_back({nums.at(i), nums.at(j), nums.at(k)});

        while (j < k && nums.at(j) == nums.at(j + 1))
          ++j; // advances until the last duplicate
        ++j;   // advances past the last duplicate

        while (k > j && nums.at(k) == nums.at(k - 1))
          --k; // retreats until the first duplicate
        --k;   // retreats before the first duplicate
      }
    }
  }

  return res;
}

int main() {
  std::vector<int> nums{};
  std::vector<std::vector<int>> triplets{};

  nums = {-1, 0, 1, 2, -1, -4};
  triplets = threeSum(nums);
  std::cout << "Expected: [[-1 -1 2] [-1 0 1]]\n";
  std::cout << "Result: ";
  display2D(triplets);

  nums = {0, 1, 1};
  triplets = threeSum(nums);
  std::cout << "Expected: []\n";
  std::cout << "Result: ";
  display2D(triplets);
}

void display2D(const std::vector<std::vector<int>> &arr) {
  std::cout << "[";
  for (const auto &r : arr) {
    std::cout << "[";
    for (const auto &c : r)
      std::cout << c << " ";
    std::cout << "] ";
  }
  std::cout << "]\n";
}