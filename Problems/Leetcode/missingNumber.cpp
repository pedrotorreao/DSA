/*********************************************************************************************/
/* Problem: LC 268. Missing Number ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array nums containing n distinct numbers in the range [0, n], return the only number
  in the range that is missing from the array.

  > Example 1:
      Input: nums = [3,0,1]
      Output: 2
      Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
      2 is the missing number in the range since it does not appear in nums.

  > Example 2:
      Input: nums = [0,1]
      Output: 2
      Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is
      the missing number in the range since it does not appear in nums.

  > Example 3:
      Input: nums = [9,6,4,2,3,5,7,0,1]
      Output: 8
      Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is
      the missing number in the range since it does not appear in nums.

 --Inputs:
  -int[]: array of integers containing 'n' distinct numbers.

--Output:
  -int: missing number.

--Constraints:
  :: n == nums.length
  :: 1 <= n <= 104
  :: 0 <= nums[i] <= n
  :: All the numbers of nums are unique.

--Time complexity: O(N)

--Space complexity: O(1)

*/

#include <iostream>
#include <numeric>
#include <vector>

int missingNumber(std::vector<int> &nums) {
  int incomplete_sum = std::accumulate(nums.begin(), nums.end(), 0);
  int full_sum = 0, n = nums.size();

  while (n) {
    full_sum += n;
    --n;
  }

  return (full_sum - incomplete_sum);
}

void display1D(const std::vector<int> &nums) {
  for (const int &num : nums)
    std::cout << num << " ";
}

int main() {
  std::vector<int> nums;
  int missing = 0;

  nums = {3, 0, 1};
  missing = missingNumber(nums);
  std::cout << "The missing number in [ ";
  display1D(nums);
  std::cout << "] is: " << missing << "\n\n";

  nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  missing = missingNumber(nums);
  std::cout << "The missing number in [ ";
  display1D(nums);
  std::cout << "] is: " << missing << "\n\n";

  return 0;
}

/*
Alternative Approach (not mine): Using bitwise logic
    ->  any number XORed with itself is 0:
            - 3 ^ 3 = 11 ^ 11 = 0
    ->  any number XORed with 0 is the number itself:
            - 3 ^ 0 = 11 ^ 00 = 11 = 3
    ->  these properties are associative (order doesn't matter), i.e.
        (A^B^C) = (A^C^B) = (B^C^A) = (C^A^B) etc.:
            - 3 ^ 5 ^ 3 = (011 ^ 101) ^ 011 = 110 ^ 011 = 101 = 5
So, if we have a range of numbers [0, n] where there is 1 element missing, if we
iterate 'i' from 0 to n XORing 'i' with each nums[i], all the elements that are present
in nums[i] have nums[i]^i = 0,but there will be 1 value of 'i' that won't have its
match in nums[] and this value XORed with the result of the other XORs will be itself:
    nums = [3,0,1]      n = nums.size() = 3      0 <= i < n

    -> nums[0] ^ 0 ^ nums[1] ^ 1 ^ nums[2] ^ 2 ^ n
    -> 3 ^ 0 ^ 0 ^ 1 ^ 1 ^ 2 ^ 3 = 3 ^ (0 ^ 0) ^ (1 ^ 1) ^ 2 ^ 3
    -> 3 ^ 0 ^ 0 ^ 2 ^ 3 = 3 ^ (0 ^ 0) ^ 2 ^ 3
    -> 3 ^ 0 ^ 2 ^ 3 = (3 ^ 3) ^ 0 ^ 2
    -> 0 ^ 0 ^ 2 = (0 ^ 0) ^ 2
    -> 0 ^ 2 = 2

  Ex 1:
    int missingNumber(vector<int>& nums) {
        int missing{0};
        for(int i{0}; i < nums.size(); i++) {
            missing = missing ^ i;
            missing = missing ^ nums.at(i);
        }
        missing = missing ^ nums.size();

        return missing;
    }

  Ex 2:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int missing = N;
        for(int i{0}; i < N; i++) {
            missing ^= (i ^ nums.at(i));
        }

        return missing;
    }

*/