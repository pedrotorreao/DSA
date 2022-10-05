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

--Reasoning: Sliding Window approach, see comments below.

--Time complexity:
    O(W+L), where W is the length of the string 's1' and L is the length of the
    string 's2'. There is an inner loop for the comparison between hashmaps with
    a time complexity of at most 0(26), which can be simpliied to ~O(1), so it does
    not affect the overall runtime of the algorithm.

--Space complexity:
    O(W+L), where W is the length of the string 's1' and L is the length of the
    string 's2'. This is the worst case, where the strings have unique characters, so
    the space allocated for their hashmaps is equal to the string lenghts.

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

  int start{0}, end{0};
  std::unordered_map<char, int> hm1, hm2;

  // count the frequency of the characters in string 's1':
  for (const auto &ch1 : s1)
    ++hm1[ch1];

  // go over the string 's2' count the frequencies of its characters:
  for (; end < L; ++end) {
    ++hm2[s2.at(end)];

    // if the length of the current window is less than the string 's1',
    // continue mapping the characters since it's not possible to have
    // a match yet:
    if (end - start + 1 < W) {
      continue;
    }

    // now that the we've matched the window size (end-start+1 == W),
    // check if both hashmaps hold the same data, i.e. same characters to frequencies
    // values. if they do, 'hm2' has an anagram/permutaion of 's1', return true:
    if (hm2 == hm1)
      return true;

    // otherwise, we need to move the window, so we decrease the frequency of the character
    // currently at 's2[start]', move the start of the window (++start) and the end (++end in
    // the for loop):
    if (!--hm2[s2.at(start)])
      hm2.erase(s2.at(start));

    ++start;
  }

  // if we've gotten out of the for loop, it means that no match was found, return false:
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