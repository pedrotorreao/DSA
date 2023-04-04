/*********************************************************************************************/
/* Problem: 345. Reverse vowels of a string ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a string s, reverse only all the vowels in the string and return it. The vowels are
  'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

  > Example 1:
    Input: s = "hello"
    Output: "holle"

  > Example 2:
    Input: s = "leetcode"
    Output: "leotcede"

 --Inputs:
  -string: string s

--Output:
  -string: modified string s with its vowels reversed.

--Constraints:
  :: 1 <= s.length <= 3 * 105
  :: s consist of printable ASCII characters.
*/

#include <cctype>
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  /*  Approach #1
    --Reasoning:
      This approach makes use of a stack of pairs to store the vowels and its positions in the
      input string. We perform two traversals, the first one adds the {i,s[i]} pairs to the
      stack, and the second swaps the vowels by getting the vowels at the top of the stack.

    --Time complexity: O(N), where N is the size of the input string.

    --Space complexity: O(N), for the worst case in which the input string consists of only vowels.
  */
  std::string reverseVowels_1(std::string s) {
    std::stack<std::pair<int, char>> vowelsPositions;

    for (int i{0}; i < s.size(); ++i) {
      char currCharac = tolower(s.at(i));

      if (isVowel(currCharac))
        vowelsPositions.push({i, s.at(i)});
    }

    for (int i{0}; i < s.size(); ++i) {
      char currCharac = tolower(s.at(i));

      if (isVowel(currCharac)) {
        s.at(i) = vowelsPositions.top().second;
        vowelsPositions.pop();
      }
    }

    return s;
  }

  /*  Approach #2
  --Reasoning:
    This solution is based on the two pointers approach in which we keep two pointers, l and r,
    which traverse the input string from opposite ends and swaps the vowels as they are found
    in a single loop.

  --Time complexity: O(N), where N is the size of the input string.

  --Space complexity: O(1), no input dependent space is allocated.
*/
  std::string reverseVowels_2(std::string s) {
    std::string vowels = "aeiouAEIOU";

    int l = 0, r = s.size() - 1;

    while (l < r) {
      while (l < r && vowels.find(s.at(l)) == std::string::npos)
        ++l;

      while (l < r && vowels.find(s.at(r)) == std::string::npos)
        --r;

      std::swap(s.at(l++), s.at(r--));
    }

    return s;
  }

  // helpers:
  bool isVowel(char &ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
  }
};

int main() {
  std::string str, rev, res;

  Solution sol;

  str = "tutorial";
  rev = "tatiroul";
  res = sol.reverseVowels_1(str);
  std::cout << "1: String \"" << str << "\" with its vowels reversed is \"" << res << "\"\t" << (res == res ? "--PASSED" : "--FAILED") << "\n";
  res = sol.reverseVowels_2(str);
  std::cout << "2: String \"" << str << "\" with its vowels reversed is \"" << res << "\"\t" << (res == res ? "--PASSED" : "--FAILED") << "\n\n";

  str = "dangEroUs";
  rev = "dUngorEas";
  res = sol.reverseVowels_1(str);
  std::cout << "1: String \"" << str << "\" with its vowels reversed is \"" << res << "\"\t" << (res == res ? "--PASSED" : "--FAILED") << "\n";
  res = sol.reverseVowels_2(str);
  std::cout << "2: String \"" << str << "\" with its vowels reversed is \"" << res << "\"\t" << (res == res ? "--PASSED" : "--FAILED") << "\n\n";

  return 0;
}