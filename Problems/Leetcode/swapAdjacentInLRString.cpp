/***
Problem: LC 777. Swap Adjacent in LR String
(https://leetcode.com/problems/swap-adjacent-in-lr-string/description/)

--Problem statement:
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists
of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR".
Given the starting string 'start' and the ending string 'end', return True if and only if there exists
a sequence of moves to transform 'start' to 'end'.

  Example 1:
    Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
    Output: true
    Explanation: We can transform start to end following these steps:
    RXXLRXRXL ->
    XRXLRXRXL ->
    XRLXRXRXL ->
    XRLXXRRXL ->
    XRLXXRRLX

  Example 2:
    Input: start = "X", end = "L"
    Output: false

--Inputs:
  string: start and end strings

--Output:
  bool: boolean indicating whether 'start' can be turned into 'end'.

--Constraints:
    :: 1 <= start.length <= 10^4
    :: start.length == end.length
    :: Both start and end will only consist of characters in 'L', 'R', and 'X'.

--Reasoning: Two pointers approach, see below.

--Time complexity:
    O(N), since we only traverse the whole string once, where N is the length of the input strings.

--Space complexity:
    O(1), since no input dependent space needs to be allocated.

*/

#include <iostream>
#include <string>

class Solution {
public:
  bool canTransform(std::string start, std::string end) {
    const int N = start.size(); // start.size() == end.size()
    int sPtr = 0, ePtr = 0;

    while (sPtr < N || ePtr < N) {
      // move pointer to next valid character in 'start', skipping the 'X's:
      while (sPtr < N && start[sPtr] == 'X')
        ++sPtr;
      // move pointer to next valid character in 'end', skipping the 'X's:
      while (ePtr < N && end[ePtr] == 'X')
        ++ePtr;

      // if we've reached the end of both strings, a transformation is possible:
      if (sPtr == N && ePtr == N)
        return true;

      // if only on of the strings reached the end, we don't have the same number of valid letters:
      if (sPtr == N || ePtr == N)
        return false;

      // if the characters at the pointed positions do not match, the transformation is not possible:
      if (start[sPtr] != end[ePtr])
        return false;

      // if current letter in 'start' is 'L' and sPtr is less than ePtr, this means that this letter
      // would need to be moved right, which is not possible for 'L's:
      if (start[sPtr] == 'L' && sPtr < ePtr)
        return false;
      // if current letter in 'start' is 'R' and sPtr is greater than ePtr, this means that this letter
      // would need to be moved left, which is not possible for 'R's:
      if (start[sPtr] == 'R' && sPtr > ePtr)
        return false;

      // move pointers:
      ++sPtr;
      ++ePtr;
    }

    return true;
  }
};

int main() {
  std::cout << std::boolalpha;

  Solution s;
  std::string start{}, end{};
  bool res{false}, expected{false};

  start = "RXXLRXRXL", end = "XRLXXRRLX";
  res = s.canTransform(start, end);
  expected = true;
  std::cout << "> String \'" << start << "\' can be transformed into string \'" << end << "\': " << res
            << (res == expected ? "\t\tPASSED" : "\t\tFAILED") << "\n";
  return 0;
}