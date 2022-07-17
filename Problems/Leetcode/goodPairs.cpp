/*********************************************************************************************/
/* Problem: LC 1512. Number of Good Pairs ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array of integers nums, return the number of good pairs. A pair (i, j) is called
  good if nums[i] == nums[j] and i < j.

  > Example 1:
      Input: nums = [1,2,3,1,1,3]
      Output: 4
      Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

  > Example 2:
    Input: nums = [1,1,1,1]
    Output: 6
    Explanation: Each pair in the array are good.

  > Example 3:
    Input: nums = [1,2,3]
    Output: 0

--Input:
  int nums[i]: array of integers

--Output:
  int: the number of good pairs

--Constraints:
  1 <= nums.length <= 100
  1 <= nums[i] <= 100

--Reasoning:
  Iterate over the input array mapping its elements, nums[i], to the frequency in which they
  appear. For each element, check if its has been seen before. If it has, the current element
  is able to form pairs with all of its previous occurences hm[i], so update the number of
  good pairs to account for it (pairs += hm[i]). If not, add it to the hash table.

--Time complexity:
  O(N), where N is the size of the input array.

--Space complexity:
  O(N), due to the hash table in the worst in which there are only distinct integers,
   where N is the size of the input array..

*/

#include <iostream>
#include <unordered_map>
#include <vector>

int numIdenticalPairs(std::vector<int> &nums) {
  std::unordered_map<int, int> hm; // num[i] : freq
  int pairs{0};

  for (const auto &n : nums) {
    if (hm.find(n) != hm.end()) {
      pairs += hm[n];
    }
    ++hm[n];
  }

  return pairs;
}

int main() {
  std::vector<int> vec{1, 1, 1, 1};
  std::cout << "# of good pairs: " << numIdenticalPairs(vec) << "\n";

  return 0;
}