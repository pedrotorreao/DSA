/******************************************************************************
Problem: LC 3. Longest Substring Without Repeating Characters
*******************************************************************************/
/*
--Problem statement:
  Given a string 's', find the length of the longest substring without repeating
  characters.

  > Example 1:
  Input: s = "abcabcbb"
  Output: 3
  Explanation: The answer is "abc", with the length of 3.

  > Example 2:
  Input: s = "bbbbb"
  Output: 1
  Explanation: The answer is "b", with the length of 1.

  > Example 3:
  Input: s = "pwwkew"
  Output: 3
  Explanation: The answer is "wke", with the length of 3.
  Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

--Inputs:
  std::string: input string 's'.

--Output:
  std::string: longest substring without repeating characters.

--Constraints:
    :: 0 <= s.length <= 5 * 104
    :: s consists of English letters, digits, symbols and spaces.

--Reasoning:
 We use a sliding window approach, where we iterate over the input string, moving the 'right' pointer
 while we have unique characters and, once we find a character that was already seen and is part of
 the current subtring, we move the 'left' pointer (shrinking the window) until the window becomes
 valid again, i.e. w/ no repeated characters.

--Time Complexity: O(N), we iterate over all the elements once, where N is the length of the string.

--Space Complexity: O(N), due to storing memory in a hashset, where N is the length of the string.
*/

#include <iostream>
#include <string>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
  const int SIZE = s.size();

  if (SIZE <= 1)
    return SIZE;

  int l = 0, r = 0, curr = 0, best = 0;
  std::unordered_set<char> seen;

  while (r < SIZE) {
    // if current character is not already present in the current subtring,
    // add it to the hashset and check if the new substring is the best we've
    // found so far:
    if (!seen.count(s.at(r))) {
      seen.insert(s.at(r));
      best = std::max(best, r - l + 1);
      ++r;
    }
    // current character is repeated, shrink the window:
    else {
      seen.erase(s.at(l));
      ++l;
    }
  }

  return best;
}

int main() {
  std::string s{""};
  int expec{0}, res{0};

  s = "abcabcbb";
  expec = 3;
  res = lengthOfLongestSubstring(s);
  std::cout << "Length of longest substr: " << res
            << "    --Expected: " << expec
            << (res == expec ? "     [PASSED]\n\n" : "     [FAILED]\n\n");

  s = "bbbbb";
  expec = 1;
  res = lengthOfLongestSubstring(s);
  std::cout << "Length of longest substr: " << res
            << "    --Expected: " << expec
            << (res == expec ? "     [PASSED]\n\n" : "     [FAILED]\n\n");

  s = "pwwkew";
  expec = 3;
  res = lengthOfLongestSubstring(s);
  std::cout << "Length of longest substr: " << res
            << "    --Expected: " << expec
            << (res == expec ? "     [PASSED]\n\n" : "     [FAILED]\n\n");
}