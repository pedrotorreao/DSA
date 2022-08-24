/**********************************************************************************************************/
/* Problem: LC 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold ********/
/**********************************************************************************************************/
/*
--Problem statement:
  Given an array of integers 'arr' and two integers 'k' and 'threshold', return the number of sub-arrays of
  size 'k' and average greater than or equal to 'threshold'.

  > Example 1:
      Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
      Output: 3
      Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other
      sub-arrays of size 3 have averages less than 4 (the threshold).

  > Example 2:
      Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
      Output: 6
      Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not
      integers.

--Inputs:
  -int[]: array of integers 'arr'
  -int: window size 'k'
  -int: threshold

--Output:
  -int: number of sub-arrays of size 'k' and average greater than or equal to 'threshold'

--Constraints:
    :: 1 <= arr.length <= 105
    :: 1 <= arr[i] <= 104
    :: 1 <= k <= arr.length
    :: 0 <= threshold <= 104

--Reasoning: See comments below.

--Time complexity: O(N), where N is the length of the array.

--Space complexity: O(1), no input dependent memory is allocated.
*/

#include <iostream>
#include <vector>

int numOfSubarrays(std::vector<int> &arr, int k, int threshold) {
  const int N = arr.size();

  // if array size is less than the window size, asnwer is zero:
  if (N < k)
    return 0;

  int runningSum{0}, goodSubArrs{0};
  double currAvrg{0.0};

  // this first loop runs up to the kth-1 element to setup the window
  // and calculate the running sum for the first k elements:
  for (int i{0}; i < k; ++i) {
    runningSum += arr.at(i);
  }
  // calculate the average for the current window elements:
  currAvrg = (runningSum / static_cast<float>(k));

  goodSubArrs = (currAvrg >= threshold) ? goodSubArrs + 1 : goodSubArrs;

  for (int i{k}; i < N; ++i) {
    runningSum += (arr.at(i) - arr.at(i - k));

    // calculate the average for the current window elements:
    currAvrg = (runningSum / static_cast<float>(k));

    // increments the result in case the current average satisfies the acceptance
    // criteria, i.e. if it is greater than or equal to the threshold:
    goodSubArrs = (currAvrg >= threshold) ? goodSubArrs + 1 : goodSubArrs;
  }

  return goodSubArrs;
}

int main() {
  std::vector<int> arr{2, 2, 2, 2, 5, 5, 5, 8};
  int k{3}, thresh{4}, expec{3};

  int res = numOfSubarrays(arr, k, thresh);
  std::cout << "Number of good subarrays: " << res
            << "\t--Expected: " << expec << (res == expec ? "\t#PASSED" : "\t#FAILED")
            << "\n";

  arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
  k = 3, thresh = 5, expec = 6;
  res = numOfSubarrays(arr, k, thresh);
  std::cout << "Number of good subarrays: " << res
            << "\t--Expected: " << expec << (res == expec ? "\t#PASSED" : "\t#FAILED")
            << "\n";

  arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
  k = 11, thresh = 5, expec = 0;
  res = numOfSubarrays(arr, k, thresh);
  std::cout << "Number of good subarrays: " << res
            << "\t--Expected: " << expec << (res == expec ? "\t#PASSED" : "\t#FAILED")
            << "\n";

  return 0;
}