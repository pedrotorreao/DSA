/*********************************************************************************************/
/* Problem: Contains Duplicate (LC)  ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an integer array 'nums', return true if any value appears at least twice in the array,
  and return 'false' if every element is distinct.
  > Example:
    a.) Input: nums = [1,2,3,1]                 Output: true
    b.) Input: nums = [1,2,3,4]                 Output: false
    c.) Input: nums = [1,1,1,3,3,4,3,2,4,2]     Output: true

--Inputs:
  - integer array

--Output:
  - boolean

--Constraints:
  1 <= nums.length <= 105
  -109 <= nums[i] <= 109

--Reasoning:
  Iterate through the input array and map each element to a hash set; however, before adding each
  element we check if the same element was not added (seen) before, if it has, it means that there
  are duplicated elements among the input dataset, so we just return 'true'. Otherwise, we'll get
  the end of the input array and no duplicates will have been found, se we return 'false'.

--Time complexity: O(N), where 'N' is the size of the array.

--Space complexity:
  O(N), in the worst case where no duplicates are found and we need to allocate space to every
  element in the input array.
*/

#include <iomanip>
#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicate(std::vector<int> &nums) {
  std::unordered_set<int> hash_set;

  for (const auto &n : nums) {
    if (hash_set.count(n) > 0)
      return true;
    hash_set.insert(n);
  }
  return false;
}

int main() {
  std::cout << std::boolalpha;

  std::vector<int> vec{1, 2, 3, 1};
  std::cout << "Contains duplicate: " << containsDuplicate(vec) << "\n";

  vec = {1, 2, 3, 4};
  std::cout << "Contains duplicate: " << containsDuplicate(vec) << "\n";

  vec = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  std::cout << "Contains duplicate: " << containsDuplicate(vec) << "\n";

  return 0;
}