/*********************************************************************************************/
/* Problem: LC 494. Target Sum ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are given an integer array 'nums' and an integer 'target'. You want to build an expression
  out of 'nums' by adding one of the symbols '+' and '-' before each integer in 'nums' and then
  concatenate all the integers.
  For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate
  them to build the expression "+2-1".

  Return the number of different expressions that you can build, which evaluates to 'target'.

  > Example 1:
      Input: nums = [1,1,1,1,1], target = 3
      Output: 5
      Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
      -1 + 1 + 1 + 1 + 1 = 3
      +1 - 1 + 1 + 1 + 1 = 3
      +1 + 1 - 1 + 1 + 1 = 3
      +1 + 1 + 1 - 1 + 1 = 3
      +1 + 1 + 1 + 1 - 1 = 3

  > Example 2:
      Input: nums = [1], target = 1
      Output: 1

--Inputs:
  int[]: integer array 'nums'
  int: integer 'target'

--Output:
  int: number of different expressions that you can build, which evaluates to 'target'

--Constraints:
    :: 1 <= nums.length <= 20
    :: 0 <= nums[i] <= 1000
    :: 0 <= sum(nums[i]) <= 1000
    :: -1000 <= target <= 1000

--Reasoning: See comments below.

--Time complexity: O(N), since we cache calculations, we don't repeat the same calculations over and over.

--Space complexity: O(N), where N is the size on the 'nums' input array.

*/

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// we need a custom hash function in order to be able to add std::pair as keys to
// an std::unordered_map:
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const std::pair<T1, T2> &p) const {
    auto hash1 = std::hash<T1>{}(p.first);
    auto hash2 = std::hash<T2>{}(p.second);

    if (hash1 != hash2) {
      return hash1 ^ hash2;
    }

    // If hash1 == hash2, their XOR is zero.
    return hash1;
  }
};

// for simplicity:
typedef std::unordered_map<std::pair<int, int>, int, hash_pair> HashMap_Pair;

int targetSumDP(const std::vector<int> &nums, int target, int position, int currentSum, HashMap_Pair &dp) {
  // if we have reached the end of the array, return whether it was possible to match 'target' or not:
  if (position >= nums.size())
    return (currentSum == target);

  std::pair<int, int> p = std::make_pair(position, currentSum);

  // if we have cached the results for the current position and current sum, return it:
  if (dp.find(p) != dp.end())
    return dp[p];

  // otherwise, recur for the two possibilities (summing current nums[i] and subtracting):
  dp[p] = (targetSumDP(nums, target, position + 1, currentSum + nums.at(position), dp) +
           targetSumDP(nums, target, position + 1, currentSum - nums.at(position), dp));

  return dp[p];
}

int findTargetSumWays(const std::vector<int> &nums, int target) {
  //  dp[id,total]: # of different ways to achieve 'target' from position 'id'
  HashMap_Pair dp;
  int pos = 0;
  int currentSum{0};

  return targetSumDP(nums, target, pos, currentSum, dp);
}

int main() {
  std::vector<int> vec{1, 5, 2, 6, 3, 4, 1};
  int target{20}, sumWays{0};

  sumWays = findTargetSumWays(vec, target);
  std::cout << sumWays << "\n";

  return 0;
}
