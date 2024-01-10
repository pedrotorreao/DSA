/* * * * * * * * * * * * * * * * * *
Problem: LC 67. Add Binary

--Problem statement:
Given two binary strings a and b, return their sum as a binary string.

  > Example 1:
      Input: a = "11", b = "1"
      Output: "100"

  > Example 2:
    Input: a = "1010", b = "1011"
    Output: "10101"

--Constraints:
    :: 1 <= a.length, b.length <= 10^4
    :: a and b consist only of '0' or '1' characters.
    :: Each string does not contain leading zeros except for the zero itself.

--Inputs:
  - strings 'a' and 'b' representing binary numbers

--Outputs:
  - string corresponding to the binary number result of the sum of the input strings

--Reasoning: Simple iterative approach

--Time complexity:
    :: O(n), where n is the total number of elements in the largest input string.

--Space complexity:
    :: O(1), since no additional input-dependent space is allocated. Not considering the
  space allocated for the outputs string.
* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>

class Solution {
public:
  static std::string addBinary(std::string a, std::string b) {
    if (a.empty())
      return b;
    if (b.empty())
      return a;

    std::string res;
    int i;

    if (a.size() >= b.size()) {
      res = a;
      i = a.size() - 1;
    } else {
      res = b;
      i = b.size() - 1;
    }

    int ai = a.size() - 1, bi = b.size() - 1;
    bool carry = false;

    while (ai >= 0 && bi >= 0) {
      if (a.at(ai) == '1' && b.at(bi) == '1') {
        if (carry)
          res.at(i) = '1';
        else
          res.at(i) = '0';
        carry = true;
      } else if (a.at(ai) == '0' && b.at(bi) == '0') {
        if (carry) {
          res.at(i) = '1';
          carry = false;
        } else
          res.at(i) = '0';
      } else {
        if (carry) {
          res.at(i) = '0';
        } else {
          res.at(i) = '1';
          carry = false;
        }
      }
      --ai, --bi, --i;
    }

    while (carry && i >= 0) {
      if (res.at(i) == '1')
        res.at(i) = '0';
      else {
        res.at(i) = '1';
        carry = false;
      }
      --i;
    }

    if (carry)
      res = "1" + res;

    return res;
  }
};

int main() {
  std::string a, b;

  a = "11";
  b = "1";
  std::cout << "The sum of binary numbers \"" << a << "\" and \"" << b << "\" is: \"" << Solution::addBinary(a, b) << "\"\n";

  a = "1010";
  b = "1011";
  std::cout << "The sum of binary numbers \"" << a << "\" and \"" << b << "\" is: \"" << Solution::addBinary(a, b) << "\"\n";
}
