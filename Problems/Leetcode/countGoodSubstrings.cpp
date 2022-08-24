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
  const int windowSize = 3;        // fixed window/substring size
  const int stringSize = s.size(); // get string size

  std::unordered_map<char, int> hm; // hashmap to map characters to their frequencies
  int numOfGoodStrings{0};          // variable to be returned

  if (stringSize < windowSize) // string is smaller than the substring size, result is zero
    return 0;

  for (int i{0}; i < windowSize; ++i) // setup window for the first k-sized substring
    ++hm[s.at(i)];                    // count the frequency each character appears

  if (hm.size() == 3)   // if all characters were unique, k elements will have been added to the hashmap
    ++numOfGoodStrings; // add 1 to the result to account for the first good substring

  // Iterate over the remaining elements while sliding the window. Since the window size is fixed,
  // at each step we need to remove the previous left window border, i.e. character s[i-k], and add
  // the new right window border, i.e. character s[i].
  for (int i{windowSize}; i < stringSize; ++i) {
    char prevLeftBorderChar = s.at(i - windowSize); // previous left window border
    char newRightBorderChar = s.at(i);              // new right window border

    // Decrement the frequency for the removed character, i.e. s.at(i - windowSize).
    // If it reaches zero, this character is not part of the current window/substring
    // and we must remove it from the hashmap:
    if (!--hm[prevLeftBorderChar])
      hm.erase(prevLeftBorderChar);

    // Add/increment frequency of the newly added character, i.e. element s[i]:
    ++hm[newRightBorderChar];

    // If all characters in the current window/substring are unique, k elements
    // will have been added to the hashmap, so add 1 to the result to account for
    // another good substring:
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