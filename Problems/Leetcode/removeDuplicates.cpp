/* * * * * * * * * * * * * * * * * *
Problem: LC 26. Remove Duplicates From Sorted Array

--Problem statement:
Given an integer array 'nums' sorted in non-decreasing order, remove the duplicates
in-place such that each unique element appears only once. The relative order of
the elements should be kept the same. Then return the number of unique elements
in 'nums'.

Consider the number of unique elements of 'nums' to be 'k', to get accepted, you need
to do the following things:
  - Change the array ''nums'' such that the first k elements of 'nums' contain the
  unique elements in the order they were present in 'nums' initially. The remaining
  elements of 'nums' are not important as well as the size of 'nums'.
  - Return k.

  > Example 1:
      Input: nums = [1,1,2]
      Output: 2, nums = [1,2,_]
      Explanation: Your function should return k = 2, with the first two elements of nums
    being 1 and 2 respectively.
      It does not matter what you leave beyond the returned k (hence they are underscores).

  > Example 2:
      Input: nums = [0,0,1,1,1,2,2,3,3,4]
      Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
      Explanation: Your function should return k = 5, with the first five elements of nums
    being 0, 1, 2, 3, and 4 respectively.

--Constraints:
    :: 1 <= nums.length <= 3 * 10^4
    :: -100 <= nums[i] <= 100
    :: nums is sorted in non-decreasing order.

--Inputs:
  - int[]: array of integers

--Outputs:
  - int: number of unique elements.

--Reasoning: Simple two-pointers approach

--Time complexity:
    :: O(n), where n is the total number of elements in the input array.

--Space complexity:
    :: O(1), since no additional input-dependent space is allocated.
* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <vector>

void display1D(const std::vector<int> &nums, int k) {
  std::cout << "[ ";

  for (int i = 0; i < k; i++) {
    std::cout << nums[i] << " ";
  }

  std::cout << "]\n";
}

class Solution {
public:
  static int removeDuplicates(std::vector<int> &nums) {
    int right_ptr = 1, left_ptr = 1;

    while (right_ptr < nums.size()) {
      if (nums.at(right_ptr) != nums.at(right_ptr - 1)) {
        nums.at(left_ptr) = nums.at(right_ptr);
        ++left_ptr;
      }
      ++right_ptr;
    }

    return left_ptr;
  }
};

int main() {
  std::vector<int> vec{1, 1, 2};
  int k = Solution::removeDuplicates(vec);
  display1D(vec, k);

  vec = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  k = Solution::removeDuplicates(vec);
  display1D(vec, k);
}
