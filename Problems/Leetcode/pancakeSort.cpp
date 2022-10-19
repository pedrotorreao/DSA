/******************************************************************************
Problem: Pancake Sorting
*******************************************************************************/
/*
--Problem statement:
  Given an array of integers arr, sort the array by performing a series of pancake
  flips. In one pancake flip we do the following steps:
    - Choose an integer k where 1 <= k <= arr.length.
    - Reverse the sub-array arr[0...k-1] (0-indexed).

  For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3,
  we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at
  k = 3.

  Return an array of the k-values corresponding to a sequence of pancake flips
  that sort arr. Any valid answer that sorts the array within (10 * arr.length) flips
  will be judged as correct.

  > Example 1:
      Input: arr = [3,2,4,1]
      Output: [4,2,4,3]
      Explanation:
        We perform 4 pancake flips, with k values 4, 2, 4, and 3.
        Starting state: arr = [3, 2, 4, 1]
        After 1st flip (k = 4): arr = [1, 4, 2, 3]
        After 2nd flip (k = 2): arr = [4, 1, 2, 3]
        After 3rd flip (k = 4): arr = [3, 2, 1, 4]
        After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.

  > Example 2:
      Input: arr = [1,2,3]
      Output: []
      Explanation:
        The input is already sorted, so there is no need to flip anything. Note
        that other answers, such as [3, 3], would also be accepted.

--Inputs:
  int[]: integer array nums

--Output:
  int[]: array of the indexes k corresponding to the ranges flipped until arr is sorted.

--Constraints:
    :: 1 <= arr.length <= 100
    :: 1 <= arr[i] <= arr.length
    :: All integers in arr are unique (i.e. arr is a permutation of the integers
    from 1 to arr.length).

--Reasoning:
  Find the index 'i = max_it*' of the next maximum number 'max'. Reverse (i + 1) numbers,
  so that the 'max' will be at arr[0]. Reverse 'max' numbers, so that 'max' will be at A[N - 1 -i].
  Repeat this process N times.
  Basically,
    .find max value position, i
      -> flip elements 0 to i so that max is at index 0, i.e. arr[0] = max
        -> flip elements 0 to N-i-1 so that max is put last position arr[N-i-1]
          -> this position is now fixed, reduce size (window)
            -> repeat


--Time complexity: O(N^2)

--Space complexity:
    O(1), since the algorithm does not need to allocate input dependent memory, or
    O(N), if we are counting the output array.

*/

#include <algorithm>
#include <iostream>
#include <vector>

void display1D(const std::vector<int> &arr);

std::vector<int> pancakeSort(std::vector<int> &arr) {
  const int N = arr.size();
  std::vector<int> flips{};

  for (int i{0}; i < N; ++i) {
    auto max_it = std::max_element(arr.begin(), arr.end() - i);

    flips.push_back(max_it - arr.begin() + 1);
    std::reverse(arr.begin(), max_it + 1);

    flips.push_back(arr.size() - i);
    std::reverse(arr.begin(), arr.end() - i);
  }
  return flips;
}

int main() {
  std::vector<int> vec{}, flips{};

  vec = {3, 2, 4, 1};
  flips = pancakeSort(vec);
  std::cout << "Flips needed for sorting: ";
  display1D(flips);

  return 0;
}

void display1D(const std::vector<int> &arr) {
  std::cout << "[ ";
  for (const auto &a : arr)
    std::cout << a << " ";

  std::cout << "]\n\n";
}