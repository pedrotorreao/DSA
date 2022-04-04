/*********************************************************************************************/
/* Problem: Contains Duplicate II (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an integer array 'nums' and an integer 'k', return true if there are two distinct indices
  'i' and 'j' in the array such that nums[i] == nums[j] and abs(i - j) <= k.

  > Example 1:
    Input: nums = [1,2,3,1], k = 3
    Output: true

  > Example 2:
    Input: nums = [1,0,1,1], k = 1
    Output: true

  > Example 3:
    Input: nums = [1,2,3,1,2,3], k = 2
    Output: false

--Inputs:
  -int[]: array of integers
  -int: target integer

--Output:
  - boolean: whether it is possible or not to meet the conditions

--Constraints:
  1 <= nums.length <= 105
  -109 <= nums[i] <= 109
  0 <= k <= 105

--Reasoning: See comments below.

--Time complexity:
  O(N), where N is the size of the array.

--Space complexity:
  O(N), where N is the size of the array, for the worst case where the array contains
  only unique numbers.
*/

#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
  // hash map to map the array elements to their indices, num[i] : i
  std::unordered_map<int, int> hm;
  // iterate over the array adding each array element and its position
  // to the hash map and checking at each step if the current number
  // has been seen (added to the hash map) before. If so, check if the
  // the difference between their positions is less than 'k', if it is,
  // the conditions were satisfied, return true:
  for (int i{0}; i < nums.size(); ++i) {
    if (hm.find(nums.at(i)) != hm.end()) {
      if (abs(hm[nums.at(i)] - i) <= k)
        return true;
      else
        hm[nums.at(i)] = i;
    } else {
      hm[nums.at(i)] = i;
    }
  }

  return false;
}

int main() {
  std::cout << std::boolalpha;

  std::vector<int> nums;
  int k;

  nums = {1, 2, 3, 1};
  k = 3;
  std::cout << "Contains duplicate: " << containsNearbyDuplicate(nums, k) << "\n";

  nums = {1, 0, 1, 1};
  k = 1;
  std::cout << "Contains duplicate: " << containsNearbyDuplicate(nums, k) << "\n";

  nums = {1, 2, 3, 1, 2, 3};
  k = 2;
  std::cout << "Contains duplicate: " << containsNearbyDuplicate(nums, k) << "\n";

  return 0;
}
