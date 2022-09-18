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

--Space complexity:

*/

#include <iostream>
#include <string>
#include <unordered_map>

std::string longestNiceSubstring(std::string s) {
  if (s.size() <= 1)
    return "";

  const int S = s.size();
  std::unordered_map<char, int> charFreq;
  std::string goodStr{}, temp{};
  int l{0}, r{0}, maxLength{0};

  for (; r < S; ++r)
    ++charFreq[s.at(r)];

  for (r = 0; r < S; ++r) {
    char lower = tolower(s.at(r));
    char upper = toupper(s.at(r));

    if (!(charFreq[lower] && charFreq[upper])) {
      if (!--charFreq[s.at(r)])
        charFreq.erase(s.at(r));
      l = r + 1;

      // temp = s.substr(l,r-l); //?
    }
    // else {
    //     temp.push_back(s.at(r)); //?
    // }

    if (r - l > goodStr.size())
      goodStr = s.substr(l, r - l);
    else
      goodStr.push_back(s.at(r));

    // goodStr = (temp.size() > goodStr.size()) ? temp : goodStr;

    // if(maxLength < (r-l)){

    //     goodStr = s.substr(l,r-l+1);
    //     std::cout << "Xirombs\n";
    // }
    // else{
    //     goodStr.push_back(s.at(r));
    // }

    // maxLength = std::max(maxLength, r-l);
  }

  return goodStr;
}

int main() {
  std::cout << longestNiceSubstring("YazaAay") << "\n";
  std::cout << longestNiceSubstring("Bb") << "\n";
  std::cout << longestNiceSubstring("c") << "\n";
  std::cout << longestNiceSubstring("XabcdefFEDCBAy") << "\n";
  std::cout << longestNiceSubstring("abcdefFEDCBAyyyyx") << "\n";

  return 0;
}