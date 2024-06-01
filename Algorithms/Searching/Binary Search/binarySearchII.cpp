/*
-- Algorithm: Binary Search - Alternative approach

  - Definition:
  Search algorithm that finds the position of a target value within a sorted array by repeatedly
  dividing the search interval in half.

  - Reasoning:
  This approach is based on an efficient way to iterate through the elements of the array. The
  idea is to make jumps and slow the speed when we get closer to the search target.
    1. iterate over the input array from left to right, and set the initial jump length to n/2.
    2. at each step, halve the jump length: first n/4, then n/8, n/16, etc., until the length is 1.
    3. after the jumps, either the target element has been found or it's not in the array.
  During the search, the variable "jump" contains the current jump length. The
  time complexity of the algorithm is O (log n),

  - Time complexity:
      O(log n), where n is the size of the input array, since the code in the while loop is performed
      at most twice for each jump length.

  - Space complexity: O(1), since not input dependent space needs to be allocated.
*/

#include <iostream>
#include <vector>

int binarySearchII(const std::vector<int> &nums, int target) {
  int currIdx = 0, n = nums.size();

  for (int jump = n / 2; jump >= 1; jump = jump / 2) {
    while (currIdx + jump < n && nums.at(currIdx + jump) <= target)
      currIdx += jump;
  }

  return (nums.at(currIdx) == target) ? currIdx : -1;
}

int main() {
  std::vector<int> nums{};
  int idx = -1, target = -1;

  nums = {11, 23, 30, 45, 51, 62, 70, 89, 95, 100, 110};
  target = -1;
  idx = binarySearchII(nums, target);
  std::cout << "-- Value found at position (-1 = NOT FOUND): " << idx << "\n\n";

  target = 23;
  idx = binarySearchII(nums, target);
  std::cout << "-- Value found at position (-1 = NOT FOUND): " << idx << "\n\n";

  target = 95;
  idx = binarySearchII(nums, target);
  std::cout << "-- Value found at position (-1 = NOT FOUND): " << idx << "\n\n";
}