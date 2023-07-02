/*********************************************************************************************/
/* Problem: 457. Circular Array Loop   ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are playing a game involving a circular array of non-zero integers nums. Each nums[i]
  denotes the number of indices forward/backward you must move if you are located at index i:
    - If nums[i] is positive, move nums[i] steps forward, and
    - If nums[i] is negative, move nums[i] steps backward.

  Since the array is circular, you may assume that moving forward from the last element puts you
  on the first element, and moving backwards from the first element puts you on the last element.

  A cycle in the array consists of a sequence of indices seq of length k where:
    - Following the movement rules above results in the repeating index sequence:
       seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
    - Every nums[seq[j]] is either all positive or all negative.
    - k > 1

  Return true if there is a cycle in nums, or false otherwise.


  Example 1:
    Input: nums = [2,-1,1,2,2]
    Output: true
    Explanation:
      The graph shows how the indices are connected. White nodes are jumping forward, while red
      is jumping backward. We can see the cycle 0 --> 2 --> 3 --> 0 --> ..., and all of its nodes
      are white (jumping in the same direction).

  Example 2:
    Input: nums = [-1,-2,-3,-4,-5,6]
    Output: false
    Explanation:
      The graph shows how the indices are connected. White nodes are jumping forward, while red
      is jumping backward. The only cycle is of size 1, so we return false.

  Example 3:
    Input: nums = [1,-1,5,1,4]
    Output: true
    Explanation:
      The graph shows how the indices are connected. White nodes are jumping forward, while red
      is jumping backward. We can see the cycle 0 --> 1 --> 0 --> ..., and while it is of size > 1,
      it has a node jumping forward and a node jumping backward, so it is not a cycle. We can see
      the cycle 3 --> 4 --> 3 --> ..., and all of its nodes are white (jumping in the same direction).

--Inputs:
  -int[]: array of integers nums

--Output:
  -boolean: boolean value indicating whether there is a cycle or not

--Constraints:
  :: 1 <= nums.length <= 5000
  :: -1000 <= nums[i] <= 1000
  :: nums[i] != 0

--Reasoning: Two pointers approach, see comments below.

--Time complexity:
  O(N^2), where N is the size of the list, since we are iterating over all the elements in the array
  trying to find a cycle for each one of them.

--Space complexity: O(1), no additional input dependent space is allocated.

*/

#include <iostream>
#include <vector>

class Solution {
public:
  static bool circularArrayLoop(const std::vector<int> &nums) {
    const int N = nums.size();
    // look for a cycle for each element in 'nums':
    for (int i{0}; i < N; ++i) {
      // direction in which we are moving:
      bool movingForward = (nums.at(i) >= 0);
      // slow and fast pointers:
      int slow = i, fast = i;

      do {
        // advance one step for the slow pointer:
        slow = getNextIndex(nums, movingForward, slow, N);
        // advance one step for the fast pointer:
        fast = getNextIndex(nums, movingForward, fast, N);
        // if still valid, advance one more step for the fast pointer:
        if (fast != -1)
          fast = getNextIndex(nums, movingForward, fast, N);
      }
      // keep moving the pointers while both pointers are still valid and a cycle
      // has not yet been found:
      while (slow != -1 && fast != -1 && slow != fast);

      // if pointers are valid and the same position, a cycle has been found during
      // traversal:
      if (slow != -1 && slow == fast)
        return true;
    }

    return false;
  }

private:
  static int getNextIndex(const std::vector<int> &nums, bool isForward, int curr, int sz) {
    bool currDirection = (nums.at(curr) >= 0);

    // change of directions, since a cycle should not contain both forward
    // and backward movements, the current path does not represent a valid cycle:
    if (isForward != currDirection)
      return -1;

    // calculate the next index (add the array size, sz, to account for
    // negative numbers):
    int nextIndex = (curr + nums.at(curr) + sz) % sz;

    // one element cycle, since the cycle should have more than one element, the
    // current path does not represent a valid cycle:
    if (curr == nextIndex)
      return -1;

    return nextIndex;
  }
};

int main() {
  std::cout << std::boolalpha;

  std::vector<int> arr{1, 2, -1, 2, 2};
  std::cout << "Loop exists for [1, 2, -1, 2, 2]: "
            << Solution::circularArrayLoop(arr) << "\n"; // T

  arr = {2, 2, -1, 2};
  std::cout << "Loop exists for [2, 2, -1, 2]: "
            << Solution::circularArrayLoop(arr) << "\n"; // T

  arr = {2, 1, -1, -2};
  std::cout << "Loop exists for [2, 1, -1, -2]: "
            << Solution::circularArrayLoop(arr) << "\n"; // F

  arr = {2, -1, 1, 2, 2};
  std::cout << "Loop exists for [2, -1, 1, 2, 2]: "
            << Solution::circularArrayLoop(arr) << "\n"; // T

  arr = {-1, -2, -3, -4, -5, 6};
  std::cout << "Loop exists for [-1, -2, -3, -4, -5, 6]: "
            << Solution::circularArrayLoop(arr) << "\n"; // F

  arr = {1, -1, 5, 1, 4};
  std::cout << "Loop exists for [1, -1, 5, 1, 4]: "
            << Solution::circularArrayLoop(arr) << "\n"; // T

  return 0;
}