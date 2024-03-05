/* * * * * * * * * * * * * * * * * *
Problem: LC 402. Remove K Digits

--Problem statement:
Given string 'num' representing a non-negative integer 'num', and an integer 'k', return the
smallest possible integer after removing 'k' digits from 'num'.

  Example 1:
    Input: num = "1432219", k = 3
    Output: "1219"
    Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

  Example 2:
    Input: num = "10200", k = 1
    Output: "200"
    Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

  Example 3:
    Input: num = "10", k = 2
    Output: "0"
    Explanation: Remove all the digits from the number and it is left with nothing which is 0.

 --Constraints:
    :: 1 <= k <= num.length <= 10^5
    :: num consists of only digits.
    :: num does not have any leading zeros except for the zero itself.

--Inputs:
  - string 'num' representing a non-negative integer.
  - integer 'k'

--Outputs:
  - smallest possible integer after removing 'k' digits from 'num'.

--Reasoning: Use a monotonic stack approach. See comments below.

--Time complexity:
    :: O(n), where n is lengths of the input string, num.

--Space complexity:
    :: O(n), due to the additional space needed for the stack.
* * * * * * * * * * * * * * * * * */
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  static std::string removeKdigits(std::string num, int k) {
    std::stack<char> st;

    for (auto &n : num) {
      while (k > 0 && !st.empty() && st.top() > n) {
        st.pop();
        --k;
      }
      st.push(n);

      // remove leading zeros:
      if (st.size() == 1 && n == '0')
        st.pop();
    }

    // truncate to make sure we remove all k characters:
    for (int i{0}; i < k && !st.empty(); ++i) {
      st.pop();
    }

    std::string s = ""; // result string
    // populate the result string with the characters left in the stack:
    while (!st.empty()) {
      s.push_back(st.top());
      st.pop();
    }

    std::reverse(s.begin(), s.end());

    return s.empty() ? "0" : s;
  }
};

int main() {
  std::string str{""};
  int k{0};

  str = "1432219";
  k = 3;
  std::cout << "Smallest possible integer after removing " << k << " digits from " << str << ": " << Solution::removeKdigits(str, k) << "\n";

  str = "10200";
  k = 1;
  std::cout << "Smallest possible integer after removing " << k << " digits from " << str << ": " << Solution::removeKdigits(str, k) << "\n";
}