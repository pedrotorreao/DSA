/*********************************************************************************************/
/* Problem: LC 1358. Number of Substrings Containing All Three Characters ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a string 's' consisting only of characters 'a', 'b' and 'c'. Return the number of substrings
  containing at least one occurrence of all these characters 'a', 'b' and 'c'.

  > Example 1:
    Input: s = "abcabc"
    Output: 10
    Explanation: The substrings containing at least one occurrence of the characters a', 'b' and
    'c' are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

  > Example 2:
    Input: s = "aaacb"
    Output: 3
    Explanation: The substrings containing at least one occurrence of the characters a', 'b' and
    'c' are "aaacb", "aacb" and "acb".

  > Example 3:
    Input: s = "abc"
    Output: 1

--Inputs:
  string: string 's' consisting only of characters 'a', 'b' and 'c'

--Output:
  int: number of substrings containing at least one occurrence of all 3 characters.

--Constraints:
    :: 3 <= s.length <= 5 x 10^4
    :: s only consists of a, b or c characters.

*/

#include <iostream>
#include <string>
#include <unordered_map>

/*
    Approach #1 - Brute Force:
        --Reasoning: In this approach, we try out all the possible substrings
        --Time complexity: O(N^2), since for each iteration of the outer loop (i), we iterate N-i
          times in the inner loop.
        --Space complexity:
          O(1), since we allocate space for at most 3 characters and their frequencies, which is not
          dependent on the input size, i.e. the string length.
*/
int numberOfSubstrings_1(std::string s) {
  if (s.size() < 3)
    return 0;

  const int L = s.size();
  std::unordered_map<char, int> hm;
  int left_border{0}, num_of_substr{0};

  for (int left_border{0}; left_border < L; ++left_border) {
    for (int right_border{left_border}; right_border < L; ++right_border) {
      ++hm[s.at(right_border)];
      if (hm.size() == 3)
        ++num_of_substr;
    }
    hm.clear();
  }

  return num_of_substr;
}

/*
    Approach #2 - Sliding Window I:
        --Reasoning:
          By using a sliding window approach, when the condition is met (all three characters are present),
          we move the left border (left++). This way, after the while loop is finished, left-1 would be the
          leftmost index to satisfy the condition, left doesn't satisfy it (breaks the while loop).
          Also, [left-1, right] would be the minimum window size to satisfy the requirements. Because it is
          minimal, we can choose nums[0], nums[1] ... nums[left-1] as the left side of the window, and it
          would still satisfies the condition. Therefore, we can add 'left' to the result, to account for
          all the substrings from 0 to left-1.
        --Time complexity: O(N), where N is the string size.
        --Space complexity:
          O(1), since we allocate space for at most 3 characters and their frequencies, which is not
          dependent on the input size, i.e. the string length.
*/
int numberOfSubstrings_2(std::string s) {
  if (s.size() < 3)
    return 0;

  std::unordered_map<char, int> char_freq;

  const int L = s.size(), W = 3;
  int left{0}, right{0}, res{0};

  for (; right < L; ++right) {
    ++char_freq[s.at(right)];

    while (char_freq.size() == W) {
      if (!--char_freq[s.at(left)])
        char_freq.erase(s.at(left));
      ++left;
    }
    // The range [left-1 .. right] represents the minimum length substring ending at 'right' which
    // contains all three characters. This substring could be extended left/towards the beginning
    // until left=0 and it would still be a valid substring, i.e. meeting the constraint,
    // which is a total of length([0..left-1]) = left substrings ending at 'right'.
    res += left;
  }

  return res;
}

/*
    Approach #3 - Sliding Window II:
        --Reasoning: Basically the same idea as #2, but the calculation could be easier to grasp this way.
        --Time complexity: O(N), where N is the string size.
        --Space complexity:
          O(1), since we allocate space for at most 3 characters and their frequencies, which is not
          dependent on the input size, i.e. the string length.
*/
int numberOfSubstrings_3(std::string s) {
  if (s.size() < 3)
    return 0;

  std::unordered_map<char, int> char_freq;

  const int L = s.size(), W = 3;
  int left{0}, right{0}, res{0};

  for (; right < L; ++right) {
    ++char_freq[s.at(right)];

    while (char_freq.size() == W) {
      res += L - right;
      if (!--char_freq[s.at(left)])
        char_freq.erase(s.at(left));
      ++left;
    }
  }

  return res;
}

int main() {
  std::string s{"abcabc"};
  int expec{10};
  int res = numberOfSubstrings_3(s);
  std::cout << "Number of substrings: " << res
            << " \t--Expected: " << expec
            << (res == expec ? "\t--[PASSED]" : "\t--[FAILED]")
            << "\n";

  s = "aaacb";
  expec = 3;
  res = numberOfSubstrings_3(s);
  std::cout << "Number of substrings: " << res
            << " \t--Expected: " << expec
            << (res == expec ? "\t--[PASSED]" : "\t--[FAILED]")
            << "\n";

  return 0;
}