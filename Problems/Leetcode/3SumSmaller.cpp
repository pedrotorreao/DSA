/*********************************************************************************************/
/* Problem: 259. 3Sum Smaller ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array arr of unsorted numbers and a target sum, count all triplets in it such that
  arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a
  function to return the count of such triplets.

  > Example 1:
  Input: [-1, 0, 2, 3], target=3
  Output: 2
  Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]

  > Example 2:
  Input: [-1, 4, 2, 1, 3], target=5
  Output: 4
  Explanation: There are four triplets whose sum is less than the target:
  [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]


--Inputs:
  -int arr[n]: integer array arr, of unsorted numbers
  -int: targetSum

--Output:
  -int: target sum

--Reasoning: See comments below.

--Time complexity:
    > O(N*log(N)), due to the sorting
    > O(N^2), for the search
    --> O(N*log(N) + N^2) --> O(N^2)

--Space complexity: O(N), worst case scenario.

*/

#include <algorithm>
#include <iostream>
#include <vector>

int searchTriplets(std::vector<int> &arr, int target) {
  int count = 0;
  const int N = arr.size();

  // sort the input array:
  std::sort(arr.begin(), arr.end());

  // we're going to search by using the two-pointers approach:
  //  - left_ptr:   leftmost pointer, defined the first element in the search window
  //  - mid_ptr:    middle pointer, it's moved when the current sum is smaller than target's
  //                and needs to be increased.
  //  - right_ptr:  righmost pointer, it's moved when the current sum is greater than target's
  //                and needs to be reduced.
  for (int left_ptr{0}; left_ptr < N - 2; ++left_ptr) {
    int mid_ptr = left_ptr + 1, right_ptr = N - 1;

    // iterate while the pointers do not meet:
    while (mid_ptr < right_ptr) {
      int currentSum = arr.at(left_ptr) + arr.at(mid_ptr) + arr.at(right_ptr);

      // if current sum is too large, we need a smaller value, decrement the 'right_ptr' to
      // get to a smaller value:
      if (currentSum >= target)
        --right_ptr;
      // otherwise; we have satisfied the condition, so we can increment the counter, but since
      // arr[right_ptr] >= arr[mid_ptr], we could replace arr[right_ptr] with any other value
      // between arr[right_ptr] and arr[mid_ptr] that we'd get a sum which satisfies the constraint,
      // therefore, there are "right_ptr - mid_ptr" elements which can be added to the count in total:
      else {
        count += right_ptr - mid_ptr;
        ++mid_ptr;
      }
    }
  }

  return count;
}

int main() {
  std::vector<int> vec = {};

  vec = {-1, 0, 2, 3};
  std::cout << searchTriplets(vec, 3) << "\n";

  vec = {-1, 4, 2, 1, 3};
  std::cout << searchTriplets(vec, 5) << "\n";
}