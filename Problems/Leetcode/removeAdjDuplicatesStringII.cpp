/* * * * * * * * * * * * * * * * * *
Problem: LC 1209. Remove All Adjacent Duplicates In a String II

--Problem statement:
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent
and equal letters from s and removing them, causing the left and the right side of the deleted
substring to concatenate together. We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that
the answer is unique.

  > Example 1:
      Input: s = "abcd", k = 2
      Output: "abcd"
      Explanation: There's nothing to delete.

  > Example 2:
      Input: s = "deeedbbcccbdaa", k = 3
      Output: "aa"
      Explanation:
        * First delete "eee" and "ccc", get "ddbbbdaa"
        * Then delete "bbb", get "dddaa"
        * Finally delete "ddd", get "aa"

  > Example 3:
      Input: s = "pbbcggttciiippooaais", k = 2
      Output: "ps"

--Constraints:
    :: 1 <= s.length <= 10^5
    :: 2 <= k <= 10^4
    :: s only contains lowercase English letters.

--Inputs:
  - string s consisting of lowercase English letters.
  - int k consisting of the number of duplicate removals that should be made.

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
#include <utility>

class Solution {
public:
  static std::string removeDuplicatesII(std::string s, int k) {
    if (k == 1) // all character should be removed
      return "";
    if (k > s.size()) // no group of duplicates of size k
      return s;

    // stack for storing the string characters and their counts:
    std::stack<std::pair<char, int>> st_p;
    // iterate over the input string and process each character from the end so the
    // characters will be pushed onto the stack in the correct order:
    for (int i = s.size() - 1; i >= 0; i--) {
      // current character:
      char c = s.at(i);
      // 1.a: if the stack is not empty and the current character is equal to the character at
      // the top of the stack, increment the count of the top character:
      if (!st_p.empty() && st_p.top().first == c) {
        st_p.top().second += 1;
        // if the count of the top character on the stack is k, we have a group of duplicates which satisfy
        // the condition, so pop the top character from the stack:
        if (st_p.top().second == k) {
          st_p.pop();
        }
        continue;
      }
      // 1.b: otherwise, add the current character with a count of 1 to the stack:
      st_p.push(std::make_pair(c, 1));
    }

    s = "";
    // build the result string from the characters remaining on the stack and their counts:
    while (!st_p.empty()) {
      s.append(st_p.top().second, st_p.top().first);
      st_p.pop();
    }
    return s;
  }
};

int main() {
  std::string s = "", res = "";
  int k = 0;

  s = "abcd";
  k = 2;
  res = Solution::removeDuplicatesII(s, k);
  std::cout << "The result of removing " << k << " adjacent duplicates from \"" << s << "\" is: \"" << res << "\"\n";

  s = "deeedbbcccbdaa";
  k = 3;
  res = Solution::removeDuplicatesII(s, k);
  std::cout << "The result of removing " << k << " adjacent duplicates from \"" << s << "\" is: \"" << res << "\"\n";

  s = "pbbcggttciiippooaais";
  k = 2;
  res = Solution::removeDuplicatesII(s, k);
  std::cout << "The result of removing " << k << " adjacent duplicates from \"" << s << "\" is: \"" << res << "\"\n";
}
