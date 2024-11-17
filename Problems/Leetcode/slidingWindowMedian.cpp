/***
Problem: LC 480. Sliding Window Median
(https://leetcode.com/problems/sliding-window-median/description/)

--Problem statement:
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value.
So the median is the mean of the two middle values.
    > For examples, if arr = [2,3,4], the median is 3.
    > For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very
left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves
right by one position.

Return the median array for each window in the original array. Answers within 10^-5 of the actual value will be accepted.

> Example 1:
    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
    Explanation:
      Window position                Median
      ---------------                -----
      [1  3  -1] -3  5  3  6  7        1
       1 [3  -1  -3] 5  3  6  7       -1
       1  3 [-1  -3  5] 3  6  7       -1
       1  3  -1 [-3  5  3] 6  7        3
       1  3  -1  -3 [5  3  6] 7        5
       1  3  -1  -3  5 [3  6  7]       6

> Example 2:
    Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
    Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]

--Inputs:
  :: int[]: integer array 'nums'
  :: int: window size, 'k'

--Output:
  :: int[]: median array for each window in the original array

--Constraints:
  :: 1 <= k <= nums.length <= 10^5
  :: -2^31 <= nums[i] <= 2^31 - 1

--Reasoning:
    Lean on the C++ STL algorithms:
    - <vector> .insert(const_iterator position, const value_type& val):
        :: inserts new element before the element at the specified 'position'.
        :: linear on the number of elements inserted plus the number of elements moved.
    - <vector> .erase(const_iterator position):
        :: removes from the vector a single element at 'position'.
        :: linear on the number of elements erased plus the number of elements moved.
    - <algoritm> lower_bound(ForwardIterator first, ForwardIterator last, const T& val):
        :: returns an iterator pointing to the first element in the range [first,last) which does not compare less than 'val'.
        :: it can be used to insert a number in the correct order and to get find the exact value to be deleted.
        :: logarithmic in the distance between 'first' and 'last'.

    See more comments in the code below.

--Time complexity: O((n-k)*k)

--Space complexity: O(n + k)

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
    vector<double> kSizedMedian;
    vector<long long> medians;

    // initialize a k-sized window:
    for (int i{0}; i < k; i++) {
      medians.insert(lower_bound(medians.begin(), medians.end(), nums.at(i)), nums.at(i)); // O(k),
                                                                                           // since 'k' is the size of the window.
    }

    double currentMedian = 0.0;
    // even-sized window, take the average of the middle values:
    if (k % 2 == 0) {
      currentMedian = (medians.at(k / 2) / 2.0) + (medians.at(k / 2 - 1) / 2.0);
    }
    // odd-sized window, take the average of the middle values:
    else {
      currentMedian = static_cast<double>(medians.at(k / 2));
    }
    // add first calculated median to the result:
    kSizedMedian.push_back(currentMedian);

    for (int i{k}; i < nums.size(); i++) { // O(n-k)
      // remove element that is getting out of the sliding window, i.e. left border:
      medians.erase(lower_bound(medians.begin(), medians.end(), nums.at(i - k))); // O(k),
                                                                                  // since we may need to shift elements by 1 position.

      // insert element that is being included in the sliding window, i.e. right border, in the correct position:
      medians.insert(lower_bound(medians.begin(), medians.end(), nums.at(i)), nums.at(i)); // O(k),
                                                                                           // since we may need to shift elements by 1 position.

      // even-sized window, take the average of the middle values:
      if (k % 2 == 0) {
        currentMedian = (medians.at(k / 2) / 2.0) + (medians.at(k / 2 - 1) / 2.0);
      }
      // odd-sized window, take the average of the middle values:
      else {
        currentMedian = static_cast<double>(medians.at(k / 2));
      }
      // add first calculated median to the result:
      kSizedMedian.push_back(currentMedian);
    }

    return kSizedMedian;
  }

  void display1D(const vector<double> &v) {
    cout << "[ ";
    for (const double &n : v) {
      cout << n << " ";
    }
    cout << "]\n";
  }
};

int main() {
  vector<int> nums;
  vector<double> result;
  int k;

  Solution s;

  nums = {1, 3, -1, -3, 5, 3, 6, 7};
  k = 3;
  result = s.medianSlidingWindow(nums, k);
  s.display1D(result);

  nums = {1, 2, 3, 4, 2, 3, 1, 4, 2};
  result = s.medianSlidingWindow(nums, k);
  s.display1D(result);

  return 0;
}