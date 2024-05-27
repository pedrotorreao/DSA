/***
Problem: LC 215. Kth Largest Element in Array
(https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

--Problem statement:
  Given an integer array nums and an integer k, return the kth largest element in the array.
  Note that it is the kth largest element in the sorted order, not the kth distinct element.
  Can you solve it without sorting?

  > Example 1:
    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5

  > Example 2:
    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4

--Inputs:
  int[]: integer array nums
  int: integer k

--Output:
  int: the kth largest element in the array

--Constraints:
    :: 1 <= k <= nums.length <= 10^5
    :: -10^4 <= nums[i] <= 10&4

--Time complexity: considering n as the size of the input array,
  -> To insert the first k values - TC1: O(k * log(k))
  -> To iterate over the remaining array adding updating the heap with larger values - TC2: O((n-k) * log(k))
  -> TC: O(k*log(k) + (n-k)*log(k)), which is asymptotically equal to: O(n * log(k))

--Space complexity: O(k), since we only store the top k values in the heap.

*/

#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  static int findKthLargest(std::vector<int> &nums, int k) {
    // Insert the the first k numbers in the min heap (TC: O(K * log(K))):
    std::priority_queue<int, std::vector<int>, std::greater<int>> minH(
        nums.begin(), nums.begin() + k);

    // Iterate over the remaining numbers of the input array, if the number from the array is
    // bigger than the top (smallest) number of the min-heap, remove the top number from
    // heap and add the number from array. This will ensure that we always have the ‘k’ largest
    // numbers in the heap with the top of which being the kth largest number (TC: O((N-K) * log(K))):
    for (int i = k; i < nums.size(); ++i) {
      if (nums.at(i) > minH.top()) {
        minH.pop();
        minH.push(nums.at(i));
      }
    }

    return minH.top();
  }
};

int main() {
  std::vector<int> nums;
  int k{0};

  nums = {3, 1, 5, 12, 2, 11};
  k = 3;
  std::cout << "-- kth largest value: " << Solution::findKthLargest(nums, k) << "\n";

  nums = {5, 12, 11, -1, 12};
  k = 3;
  std::cout << "-- kth largest value: " << Solution::findKthLargest(nums, k) << "\n";

  nums = {3, 2, 1, 5, 6, 4};
  k = 2;
  std::cout << "-- kth largest value: " << Solution::findKthLargest(nums, k) << "\n";

  nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  k = 4;
  std::cout << "-- kth largest value: " << Solution::findKthLargest(nums, k) << "\n";

  return 0;
}