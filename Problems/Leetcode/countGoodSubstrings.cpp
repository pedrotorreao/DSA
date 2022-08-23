/*********************************************************************************************/
/* Problem: LC 1876. Substrings of Size Three with Distinct Characters ********/
/*********************************************************************************************/
/*
--Problem statement:
  A string is good if there are no repeated characters. Given a string s​​​​​, return the number of
  good substrings of length three in s​​​​​​.
  Note that if there are multiple occurrences of the same substring, every occurrence should be
  counted.
  A substring is a contiguous sequence of characters in a string.

  > Example 1:
    Input: s = "xyzzaz"
    Output: 1
    Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz".
    The only good substring of length 3 is "xyz".

  > Example 2:
    Input: s = "aababcabc"
    Output: 4
    Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
    The good substrings are "abc", "bca", "cab", and "abc".

--Inputs:
  -std::string

--Output:
  -int: number of good substrings.

--Constraints:
    :: 1 <= s.length <= 100
    :: s​​​​​​ consists of lowercase English letters.

--Reasoning: See comments below.

--Time complexity: O(N), where N is the length of the string.

--Space complexity: O(1), we store at most 3 characters simultaneosly.
*/

#include <iostream>
#include <string>
#include <unordered_map>

int countGoodSubstrings(std::string s) {
  const int windowSize = 3;
  const int stringSize = s.size();

  std::unordered_map<char, int> hm;
  int numOfGoodStrings{0};

  if (stringSize < windowSize)
    return 0;

  for (int i{0}; i < windowSize; ++i)
    ++hm[s.at(i)];

  if (hm.size() == 3)
    ++numOfGoodStrings;

  for (int i{windowSize}; i < stringSize; ++i) {
    char prevLeftBorderChar = s.at(i - windowSize);
    char newRightBorderChar = s.at(i);

    if (!--hm[prevLeftBorderChar])
      hm.erase(prevLeftBorderChar);

    ++hm[newRightBorderChar];

    if (hm.size() == 3)
      ++numOfGoodStrings;
  }

  return numOfGoodStrings;
}

int main() {
  std::string s{"aababcabc"};
  std::cout << "Number of good sub strings in \"" << s << "\": " << countGoodSubstrings(s) << "\n";

  return 0;
}