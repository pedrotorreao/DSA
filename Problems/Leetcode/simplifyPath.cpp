/***
Problem: LC 71. Simplify Path
(https://leetcode.com/problems/simplify-path/description/)

--Problem statement:
  You are given an absolute path for a Unix-style file system, which always begins with a slash '/'.
  Your task is to transform this absolute path into its simplified canonical path. The rules of a Unix-style
  file system are as follows:
      - A single period '.' represents the current directory.
      - A double period '..' represents the previous/parent directory.
      - Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
      - Any sequence of periods that does not match the rules above should be treated as a valid directory
      or file name. For example, '...' and '....' are valid directory or file names.

  The simplified canonical path should follow these rules:
      - The path must start with a single slash '/'.
      - Directories within the path must be separated by exactly one slash '/'.
      - The path must not end with a slash '/', unless it is the root directory.
      - The path must not have any single or double periods ('.' and '..') used to denote current or parent
      directories.
  Return the simplified canonical path.

  > Example 1:
      Input: path = "/home/"
      Output: "/home"
      Explanation: The trailing slash should be removed.

  > Example 2:
      Input: path = "/home//foo/"
      Output: "/home/foo"
      Explanation: Multiple consecutive slashes are replaced by a single one.

  > Example 3:
      Input: path = "/home/user/Documents/../Pictures"
      Output: "/home/user/Pictures"
      Explanation: A double period ".." refers to the directory up a level (the parent directory).

  > Example 4:
      Input: path = "/../"
      Output: "/"
      Explanation: Going one level up from the root directory is not possible.

  > Example 5:
      Input: path = "/.../a/../b/c/../d/./"
      Output: "/.../b/d"
      Explanation: "..." is a valid name for a directory in this problem.

--Inputs:
  string: absolute path for a Unix-style file system.

--Output:
  string: simplified path.

--Constraints:
  > 1 <= path.length <= 3000
  > 'path' consists of English letters, digits, period '.', slash '/' or '_'.
  > 'path' is a valid absolute Unix 'path'.

--Reasoning:
  Use a stack for keeping track of the directories. Then, split the input path into components by the "/" character,
  and process each component. If a component is:
    a.) "..": go to the previous directory by popping the top of the stack.
    b.) "." or an empty string, "": do nothing.
    c.) otherwise: push the component into the stack as a new directory.
  See more comments in the code below.

--Time complexity:
    > splitting the input path string: O(N), where N is the length of the string.
    > processing: O(N), also, since each component is processes at most once.
    > building the output string: O(N). It's just a matter of going over the stack and appending the components.

        TC: O(N) + O(N) + O(N) = O(3N) ~ O(N).

--Space complexity: O(N), due to the additional space used by the stack.

*/

#include <bits/stdc++.h>

class Solution {
public:
  static std::string simplifyPath(std::string path) {
    // Stack for storing the directory names:
    std::stack<std::string> st;

    // Use std::istringstream to split the input path string using '/'
    // as the delimiter:
    std::istringstream iss(path);
    std::string currPath;
    while (std::getline(iss, currPath, '/')) {
      if (currPath == "..") {
        // If the component is '..', go up one directory, i.e. if the stack
        // is not empty, pop the last component from the stack:
        if (!st.empty()) {
          st.pop();
        }
      } else if (!currPath.empty() && currPath != ".") {
        // If the component is not empty and not '.', push it onto the stack:
        st.push(currPath);
      }
    }

    // Result string:
    std::string result = "";

    // Build the simplified path by popping components from the stack:
    while (!st.empty()) {
      // Insert '/' before each component to ensure correct path format:
      result = "/" + st.top() + result;
      st.pop();
    }

    // If the result is empty, return '/', otherwise return the simplified path
    return result.empty() ? "/" : result;
  }
};

int main() {
  std::string str = "", expected = "", res = "";

  str = "/a//b////c/d//././/..";
  expected = "/a/b/c";
  res = Solution::simplifyPath(str);

  std::cout << "Input string: \"" << str << "\""
            << "\nExpected: \"" << expected << "\""
            << "\nResult: \"" << res << "\"" << "\n\n";

  str = "/../";
  expected = "/";
  res = Solution::simplifyPath(str);

  std::cout << "Input string: \"" << str << "\""
            << "\nExpected: \"" << expected << "\""
            << "\nResult: \"" << res << "\"" << "\n\n";

  str = "/home//foo/";
  expected = "/home/foo";
  res = Solution::simplifyPath(str);

  std::cout << "Input string: \"" << str << "\""
            << "\nExpected: \"" << expected << "\""
            << "\nResult: \"" << res << "\"" << "\n\n";

  return 0;
}