/*********************************************************************************************/
/* Problem: The Maximum Subarray (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  We define subsequence as any subset of an array. We define a subarray as a contiguous
  subsequence in an array. Given an array, find the maximum possible sum among:
    1. all nonempty subarrays.
    2. all nonempty subsequences.
  Print the two values as space-separated integers on one line.
  Note that empty subarrays/subsequences should not be considered.

  > Example:
      arr=[-1,2,3,-4,5,10]
    The maximum subarray sum is comprised of elements at inidices [1 to 5]. Their sum is
    (2+3-4+5+10) = 16. The maximum subsequence sum is comprised of elements at indices [1,2,4,5]
    and their sum is (2+3+5+10) = 20.

--Input:
  int arr[n]: an array of integers

--Output:
  int[2]: the maximum subarray and subsequence sums

--Constraints:
  1<=n<=10^5
  -10^4 <= arr[i] <= 10^4

--Reasoning: See comments below.

--Time complexity: O(N), where N is the size of the array.

--Space complexity: O(1), no additional input dependent memory needs to be allocated.

*/

#include <climits>
#include <iostream>
#include <vector>

std::vector<int> maxSubarray(std::vector<int> arr) {
  std::vector<int> res(2, 0);
  int current_sum{0}, best_sum{INT_MIN}, best_seq = arr.at(0);

  for (int i{0}; i < arr.size(); ++i) {
    /* -- Kadane's Algorithm:
    Given an array V of size n, the local maximum at an index i can
    be calculated by following relationship:
        local_max[i] = max(V[i], V[i] + local_max[i-1])
    At each step we got 2 choices: we either take the current element
    and continue with previous sum OR restart a new range.
    */
    current_sum = std::max(arr.at(i), current_sum + arr.at(i));

    if (current_sum > best_sum) {
      best_sum = current_sum;
    }
  }
  res.at(0) = best_sum;

  for (int i{1}; i < arr.size(); ++i) {
    // update the max. subsequence sum to be the largest value between
    // the 'current best', the 'current best + current element' and the
    // 'current element':
    best_seq = std::max(best_seq + arr.at(i), std::max(best_seq, arr.at(i)));
  }
  res.at(1) = best_seq;

  return res;
}

int main() {
  std::vector<int> arr_1{-1, 2, 3, -4, 5, 10};
  std::vector<int> r = maxSubarray(arr_1);
  std::cout << "Max. subarray sum: " << r.at(0) << "\tMax. subsequence sum: " << r.at(1) << "\n";

  arr_1 = {1, 2, 3, 4};
  r = maxSubarray(arr_1);
  std::cout << "Max. subarray sum: " << r.at(0) << "\tMax. subsequence sum: " << r.at(1) << "\n";

  arr_1 = {2, -1, 2, 3, 4, -5};
  r = maxSubarray(arr_1);
  std::cout << "Max. subarray sum: " << r.at(0) << "\tMax. subsequence sum: " << r.at(1) << "\n";

  return 0;
}