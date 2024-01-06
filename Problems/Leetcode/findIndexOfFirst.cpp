/* * * * * * * * * * * * * * * * * *
Problem: LC 28. Find the Index of the First Occurrence in a String

--Problem statement:
Given two strings 'needle' and 'haystack', return the index of the first
occurrence of 'needle' in 'haystack', or -1 if 'needle' is not part of 'haystack'.

  > Example 1:
      Input: haystack = "sadbutsad", needle = "sad"
      Output: 0
      Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0,
    so we return 0.

  > Example 2:
      Input: haystack = "leetcode", needle = "leeto"
      Output: -1
      Explanation: "leeto" did not occur in "leetcode", so we return -1.

--Constraints:
    :: 1 <= haystack.length, needle.length <= 104
    :: haystack and needle consist of only lowercase English characters.

--Inputs:
  - string: haystack
  - string: needle

--Outputs:
  - int: index of the first occurrence of needle in haystack

--Reasoning: Simple two-pointers approach

--Time complexity:
    :: O(n), where n is the total number of elements in the input array.

--Space complexity:
    :: O(1), since no additional input-dependent space is allocated.
* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>

class Solution {
public:
  // --Reasoning: Use the find() method from the string class.
  // --Time complexity: O(n*m), where 'n' is the length of the string 'haystack'
  // and 'm' is the length of the string 'needle'.
  // --Space complexity: O(1)
  static int findIdOfFirstOccurrence_1(const std::string &haystack, const std::string &needle) {
    std::size_t found = haystack.find(needle);
    if (found != std::string::npos)
      return found;

    return -1;
  }
  // --Reasoning: Two-pointers approach.
  // --Time complexity: O(n*m), where 'n' is the length of the string 'haystack'
  // and 'm' is the length of the string 'needle'.
  // --Space complexity: O(1)
  static int findIdOfFirstOccurrence_2(const std::string &haystack, const std::string &needle) {
    int i{0}, j{0};

    while (j < haystack.size()) {
      if (haystack.at(j) == needle.at(i)) {
        ++i;
      } else {
        j = j - i;
        i = 0;
      }
      ++j;

      if (i == needle.size())
        return j - i;
    }
    return -1;
  }
};

int main() {
  std::string haystack{"sadbutsad"}, needle{"sad"};
  int k = Solution::findIdOfFirstOccurrence_1(haystack, needle);
  std::cout << "First occurrence of \"" << needle << "\" found in \"" << haystack << "\"at position: " << k << "\n";
  k = Solution::findIdOfFirstOccurrence_2(haystack, needle);
  std::cout << "First occurrence of \"" << needle << "\" found in \"" << haystack << "\"at position: " << k << "\n\n";

  haystack = "leetcode", needle = "leeto";
  k = Solution::findIdOfFirstOccurrence_1(haystack, needle);
  std::cout << "First occurrence of \"" << needle << "\" found in \"" << haystack << "\"at position: " << k << "\n";
  k = Solution::findIdOfFirstOccurrence_2(haystack, needle);
  std::cout << "First occurrence of \"" << needle << "\" found in \"" << haystack << "\"at position: " << k << "\n\n";

  haystack = "mississipi", needle = "issip";
  k = Solution::findIdOfFirstOccurrence_1(haystack, needle);
  std::cout << "First occurrence of \"" << needle << "\" found in \"" << haystack << "\"at position: " << k << "\n";
  k = Solution::findIdOfFirstOccurrence_2(haystack, needle);
  std::cout << "First occurrence of \"" << needle << "\" found in \"" << haystack << "\"at position: " << k << "\n\n";
}
