/* * * * * * * * * * * * * * * * * *
Problem: LC 58. Length of Last Word

--Problem statement:
Given a string s consisting of words and spaces, return the length of the
last word in the string. A word is a maximal substring consisting of non-space
characters only.

  > Example 1:
      Input: s = "Hello World"
      Output: 5
      Explanation: The last word is "World" with length 5.

  > Example 2:
      Input: s = "   fly me   to   the moon  "
      Output: 4
      Explanation: The last word is "moon" with length 4.

  > Example 3:
      Input: s = "luffy is still joyboy"
      Output: 6
      Explanation: The last word is "joyboy" with length 6.

--Constraints:
    :: 1 <= s.length <= 104
    :: s consists of only English letters and spaces ' '.
    :: There will be at least one word in s.

--Inputs:
  - string

--Outputs:
  - int: length of the last word.

--Reasoning: Simple iterative approach.

--Time complexity:
    :: O(n), in the worst case that the input string consists only of spaces.

--Space complexity:
    :: O(1), since no additional input-dependent space is allocated.
* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>

class Solution {
public:
  static int lengthOfLastWord(std::string s) {
    std::string str = "";
    bool foundFirstWord = false;

    for (int i = s.size() - 1; i >= 0; i--) {
      if (s.at(i) != ' ') {
        str.push_back(s.at(i));
        foundFirstWord = true;
      } else if (foundFirstWord) {
        break;
      }
    }

    return str.size();
  }
};

int main() {
  std::string s{""};

  s = "Hello World";
  std::cout << "The length of the string \"" << s << "\" is: " << Solution::lengthOfLastWord(s) << "\n\n";

  s = "   fly me   to   the moon  ";
  std::cout << "The length of the string \"" << s << "\" is: " << Solution::lengthOfLastWord(s) << "\n\n";

  s = "luffy is still joyboy";
  std::cout << "The length of the string \"" << s << "\" is: " << Solution::lengthOfLastWord(s) << "\n\n";
}
