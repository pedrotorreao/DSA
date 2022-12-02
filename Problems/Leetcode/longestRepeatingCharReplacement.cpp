/*********************************************************************************************/
/* Problem: 424. Longest Repeating Character Replacement ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are given a string 's' and an integer 'k'. You can choose any character of the string and
  change it to any other uppercase English character. You can perform this operation at most 'k'
  times.

  Return the length of the longest substring containing the same letter you can get after performing
  the above operations.

  > Example 1:
  Input: s = "ABAB", k = 2
  Output: 4
  Explanation:
    Replace the two 'A's with two 'B's or vice versa.

  > Example 2:
  Input: s = "AABABBA", k = 1
  Output: 4
  Explanation:
    Replace the one 'A' in the middle with 'B' and form "AABBBBA". The substring "BBBB" has the
    longest repeating letters, which is 4.

--Inputs:
  -int[]: array of distinct integers 'candidates'
  -int: integer 'target'

--Output:
  -int[][]: unique combinations of candidates where the chosen numbers sum to 'target'

--Constraints:
  :: 1 <= s.length <= 105
  :: s consists of only uppercase English letters.
  :: 0 <= k <= s.length

--Reasoning: See comments below.

--Time complexity:

--Space complexity:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int characterReplacement(std::string s, int k) {
  const int N = s.size();
  std::vector<int> charFreq(26, 0); // array for mapping character frequency
  int l_ptr{0},                     // left pointer, expands the window size
      r_ptr{0},                     // right pointer, shrinks the window size
      res{0};

  for (; r_ptr < N; ++r_ptr) {
    char currCharacRight = s.at(r_ptr);   // current character being added to the window
    ++charFreq.at(currCharacRight - 'A'); // increment its frequency

    int currWindowSize = r_ptr - l_ptr + 1;                            // calculate current window size
    int maxFreq = *std::max_element(charFreq.begin(), charFreq.end()); // frequency of the element which appears the most

    // "currWindowSize - maxFreq = R": elements that need to be replaced to maximize the result
    if (currWindowSize - maxFreq > k) {    // if R>k: shrink the window to try to reduce the amount of replacements needed
      char currCharacLeft = s.at(l_ptr);   // current character being removed from the window
      --charFreq.at(currCharacLeft - 'A'); // decrement its frequency
      ++l_ptr;                             // shrink the window
    }

    res = std::max(res, r_ptr - l_ptr + 1);
  }

  return res;
}

int main() {
  std::string str{};
  int length{}, k{};

  str = "ABAB";
  k = 2;
  length = characterReplacement(str, k);
  std::cout << "String: " << str << "\n"
            << "Longest substr. containing the same letter after " << k
            << " replacements: " << length << "\n\n";

  str = "AABABBA";
  k = 1;
  length = characterReplacement(str, k);
  std::cout << "String: " << str << "\n"
            << "Longest substr. containing the same letter after " << k
            << " replacements: " << length << "\n\n";

  return 0;
}