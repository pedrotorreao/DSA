/*********************************************************************************************/
/* Problem: LC 338. Counting Bits ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
  ans[i] is the number of 1's in the binary representation of i.

  > Example 1:
  Input: n = 2
  Output: [0,1,1]
  Explanation:
      0 --> 0
      1 --> 1
      2 --> 10

  > Example 2:
  Input: n = 5
  Output: [0,1,1,2,1,2]
  Explanation:
      0 --> 0
      1 --> 1
      2 --> 10
      3 --> 11
      4 --> 100
      5 --> 101

Follow up:
    It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in
    linear time O(n) and possibly in a single pass? Can you do it without using any built-in
    function (i.e., like __builtin_popcount in C++)?

--Input:
  int: n.

--Output:
  int[]: array ans of length n + 1.

--Constraints:
  :: 0 <= n <= 105.
*/

#include <iostream>
#include <vector>

template <typename T>
void display1D(const std::vector<T> &vec) {
  const int N = vec.size();

  std::cout << "[";
  for (int i{0}; i < N; ++i) {
    std::cout << vec.at(i);
    if (i + 1 < N)
      std::cout << ',';
  }
  std::cout << "]\n\n";
}

/* Approach #1
--Reasoning:
    Iterate over all the numbers from 0 to n (inclusive), and for each i (0 <= i <= n), count the
    number of 1 bits it has by perfoming a bitwise &1 operation and bit shifting i until it becomes
    invalid (i=0).

--Time complexity:
    O(log(N)): for the inner while loop that, at each bitshift, divides the its range by 2;
    O(N+1)~=O(N):  for the outer for loop which runs for every integer between 0 and N.

--Space complexity: O(1), if we don't take into account the output array.
*/
std::vector<int> countBits_1(int n) {
  std::vector<int> bit_count(n + 1, 0);

  for (int i{0}; i <= n; ++i) {
    int curr = i;
    while (curr > 0) {
      bit_count.at(i) += (curr & 1);

      curr >>= 1;
    }
  }

  return bit_count;
}

/* Approach #2
--Reasoning:
    Iterate over all the numbers from 0 to n (inclusive), and for each i (0 <= i <= n), use the built-in
    C++ function '__builtin_popcount()' to count the number of 1 bits it has.

--Time complexity: O(# of bits in 'n')

--Space complexity: O(1), if we don't take into account the output array.
*/
std::vector<int> countBits_2(int n) {
  std::vector<int> bit_count(n + 1, 0);

  for (int i{0}; i <= n; ++i) {
    bit_count.at(i) = __builtin_popcount(i);
  }

  return bit_count;
}

/* Approach #3
--Reasoning:
    Iterate over all the numbers from 0 to n (inclusive), and for each i (0 <= i <= n), the number of 1's in
    its binary representation will be
        bit_count[i] += bit_count[i >> 2] + (i & 1)

    Note: - even i's have LSB equal to 0
          - odd i's have LSB equal to 1
          - the difference between 2*i and i is 1 bit, the LSB; consider i=7:
              2*i = 14: 1110
              i = 7:    0111
          so, for each i, we can use the previously calculated bit_count[i / 2] = bit_count[i >> 2], and only check
          its LSB to account for odd values. This use of previously calculated values works as some sort of caching
          avoind repeated work and optimizing our solution.

--Time complexity:
    O(N), since by using the previous calculated results eliminates the need for an inner loop - O(log(N)), and makes
    it so that at each iteration we only need to perform O(1) work (bit_count[i] += bit_count[i >> 2] + (i & 1)).

--Space complexity: O(1), if we don't take into account the output array.
*/
std::vector<int> countBits_3(int n) {
  std::vector<int> bit_count(n + 1, 0);

  for (int i{1}; i <= n; ++i) {
    int curr = i;

    bit_count.at(i) += bit_count.at(i >> 1) + (i & 1);
  }

  return bit_count;
}

int main() {
  int n{0};
  std::vector<int> res{};

  n = 2;
  res = countBits_3(n);
  std::cout << "Expect: [0,1,1]\n";
  std::cout << "Result: ";
  display1D(res);

  n = 5;
  res = countBits_3(n);
  std::cout << "Expect: [0,1,1,2,1,2]\n";
  std::cout << "Result: ";
  display1D(res);
}