/***
Problem: LC 930. Binary Subarrays With Sum
(https://leetcode.com/problems/binary-subarrays-with-sum/description/)

--Problem statement:
Given a binary array 'nums' and an integer 'goal', return the number of non-empty subarrays with a sum 'goal'.
A subarray is a contiguous part of the array.

  > Example 1:
      Input: nums = [1,0,1,0,1], goal = 2
      Output: 4
      Explanation:
        The 4 subarrays are bolded and underlined below:
            [1,0,1,0,1]
            [1,0,1,0,1]
            [1,0,1,0,1]
            [1,0,1,0,1]

  > Example 2:
      Input: nums = [0,0,0,0,0], goal = 0
      Output: 15

--Inputs:
    int[]: binary array 'nums'

--Output:
    int[]: number of non-empty subarrays which satisfy the problem condition.

--Constraints:
    :: 1 <= nums.length <= 3 * 10^4
    :: nums[i] is either 0 or 1.
    :: 0 <= goal <= nums.length

--Reasoning: Use the prefix sum pattern + hashmap.

--Time complexity: O(n), where 'n' is the input size. We traverse the array only once performing constant time work.

--Space complexity: O(n), where 'n' is the input size, since we might need to store every prefix sum in the hashmap if
they are all unique.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int numSubarraysWithSum(std::vector<int> &nums, int goal) {
    int count = 0,                           // subarrays which sum up to 'goal'
        prefixSum = 0;                       // running total
    std::unordered_map<int, int> prefixSums; // previously computed sums:
                                             //  [key: value] => [sum: count of subarrays with this sum]
    prefixSums[0] = 1;                       // initialize hashmap to account for subarrays that start from the beginning

    for (int num : nums) {
      // add current element 'num' to the prefix sum:
      prefixSum += num;
      // if 'prefixSum - goal' exists in the 'prefixSums' hashmap, there are subarrays which sum up to 'goal', so
      // add the value of 'prefixSums[prefixSum - goal]' to 'count':
      if (prefixSums.find(prefixSum - goal) != prefixSums.end()) {
        count += prefixSums[prefixSum - goal];
      }
      // increment the value of 'prefixSum' in the hashmap by 1:
      prefixSums[prefixSum]++;
    }

    return count;
  }
};

int main() {
  std::cout << std::boolalpha;

  Solution sol;

  std::vector<int> nums{};
  int res{-1}, expected{-1}, goal{-1};

  nums = {1, 0, 1, 0, 1};
  goal = 2;
  res = sol.numSubarraysWithSum(nums, goal);
  expected = {4};
  std::cout << ">> Answer: " << res << ((res == expected) ? "\t--PASSED\n" : "\t--FAILED\n");

  nums = {0, 0, 0, 0, 0};
  goal = 0;
  res = sol.numSubarraysWithSum(nums, goal);
  expected = {15};
  std::cout << ">> Answer: " << res << ((res == expected) ? "\t--PASSED\n" : "\t--FAILED\n");

  nums = {1, 1, 0, 1, 1};
  goal = 2;
  res = sol.numSubarraysWithSum(nums, goal);
  expected = {5};
  std::cout << ">> Answer: " << res << ((res == expected) ? "\t--PASSED\n" : "\t--FAILED\n");

  nums = {1, 1, 1, 1, 0, 0};
  goal = 3;
  res = sol.numSubarraysWithSum(nums, goal);
  expected = {4};
  std::cout << ">> Answer: " << res << ((res == expected) ? "\t--PASSED\n" : "\t--FAILED\n");

  nums = {0, 0, 0, 0, 1, 0, 1};
  goal = 1;
  res = sol.numSubarraysWithSum(nums, goal);
  expected = {12};
  std::cout << ">> Answer: " << res << ((res == expected) ? "\t--PASSED\n" : "\t--FAILED\n");

  return 0;
}

/*  ALGORITHM WALKTHROUGH - STEP BY STEP:
    nums = [1,0,1,0,1], goal = 2

    initialization: count = 0, prefixSum = 0, prefixSums = {0: 1}

    > i = 0, nums = nums[0] = 1
    prefixSum += 1 -> prefixSum = 1
    comp = prefixSum - goal = 1 - 2 = -1
    comp in prefixSums? NO
    prefixSums[prefixSum]++ -> prefixSums[1] = 1 -> prefixSums = {0: 1, 1: 1}

    > i = 1, num = nums[1] = 0
    prefixSum += 0 -> prefixSum = 1
    comp = prefixSum - goal = 1 - 2 = -1
    comp in prefixSums? NO
    prefixSums[prefixSum]++ -> prefixSums[1] = 2 -> prefixSums = {0: 1, 1: 2}

    > i = 2, num = nums[2] = 1
    prefixSum += 1 -> prefixSum = 2
    comp = prefixSum - goal = 2 - 2 = 0
    comp in prefixSums? YES:
        count += prefixSums[comp] -> count = 1
    prefixSums[prefixSum]++ -> prefixSums[2] = 1 -> prefixSums = {0: 1, 1: 2, 2: 1}

    > i = 3, num = nums[3] = 0
    prefixSum += 0 -> prefixSum = 2
    comp = prefixSum - goal = 2 - 2 = 0
    comp in prefixSums? YES:
        count += prefixSums[comp] -> count = 2
    prefixSums[prefixSum]++ -> prefixSums[2] = 2 -> prefixSums = {0: 1, 1: 2, 2: 2}

    > i = 4, num = nums[4] = 1
    prefixSum += 1 -> prefixSum = 3
    comp = prefixSum - goal = 3 - 2 = 1
    comp in prefixSums? YES:
        count += prefixSums[comp] -> count = 4
    prefixSums[prefixSum]++ -> prefixSums[3] = 1 -> prefixSums = {0: 1, 1: 2, 2: 2, 3: 1}

    > i = 5 == nums.size(): EXIT LOOP

    return count -> return 4
*/