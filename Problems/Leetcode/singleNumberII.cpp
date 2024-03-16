/* * * * * * * * * * * * * * * * * *
Problem: LC 137. Single Number II

--Problem statement:
Given an integer array nums where every element appears three times except for one,
which appears exactly once. Find the single element and return it. You must implement a solution
with a linear runtime complexity and use only constant extra space.

  > Example 1:
      Input: nums = [2,2,3,2]
      Output: 3

  > Example 2:
      Input: nums = [0,1,0,1,0,1,99]
      Output: 99

--Constraints:
    :: 1 <= nums.length <= 3 * 10^4
    :: -2^31 <= nums[i] <= 2^31 - 1
    :: Each element in nums appears exactly three times except for one element which appears once.

--Inputs:
  -int[]: integer array nums.

--Output:
  -int*: integer that appear only once in the input array.

--Reasoning: Use bit manipulation, see comments below.

--Time complexity: O(N), where N is the size of the input array. Even though the outer loop runs in
O(32) and the inner loop runs in O(N): O(32 * N), since constants are not relevant, it's still O(N).

--Space complexity: O(1), no input dependent space is allocated.
* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <vector>

void display1D(const std::vector<int> &v);

class Solution {
public:
  static int singleNumber(std::vector<int> &nums) {
    int n = nums.size();
    long int singleNum = 0;

    // iterate from the LSB (i=0) to the MSB (i=31) of a 32 bit integer - O(32):
    for (int i{0}; i < 32; i++) {
      // keep track of the number of 1s at the current bit position for all the
      // numbers in nums[]:
      int bitsSetByPosition = 0;
      // iterate over all the numbers in the input array - O(n):
      for (auto num : nums) {
        // check the bit position i for all the numbers on nums:
        // a. right-shift num by i positions to have the bit at position i as the LSB:
        int numRightShiftedByi = num >> i;
        // b. get the value of the LSB by performing a bitwise AND operation with 1:
        int bitValueAtPosi = numRightShiftedByi & 1;
        // c. add this result to the current count of bits set at position i, bitsSetByPosition:
        bitsSetByPosition = bitsSetByPosition + bitValueAtPosi;

        /* -- code above could be simplified to the following:
            bitsSetByPosition += (num >> i) & 1;
        */
      }
      // now that we have the amount of 1s at bit position i for all the values in num[],
      // we take the modulo of this result by 3 to handle the numbers that are repeated 3x.
      // since stated that "every element appears 3 times except for one, which appears exactly
      // once.", we either have a balanced count, multiple of 3 (3n), hence "bitsSetByPosition % 3 = 0",
      // or we have an unbalanced count (3n + 1), hence "bitsSetByPosition % 3 = 1", which will
      // contribute to our single number:
      bitsSetByPosition %= 3; // either 0 for three-peats or 1 for the single number.

      // create a bitmask where only the bit at the current position i will be set by left-shifting
      // bitsSetByPosition by i positions, which serves to put the unbalanced bit back to its
      // rigth position:
      int m = bitsSetByPosition << i;

      // use the mask to set the bit at i to 1 in case it is unbalanced by performing a bitwise OR
      // with singleNum, which, after the outer loop finishes evaluating all 32 bits, will hold the
      // number which appears only once:
      singleNum |= m;
    }

    return singleNum;
  }
};

int main() {
  std::vector<int> nums{};
  int expected{0}, res{0};
  bool passed{false};

  nums = {0, 1, 0, 1, 0, 1, 99};
  expected = 99;
  res = Solution::singleNumber(nums);
  passed = res == expected;
  std::cout << "array: ";
  display1D(nums);
  std::cout << "single number: " << res << " -- " << (passed ? "PASSED\n\n" : "FAILED\n\n");

  nums = {2, 2, 3, 2};
  expected = 3;
  res = Solution::singleNumber(nums);
  passed = res == expected;
  std::cout << "array: ";
  display1D(nums);
  std::cout << "single number: " << res << " -- " << (passed ? "PASSED\n\n" : "FAILED\n\n");
}

void display1D(const std::vector<int> &v) {
  std::cout << "[ ";
  for (const auto &num : v) {
    std::cout << num << " ";
  }
  std::cout << "]\n";
}