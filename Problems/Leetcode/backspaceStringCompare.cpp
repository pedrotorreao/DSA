/* * * * * * * * * * * * * * * * * *
Problem: LC 844. Backspace String Compare

--Problem statement:
Given two strings s and t, return true if they are equal when both are typed into empty text
editors. '#' means a backspace character. Note that after backspacing an empty text, the text
will continue empty.

  Example 1:
    Input: s = "ab#c", t = "ad#c"
    Output: true
    Explanation: Both s and t become "ac".

  Example 2:
    Input: s = "ab##", t = "c#d#"
    Output: true
    Explanation: Both s and t become "".

  Example 3:
    Input: s = "a#c", t = "b"
    Output: false
    Explanation: s becomes "c" while t becomes "b".

--Constraints:
    :: 1 <= s.length, t.length <= 200
    :: s and t only contain lowercase letters and '#' characters.

--Inputs:
  - strings: two strings s and t.

--Outputs:
  - bool: value indicating whether the input strings are equal after the removal of the backspaces.

--Reasoning: Use strings to store the state of the strings after applying the backspaces.

--Time complexity:
    :: O(n + m), where n and m are the lengths of the input strings.

--Space complexity:
    :: O(n + m), due to the additional space needed for the copy strings.
* * * * * * * * * * * * * * * * * */
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  static bool backspaceCompare(std::string s, std::string t) {
    std::string s_new, t_new;

    // iterate over string 's':
    for (char &ch : s) {
      // if not a backspace, add current character to the result string:
      if (ch != '#')
        s_new += ch;
      // otherwise, if the string is not empty, pop the last element to apply
      // one backspace:
      else {
        if (!s_new.empty())
          s_new.pop_back();
      }
    }
    // iterate over string 't':
    for (char &ch : t) {
      // if not a backspace, add current character to the result string:
      if (ch != '#')
        t_new += ch;
      // otherwise, if the string is not empty, pop the last element to apply
      // one backspace:
      else {
        if (!t_new.empty())
          t_new.pop_back();
      }
    }

    if (s_new == t_new)
      return true;
    return false;
  }
};

int main() {
  std::cout << std::boolalpha;

  std::string s, t;

  s = "ab#c";
  t = "ad#c";
  std::cout << "-- strings  \"" << s << "\" and \"" << t
            << "\" are equal: " << Solution::backspaceCompare(s, t) << "\n";
}