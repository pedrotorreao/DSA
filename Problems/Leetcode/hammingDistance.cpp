/* * * * * * * * * * * * * * * * * *
Problem: LC 461. Hamming Distance

--Problem statement:
The Hamming distance between two integers is the number of positions at which
the corresponding bits are different.
Given two integers x and y, return the Hamming distance between them.

  > Example 1:
      Input: x = 1, y = 4
      Output: 2
      Explanation:
      1   (0 0 0 1)
      4   (0 1 0 0)
            ↑   ↑
      The above arrows point to positions where the corresponding bits are different.

  > Example 2:
      Input: x = 3, y = 1
      Output: 1

--Constraints:
    :: 0 <= x, y <= 2^31 - 1

--Inputs:
  - int: integers x and y

--Outputs:
  - int: hamming distance

--Reasoning: Use bit manipulation. By XOR-ing the input integers, we get as result an integer for which
the bit representation has 1's where the input numbers differ. Example:
    x = 5 -> 0101
    y = 2 -> 0010
      x ^ y = 0101 ^ 0010 = 0111 = 7
  After that, we just need to count the number of bits which are 1.

--Time complexity:
    :: O(log n), where n is the result of the XOR operation between the input integers.

--Space complexity:
    :: O(1), since no additional input-dependent space is allocated.

* * * * * * * * * * * * * * * * * */

#include <iostream>

class Solution {
public:
  static int hammingDistance_1(int x, int y) {
    int r = (x ^ y), diff = 0;

    while (r) {
      if (r & 1)
        ++diff;

      r /= 2;
    }

    return diff;
  }

  static int hammingDistance_2(int x, int y) {
    int r = (x ^ y), diff = 0;

    while (r) {
      ++diff;

      r = (r - 1) & r;
    }

    return diff;
  }
};

int main() {
  int x = 0, y = 0;

  x = 1;
  y = 4;
  std::cout << "The hamming distance between \"" << x << "\" and \"" << y << "\" is: \"" << Solution::hammingDistance_1(x, y) << "\"\n";
  std::cout << "The hamming distance between \"" << x << "\" and \"" << y << "\" is: \"" << Solution::hammingDistance_2(x, y) << "\"\n";

  x = 5;
  y = 2;
  std::cout << "The hamming distance between \"" << x << "\" and \"" << y << "\" is: \"" << Solution::hammingDistance_1(x, y) << "\"\n";
  std::cout << "The hamming distance between \"" << x << "\" and \"" << y << "\" is: \"" << Solution::hammingDistance_2(x, y) << "\"\n";
}
