/******************************************************************************
Problem: Permutation in a string.
*******************************************************************************/
/*
--Problem statement:
  Given two strings s1 and s2, return true if s2 contains a permutation of s1,
  or false otherwise. In other words, return true if one of s1's permutations
  is the substring of s2.

  > Example 1:
    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").

  > Example 2:
    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false

--Inputs:
  string: input strings s1 and s2

--Output:
  bool: whether one of s1's permutations is the substring of s2.

--Constraints:
    :: 1 <= s1.length, s2.length <= 104
    :: s1 and s2 consist of lowercase English letters.

--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <string>
#include <unordered_map>

bool checkInclusion(std::string &s1, std::string &s2) {
  // validate inputs:
  if ((s1.size() > s2.size()) || (s1.size() == 0) || (s2.size() == 0))
    return false;

  // get total length:
  const int L = s2.size();
  // get window size:
  const int W = s1.size();

  //... solution here

  return false;
}

int main() {
  std::cout << std::boolalpha;

  std::string str1{"ab"}, str2{"eidbaooo"};
  bool expec{true};
  bool res = checkInclusion(str1, str2);
  std::cout << "\"" << str2 << "\" contains a permutation of \"" << str1 << "\": "
            << res << "    --Expected: " << expec
            << (res == expec ? "    ::PASSED\n" : "    ::FAILED\n");

  str2 = "eidboaoo";
  expec = false;
  res = checkInclusion(str1, str2);
  std::cout << "\"" << str2 << "\" contains a permutation of \"" << str1 << "\": "
            << res << "    --Expected: " << expec
            << (res == expec ? "    ::PASSED\n" : "    ::FAILED\n");

  str1 = "adc";
  str2 = "dcda";
  expec = true;
  res = checkInclusion(str1, str2);
  std::cout << "\"" << str2 << "\" contains a permutation of \"" << str1 << "\": "
            << res << "    --Expected: " << expec
            << (res == expec ? "    ::PASSED\n" : "    ::FAILED\n");
  return 0;
}