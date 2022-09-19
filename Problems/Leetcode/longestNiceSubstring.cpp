/*********************************************************************************************/
/* Problem: LC 1763. Longest Nice Substring ********/
/*********************************************************************************************/
/*
--Problem statement:
  A string s is nice if, for every letter of the alphabet that s contains, it appears both in
  uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and
  'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

  Given a string s, return the longest substring of s that is nice. If there are multiple, return
  the substring of the earliest occurrence. If there are none, return an empty string.

  > Example 1:
      Input: s = "YazaAay"
      Output: "aAa"
      Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
      "aAa" is the longest nice substring.

  > Example 2:
      Input: s = "Bb"
      Output: "Bb"
      Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.


  > Example 3:
      Input: s = "c"
      Output: ""
      Explanation: There are no nice substrings.

--Inputs:
  string s: string to be analyzed

--Output:
  string: longest substring of 's' that is nice

--Constraints:
    :: 1 <= s.length <= 100
    :: s consists of uppercase and lowercase English letters.

--Reasoning: Sliding window approach.

--Time complexity:
    ::Best case - O(N): for a string containing only matching characters, only one pass
  would be needed and no recursive calls would be made.
    ::Worst case - O(N^2): for a string made completely of distinct characters, we'd need
  to make recursive calls or the right partition until we reach the base case, r_str.size() < 2.

--Space complexity: O(N), where N is the length of the original string.

*/

#include <iostream>
#include <string>
#include <unordered_set>

std::string longestNiceSubstring(std::string s) {
  // string is to small to be nice:
  if (s.size() <= 1)
    return "";

  const int S = s.size();
  // create an unordered_set and initialize it with the string characters:
  std::unordered_set<char> charSet(s.begin(), s.end());

  for (int i{0}; i < S; ++i) {
    char lower = tolower(s.at(i));
    char upper = toupper(s.at(i));

    // if current character has its matching lowercase/uppercase character,
    // continue traversing the string:
    if (charSet.count(lower) && charSet.count(upper))
      continue;

    // otherwise, split the string at the unmatched character and evaluate both
    // substrings to find out which substring has the longest nice substring:
    std::string l_str = longestNiceSubstring(s.substr(0, i));
    std::string r_str = longestNiceSubstring(s.substr(i + 1));

    return ((l_str.size() >= r_str.size()) ? l_str : r_str);
  }

  return s;
}

int main() {
  std::cout << longestNiceSubstring("YazaAay") << "\n";
  std::cout << longestNiceSubstring("Bb") << "\n";
  std::cout << longestNiceSubstring("c") << "\n";
  std::cout << longestNiceSubstring("XabcdefFEDCBAy") << "\n";
  std::cout << longestNiceSubstring("abcdefFEDCBAyyyyx") << "\n";

  return 0;
}