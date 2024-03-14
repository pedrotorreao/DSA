/* * * * * * * * * * * * * * * * * *
Problem: LC 409. Longest Palindrome

--Problem statement:
Given a string 's' which consists of lowercase or uppercase letters, return the
length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

  > Example 1:
    Input: s = "abccccdd"
    Output: 7
    Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

  > Example 2:
    Input: s = "a"
    Output: 1
    Explanation: The longest palindrome that can be built is "a", whose length is 1.

 --Constraints:
    :: 1 <= s.length <= 2000
    :: s consists of lowercase and/or uppercase English letters only.

--Inputs:
  - string 's'.

--Outputs:
  - int: length of the longest palindrome

--Reasoning: Use a hash-table.

--Time complexity:
    :: O(n), where n is length of the input string.

--Space complexity:
    :: O(26) ~ O(1).
* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  static int longestPalindrome(std::string s) {
    std::unordered_map<char, int> hm;

    // map character frequencies:
    for (auto &c : s)
      ++hm[c];

    // flag for indicating the presence of odd character frequency:
    bool oddFreqCharExists{false};
    int length = 0;
    for (auto it = hm.begin(); it != hm.end(); it++) {
      int charFreq = it->second;
      // a. if the character has an even frequency, all of its occurences
      // can be added to the resulting palindrome:
      if (charFreq % 2 == 0)
        length += charFreq;
      // b. otherwise, only add the largest number of occurences which is
      // even (charFreq - 1), since for the output to be a valid palindrome, it
      // can have at most 1 character which has an odd frequency (middle character):
      else {
        length += charFreq - 1;
        oddFreqCharExists = true;
      }
    }
    // if there characters with odd frequencies, add one of them to be the middle
    // character in the palindrome:
    return oddFreqCharExists ? length + 1 : length;
  }
};

int main() {
  std::string s{"abccccdd"};
  std::cout << "Length of the longest palindrome obtained from \"" << s << "\": " << Solution::longestPalindrome(s) << "\n";
}