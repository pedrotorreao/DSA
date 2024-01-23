/* * * * * * * * * * * * * * * * * *
Problem: LC 1047. Remove All Adjacent Duplicates In a String

--Problem statement:
You are given a string s consisting of lowercase English letters. A duplicate removal
consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be
proven that the answer is unique.

  > Example 1:
      Input: s = "abbaca"
      Output: "ca"
      Explanation:
        For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal,
        and this is the only possible move.  The result of this move is that the string is "aaca",
        of which only "aa" is possible, so the final string is "ca".

  > Example 2:
      Input: s = "azxxzy"
      Output: "ay"

--Constraints:
    :: 1 <= s.length <= 10^5
    :: s consists of lowercase English letters.

--Inputs:
  - string s consisting of lowercase English letters.

--Outputs:
  - string after all duplicate removals have been made.

--Reasoning: Monotonic Stack approach. See comments below.

--Time complexity:
    :: O(n), where n is the length of the input string.

--Space complexity:
    :: O(n), where n is the length of the input string, for the worst case in which we have no adjacent
    duplicates in the input string and all the characters are stored in the stack.

* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  static std::string removeDuplicates(std::string s) {
    // stack for storing the string characters:
    std::stack<char> st;
    // iterate over the input string and process each character from the end so the
    // characters will be pushed onto the stack in the correct order:
    for (int i = s.size() - 1; i >= 0; i--) {
      // current character:
      char c = s.at(i);
      // if the stack is not empty and the current character is equal to the character at
      // the top of the stack, it means that we have adjacent duplicates, pop the top of
      // the stack and skip the current character:
      if (!st.empty() && st.top() == c) {
        st.pop();
        continue;
      }
      // otherwise, add the current character to the stack:
      st.push(c);
    }

    // clear the input string and build the result string from the characters remaining on the stack:
    s = "";
    while (!st.empty()) {
      s.push_back(st.top());
      st.pop();
    }
    return s;
  }
};

int main() {
  std::string s = "", res = "";

  s = "abbaca";
  res = Solution::removeDuplicates(s);
  std::cout << "The result of removing the adjacent duplicates of \"" << s << "\" is: \"" << res << "\"\n";

  s = "azxxzy";
  res = Solution::removeDuplicates(s);
  std::cout << "The result of removing the adjacent duplicates of \"" << s << "\" is: \"" << res << "\"\n";
}
