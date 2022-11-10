/******************************************************************************
LC 76. Minimum Window Substring
*******************************************************************************/
/*
--Problem statement:
  Given two strings s and t of lengths m and n respectively, return the minimum
  window substring of s such that every character in t (including duplicates) is
  included in the window. If there is no such substring, return the empty string "".

  The testcases will be generated such that the answer is unique.

  > Example 1:
      Input: s = "ADOBECODEBANC", t = "ABC"
      Output: "BANC"
      Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

  > Example 2:
      Input: s = "a", t = "a"
      Output: "a"
      Explanation: The entire string s is the minimum window.

  > Example 3:
      Input: s = "a", t = "aa"
      Output: ""
      Explanation: Both 'a's from t must be included in the window.
      Since the largest window of s only has one 'a', return empty string.

--Input:
  string: strings s and t

--Output:
  string: minimum window substring of s

--Constraints:
    :: m == s.length
    :: n == t.length
    :: 1 <= m, n <= 105
    :: s and t consist of uppercase and lowercase English letters.

--Reasoning: See comments below.

--Time complexity:
    O(T_SIZE + S_SIZE), where T_SIZE and S_SIZE are the sizes of the strings 't' and 's',
    respectively. The inner while loop may be tricky, but it is valid to mention that it
    only runs one full iteration, at most.

--Space complexity:
    At most, O(26 lower case letters + 26 upper case letters) = O(52) ~= O(1).
*/

#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

std::string minWindow(std::string s, std::string t) {
  std::string ans{""};
  const int S_SIZE = s.size(),
            T_SIZE = t.size();

  if (S_SIZE < T_SIZE) // if 's' is smaller than 't', 's' can't possibly contain all character in 't'.
    return ans;

  bool validWindowFound = false; // boolean that indicates that a result was found.

  int minWindowSize = std::numeric_limits<int>::max(), // size of the shortest substring of 's' containing t's characters.
      curWindowSize = 0,                               // size of the current windows/substring being analyzed.
      missing = T_SIZE,                                // counter for the number of characters of 't' that need to be found in 's'.
      start = 0,                                       // pointer to the start of the current valid window.
      newStart = 0,                                    // pointer used to shrink the current valid window.
      end = 0;                                         // pointer to the end of the current window.

  std::unordered_map<char, int> hm; // hashmap for counting the frequencies of each character in 't'.
  for (const char &c : t)           // TC: O(T_SIZE)
    ++hm[c];

  // search for a valid window in 's':
  while (end < S_SIZE) {       // TC: O(S_SIZE)
    char currChar = s.at(end); // current character in 's'

    // 1.: if 'currChar' exists in 't':
    if (hm[currChar] > 0)
      // 1.a.: there is one less character missing, so decrement 'missing'
      --missing;

    // decrement 'currChar' frequency count, if 'currChar' does not exist in 't'
    // hm[currChar] will become negative:
    --hm[currChar];

    // 2.: if we've found a valid window, shrink the window by moving its start pointer:
    while (missing == 0) {
      validWindowFound = true;

      // 2.a.: calculate the current window's length
      curWindowSize = end - newStart + 1;
      if (minWindowSize > curWindowSize) {
        // 2.a.: update 'minWindowSize' if it's the smallest window so far.
        minWindowSize = curWindowSize;
        // 2.a.: update the 'start' of the window to be the start of the new best window.
        start = newStart;
      }
      // 2.b.: shrink the window:
      //    -> if s[newStart] exist in 't', hm[s[newStart]] is zero at this point so, after we increment it, it will become +ve;
      //    -> if s[newStart] doesn't exist in 't', hm[s[newStart]] is negative since it was never mapped and it was decremented
      //    in the outer while loop when 'end' passed by it;
      ++hm[s.at(newStart)];

      //    -> if hm[s[newStart]] is +ve (i.e. we've found a character that is present in 't'), we then increment 'missing' to
      //    indicate that the current window left border (i.e. newStart) is the beginning of a new possibly valid window. Also
      //    since we map the character at 'newStart' before incremeting 'newStart' itself, if there is no other valid windows
      //    (i.e. common characters with 't'), we can get out of this inner while loop since newStart still holds the previous
      //    valid left border; otherwise, it always increments up until the start of a new window.
      if (hm[s.at(newStart)] > 0)
        ++missing;

      //    -> shrink the window until we find a new possibly valid window:
      ++newStart;
    }

    ++end;
  }

  ans = validWindowFound ? s.substr(start, minWindowSize) : "";

  return ans;
}

int main() {
  std::string s{""}, t{""};

  s = "ADOBECODEBANC";
  t = "ABC";
  std::cout << minWindow(s, t) << "\n";

  return 0;
}