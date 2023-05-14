/*********************************************************************************************/
/* Problem: 18. 4Sum ****************/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array 'nums' of 'n' integers, return an array of all the unique quadruplets
  [nums[a], nums[b], nums[c], nums[d]] such that:
    :: 0 <= a, b, c, d < n
    :: a, b, c, and d are distinct.
    :: nums[a] + nums[b] + nums[c] + nums[d] == target

  You may return the answer in any order.

  > Example 1:
    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

  > Example 2:
    Input: nums = [2,2,2,2,2], target = 8
    Output: [[2,2,2,2]]

--Inputs:
  -int nums[n]: integer array nums
  -int: target value

--Output:
  -int arr[][]: array of triplets which satisfy the stated condition.

--Constraints:
  :: 1 <= nums.length <= 200
  :: -10^9 <= nums[i] <= 10^9
  :: -10^9 <= target <= 10^9

--Reasoning: See comments below.

*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

void display2D(const std::vector<std::vector<int>> &arr);

/*
-- Approach #1 - Brute Force: 4 nested for loops

-- Time complexity: O(N^4)
-- Space complexity: O(N), due to the hash set used to avoid storing repeated quads.
*/
std::vector<std::vector<int>> fourSum_1(std::vector<int> &nums, int target) {
  // input size:
  const int SIZE = nums.size();
  // sort input data (that's gonna take O(n*log(n))):
  std::sort(nums.begin(), nums.end());
  // output array:
  std::vector<std::vector<int>> result;
  // set to store the unique quads:
  std::set<std::vector<int>> hash_set;

  for (int l{0}; l < SIZE - 3; ++l) {
    for (int m{l + 1}; m < SIZE - 2; ++m) {
      for (int n{m + 1}; n < SIZE - 1; ++n) {
        for (int p{n + 1}; p < SIZE; ++p) {
          int curr_sum = nums.at(l) + nums.at(m) + nums.at(n) + nums.at(p);

          if (curr_sum == target)
            hash_set.insert({nums.at(l), nums.at(m), nums.at(n), nums.at(p)});
        }
      }
    }
  }

  for (auto &quad : hash_set)
    result.push_back(quad);

  return result;
}

/*
-- Approach #2 - Two pointer + 3 nested for loops

-- Time complexity: O(N^3)
-- Space complexity: O(N), due to the hash set used to avoid storing repeated quads.
*/
std::vector<std::vector<int>> fourSum_2(std::vector<int> &nums, int target) {
  // input size:
  const int SIZE = nums.size();
  // sort input data (that's gonna take O(n*log(n))):
  std::sort(nums.begin(), nums.end());
  // output array:
  std::vector<std::vector<int>> result;
  // set to store the unique quads:
  std::set<std::vector<int>> hash_set;

  for (int l{0}; l < SIZE - 3; ++l) {
    for (int m{l + 1}; m < SIZE - 2; ++m) {
      // calculate the amount missing to match the target value:
      int new_target = target - (nums.at(l) + nums.at(m));
      // two pointers approach:
      int low = m + 1, high = SIZE - 1;
      // iterate while the pointers do not meet each other:
      while (low < high) {
        int curr_sum = nums.at(low) + nums.at(high);
        // if the current sum is too small, move left pointer (increment low) to greater values:
        if (curr_sum < new_target)
          ++low;
        // if the current sum is too large, move right pointer (decrement high) to smaller values:
        else if (curr_sum > new_target)
          --high;
        // if current sum is a match, add current quad to the hash set and inc/dec pointers:
        else {
          hash_set.insert({nums.at(l), nums.at(m), nums.at(low), nums.at(high)});
          ++low;
          --high;
        }
      }
    }
  }
  // iterate over the unique quads adding the to the output:
  for (auto &quad : hash_set)
    result.push_back(quad);

  return result;
}

/*
-- Approach #3 - Two pointer + 3 nested for loops + skip repeated quads

-- Time complexity: O(N^3)
-- Space complexity: O(1).
*/
std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
  // input size:
  const int SIZE = nums.size();
  // sort input data (that's gonna take O(n*log(n))):
  std::sort(nums.begin(), nums.end());
  // output array:
  std::vector<std::vector<int>> result;

  for (int l{0}; l < SIZE - 3; ++l) {
    for (int m{l + 1}; m < SIZE - 2; ++m) {
      // calculate the amount missing to match the target value:
      int new_target = target - (nums.at(l) + nums.at(m));
      // two pointers approach:
      int low = m + 1, high = SIZE - 1;
      // iterate while the pointer do not meet each other:
      while (low < high) {
        int curr_sum = nums.at(low) + nums.at(high);
        // if the current sum is too small, move left pointer (increment low) to greater values:
        if (curr_sum < new_target)
          ++low;
        // if the current sum is too large, move right pointer (decrement high) to smaller values:
        else if (curr_sum > new_target)
          --high;
        // if current sum is a match, add current quad to the output and skip duplicates:
        else {
          result.push_back({nums.at(l), nums.at(m), nums.at(low), nums.at(high)});

          // save the pointers positions for the current match:
          int prev_low_id = low, prev_high_id = high;

          // in case there are any neighboring duplicates, move 'low' pointer to skip them:
          while (low < high && nums.at(low) == nums.at(prev_low_id))
            ++low;
          // in case there are any neighboring duplicates, move 'high' pointer to skip them:
          while (low < high && nums.at(high) == nums.at(prev_high_id))
            --high;
        }
      }
      // skip duplicates:
      while (m + 1 < SIZE && nums.at(m) == nums.at(m + 1))
        ++m;
    }
    // skip duplicates:
    while (l + 1 < SIZE && nums.at(l) == nums.at(l + 1))
      ++l;
  }

  return result;
}

int main() {
  std::vector<int> nums{};
  std::vector<std::vector<int>> res{};
  int target{};

  nums = {1, 0, -1, 0, -2, 2};
  target = 0;
  std::cout << "Unique quadruples whose sum is equal to " << target << ": ";
  res = fourSum(nums, target);
  display2D(res);

  nums = {2, 2, 2, 2, 2};
  target = 8;
  std::cout << "Unique quadruples whose sum is equal to " << target << ": ";
  res = fourSum(nums, target);
  display2D(res);

  nums = {4, 1, 2, -1, 1, -3};
  target = 1;
  std::cout << "Unique quadruples whose sum is equal to " << target << ": ";
  res = fourSum(nums, target);
  display2D(res);

  nums = {2, 0, -1, 1, -2, 2};
  target = 2;
  std::cout << "Unique quadruples whose sum is equal to " << target << ": ";
  res = fourSum(nums, target);
  display2D(res);

  return 0;
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