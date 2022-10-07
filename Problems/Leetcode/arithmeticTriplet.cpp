/******************************************************************************
Problem: Number of Arithmetic Triplets
*******************************************************************************/
/*
--Problem statement:
  You are given a 0-indexed, strictly increasing integer array nums and a positive
  integer diff. A triplet (i, j, k) is an arithmetic triplet if the following
  conditions are met:
    :: i < j < k,
    :: nums[j] - nums[i] == diff, and
    :: nums[k] - nums[j] == diff.

  Return the number of unique arithmetic triplets.

  > Example 1:
    Input: nums = [0,1,4,6,7,10], diff = 3
    Output: 2
    Explanation:
      (1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
      (2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3.

  > Example 2:
    Input: nums = [4,5,6,7,8,9], diff = 2
    Output: 2
    Explanation:
      (0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
      (1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.

--Inputs:
  int[]: strictly ordered array of integers
  int: target difference

--Output:
  int: number of triplets

--Constraints:
    :: 3 <= nums.length <= 200
    :: 0 <= nums[i] <= 200
    :: 1 <= diff <= 50
    :: nums is strictly increasing.

--Reasoning: simple hashmap solution.

--Time complexity:
    O(N), where N is the length of the input array.

--Space complexity:
    O(N), due to the allocation of memory for the hashmap, where N is the length of the input array.

*/

#include <iostream>
#include <unordered_map>
#include <vector>

int arithmeticTriplets(std::vector<int> &nums, int diff) {
  std::unordered_map<int, int> hm;

  int num_of_triplets{0}, l{0}, r{0};

  while (r < nums.size()) {
    int rel_diff = nums[r] - diff;

    if (hm[rel_diff] > 0) {
      hm[nums[r]] = hm[rel_diff] + 1;

      if (hm[nums[r]] >= 3)
        ++num_of_triplets;
    } else
      hm[nums[r]] = 1;

    ++r;
  }

  return num_of_triplets;
}

int main() {
  std::vector<int> nums{0, 1, 4, 6, 7, 10};
  int diff{3};
  std::cout << "Res: " << arithmeticTriplets(nums, diff) << "\n\n"; // 2

  nums = {4, 5, 6, 7, 8, 9};
  diff = 2;
  std::cout << "Res: " << arithmeticTriplets(nums, diff) << "\n\n"; // 2

  nums = {1, 2, 3, 4, 6, 8, 9, 11, 13, 17, 19, 21};
  diff = 2;
  std::cout << "Res: " << arithmeticTriplets(nums, diff) << "\n\n"; // 4

  nums = {2, 4, 5, 7, 8};
  diff = 1;
  std::cout << "Res: " << arithmeticTriplets(nums, diff) << "\n\n"; // 0

  return 0;
}