/*********************************************************************************************/
/* Problem: Single Number (LC)  ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a non-empty array of integers 'nums', every element appears twice except for one. Find
  that single one. You must implement a solution with a linear runtime complexity and use only
  constant extra space.

  > Example:
    a.) Input: nums = [2,2,1]                     Output: 1
    b.) Input: nums = [4,1,2,1,2]                 Output: 4
    c.) Input: nums = [1]                         Output: 1

--Inputs:
  - integer array

--Output:
  - integer

--Constraints:
  1 <= nums.length <= 3 * 10^4
  -3 * 104 <= nums[i] <= 3 * 10^4
  Each element in the array appears twice except for one element which appears only once.

--Reasoning:
  Iterate through the input array and map each element to a hash set; however, before
  adding a new element to the hash set we check if it's not present already, if it is
  we remove it instead of adding it. In this way, at the end of the iteration, all elements
  will have been removed except one, the single number, so we just return it.

--Time complexity: O(N), where 'N' is the size of the array.

--Space complexity:
  O(1), since only one element will be left in the hash set once we are done. However, one could
  argue that for the edge case where the array is partitioned arround the single number half the
  elements of the input array would need to be allocated to the hash set before being deleted.
    Ex: array = [1,2,3,4,5,6,7,8,7,6,5,4,3,2,1]
        hash set = [1,2,3,4,5,6,7,8]
*/

#include <iomanip>
#include <iostream>
#include <unordered_set>
#include <vector>

int singleNumber(std::vector<int> &nums) {
  std::unordered_set<int> hash_set;

  for (const auto &n : nums) {
    if (hash_set.count(n) > 0)
      hash_set.erase(n);
    else
      hash_set.insert(n);
  }

  auto itr = hash_set.begin();

  return *itr;
}

int main() {
  std::vector<int> vec{2, 2, 1};
  std::cout << "Single Number: " << singleNumber(vec) << "\n";

  vec = {4, 1, 2, 1, 2};
  std::cout << "Single Number: " << singleNumber(vec) << "\n";

  vec = {1};
  std::cout << "Single NUmber: " << singleNumber(vec) << "\n";

  return 0;
}