/* * * * * * * * * * * * * * * * * *
Problem: LC 27. Remove Element

--Problem statement:
Given an integer array 'nums' and an integer 'val', remove all occurrences of 'val' in
'nums' in-place. The order of the elements may be changed. Then return the number of
elements in 'nums' which are not equal to 'val'.

Consider the number of elements in
'nums' which are not equal to 'val' be 'k', to get accepted, you need to do the following
things:
  - Change the array 'nums' such that the first 'k' elements of 'nums' contain the elements
  which are not equal to 'val'. The remaining elements of 'nums' are not important as well
  as the size of 'nums'.
  - Return 'k'.

  > Example 1:
      Input: nums = [3,2,2,3], val = 3
      Output: 2, nums = [2,2,_,_]
      Explanation: Your function should return k = 2, with the first two elements of nums
    being 2.

  > Example 2:
      Input: nums = [0,1,2,2,3,0,4,2], val = 2
      Output: 5, nums = [0,1,4,0,3,_,_,_]
      Explanation: Your function should return k = 5, with the first five elements of nums
    containing 0, 0, 1, 3, and 4.

  Note: - The elements can be returned in any order.
        - It does not matter what you leave beyond the returned k (hence they are underscores).


--Constraints:
    :: 0 <= nums.length <= 100
    :: 0 <= nums[i] <= 50
    :: 0 <= val <= 100

--Inputs:
  - int[]: array of integers, nums
  - int: integer to be removed, val

--Outputs:
  - int: number of elements in the input array which are not equal to val, k

--Reasoning: Simple two-pointers approach

--Time complexity:
    :: O(n), where n is the total number of elements in the input array.

--Space complexity:
    :: O(1), since no additional input-dependent space is allocated.
* * * * * * * * * * * * * * * * * */

#include <algorithm>
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
  static int removeElement(std::vector<int> &nums, int val) {
    if (nums.empty())
      return 0;

    if (nums.size() == 1 && nums.at(0) != val)
      return 1;

    int right_ptr = 0, left_ptr = 0, cnt = 0;

    while (right_ptr < nums.size()) {
      if (nums.at(right_ptr) != val) {
        nums.at(left_ptr) = nums.at(right_ptr);
        ++left_ptr;
      }

      ++right_ptr;
    }

    return left_ptr;
  }
};

int main() {
  std::vector<int> vec{3, 2, 2, 3};
  int val = 3;
  int k = Solution::removeElement(vec, val);
  std::sort(vec.begin(), vec.begin() + k);
  display1D(vec, k);

  vec = {0, 1, 2, 2, 3, 0, 4, 2};
  val = 2;
  k = Solution::removeElement(vec, val);
  std::sort(vec.begin(), vec.begin() + k);
  display1D(vec, k);
}
