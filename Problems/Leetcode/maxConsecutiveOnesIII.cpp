/*********************************************************************/
/* Problem: LC 1004. Max Consecutive Ones III ************************/
/*********************************************************************/
/*
--Problem statement:
Given a binary array 'nums' and an integer 'k', return the maximum number
of consecutive 1's in the array if you can flip at most 'k' 0's.

  > Example 1:
      Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
      Output: 6
      Explanation: [1,1,1,0,0,[1,1,1,1,1,1]]


  > Example 2:
      Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
      Output: 10
      Explanation: [0,0,[1,1,1,1,1,1,1,1,1,1],0,0,0,1,1,1,1]

--Inputs:
  -int[]: array of integers 'nums'
  -int: number of possible flips 'k'

--Output:
  -int: maximum number of consecutive 1's by flip at most 'k' 0's

--Constraints:
    :: 1 <= nums.length <= 105
    :: nums[i] is either 0 or 1
    :: 0 <= k <= nums.length

--Reasoning:
  The question can be also seen as "Find the longest subarray with at most K zeros.
  So, we keep count of the number of 0s found in the current window. If the count is
  greater than K (flips > k), then the current windows is not valid and we decrease
  it by moving its left border (increment L_border) until the number of zeros in the
  current window is at most K (flips <= K). We could also say that the maximum window
  gets carried throughout the iteration until a larger one is found.

--Time complexity: O(N), where N is the length of the array.

--Space complexity: O(1), no input dependent memory is allocated.
*/

#include <iostream>
#include <vector>

int longestOnes(std::vector<int> &nums, int k) {
  if (nums.size() < k)
    return 0;

  const int N = nums.size();
  int L_border{0}, R_border{0}, flips{0};

  while (R_border < N) {
    if (nums.at(R_border) == 0)
      ++flips;

    if (flips > k) {
      if (nums.at(L_border) == 0)
        --flips;
      ++L_border;
    }
    ++R_border;
  }
  return R_border - L_border;
}

int main() {
  std::vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k{2}, expec{6};
  int res = longestOnes(nums, k);
  std::cout << "Longest Ones subarray: " << res
            << "\t--Expected: " << expec
            << (res == expec ? "\t--[PASSED]" : "\t--[FAILED]")
            << "\n";

  nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
  k = 3, expec = 10;
  res = longestOnes(nums, k);
  std::cout << "Longest Ones subarray: " << res
            << "\t--Expected: " << expec
            << (res == expec ? "\t--[PASSED]" : "\t--[FAILED]")
            << "\n";

  nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1};
  k = 3, expec = 10;
  res = longestOnes(nums, k);
  std::cout << "Longest Ones subarray: " << res
            << "\t--Expected: " << expec
            << (res == expec ? "\t--[PASSED]" : "\t--[FAILED]")
            << "\n";

  return 0;
}

/*
Dry Run:

[0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
flips=0       R=0     L=0

R=0,L=0:    [_0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
    A[R] == 0 ? Y: ++flips -> flips = 1
    flips > k ? N
    ++R -> R=1

R=1,L=0:    [0,_0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
    A[R] == 0 ? Y: ++flips -> flips = 2
    flips > k ? N
    ++R -> R=2

R=2,L=0:    [0,0,_1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
    A[R] == 0 ? N
    flips > k ? N
    ++R -> R=3

R=3,L=0:    [0,0,1,_1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
    A[R] == 0 ? N
    flips > k ? N
    ++R -> R=4

R=4,L=0:    [0,0,1,1,_0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
    A[R] == 0 ? Y: ++flips -> flips = 3
    flips > k ? N
    ++R -> R=5

R=5,L=0:    [0,0,1,1,0,_0,1,1,1,0,1,1,0,0,0,1,1,1,1]
    A[R] == 0 ? Y: ++flips -> flips = 4
    flips > k ? Y:
        A[L] == 0: --flips -> flips = 3
        ++L -> L=1
    ++R -> R=6

R=6,L=1:    [0,0,1,1,0,0,_1,1,1,0,1,1,0,0,0,1,1,1,1]
    A[R] == 0 ? N
    flips > k ? N
    ++R -> R=7

R=7,L=1:    [0,0,1,1,0,0,1,_1,1,0,1,1,0,0,0,1,1,1,1]
    A[R] == 0 ? N
    flips > k ? N
    ++R -> R=8

R=8,L=1:    [0,0,1,1,0,0,1,1,_1,0,1,1,0,0,0,1,1,1,1]
    A[R] == 0 ? N
    flips > k ? N
    ++R -> R=9

R=9,L=1:    [0,0,1,1,0,0,1,1,1,_0,1,1,0,0,0,1,1,1,1]
    A[R] == 0 ? Y: ++flips -> flips = 4
    flips > k ? Y:
        A[L] == 0: --flips -> flips = 3
        ++L -> L=2
    ++R -> R=10

R=10,L=2:    [0,0,1,1,0,0,1,1,1,0,_1,1,0,0,0,1,1,1,1]
    A[R] == 0 ? N
    flips > k ? N
    ++R -> R=11

R=11,L=2:    [0,0,1,1,0,0,1,1,1,0,1,_1,0,0,0,1,1,1,1]
    A[R] == 0 ? N
    flips > k ? N
    ++R -> R=12

R=12,L=2:    [0,0,1,1,0,0,1,1,1,0,1,1,_0,0,0,1,1,1,1]
    A[R] == 0 ? Y: ++flips -> flips = 4
    flips > k ? Y:
        A[L] == 0 ? N
        ++L -> L=3
    ++R -> R=13

R=13,L=3:    [0,0,1,1,0,0,1,1,1,0,1,1,0,_0,0,1,1,1,1]
    A[R] == 0 ? Y: ++flips -> flips = 5
    flips > k ? Y:
        A[L] == 0 ? N
        ++L -> L=4
    ++R -> R=14

R=14,L=4:    [0,0,1,1,0,0,1,1,1,0,1,1,0,0,_0,1,1,1,1]
    A[R] == 0 ? Y: ++flips -> flips = 6
    flips > k ? Y:
        A[L] == 0 ? Y: --flips -> flips = 5
        ++L -> L=5
    ++R -> R=15

R=15,L=5:    [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,_1,1,1,1]
    A[R] == 0 ? N
    flips > k ? Y:
        A[L] == 0 ? Y: --flips -> flips = 4
        ++L -> L=6
    ++R -> R=16

R=16,L=6:    [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,_1,1,1]
    A[R] == 0 ? N
    flips > k ? Y:
        A[L] == 0 ? N
        ++L -> L=7
    ++R -> R=17

R=17,L=7:    [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,_1,1]
    A[R] == 0 ? N
    flips > k ? Y:
        A[L] == 0 ? N
        ++L -> L=8
    ++R -> R=18

R=18,L=8:    [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,_1]
    A[R] == 0 ? N
    flips > k ? Y:
        A[L] == 0 ? N
        ++L -> L=9
    ++R -> R=19


return (R - L) = (19 - 9) = 10


*/