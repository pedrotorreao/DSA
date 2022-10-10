/*********************************************************************************************/
/* Problem: Reverse Prefix of Word (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a 0-indexed string 'word' and a character 'ch', reverse the segment of word that starts at
  index 0 and ends at the index of the first occurrence of 'ch' (inclusive). If the character 'ch'
  does not exist in 'word', do nothing.
  For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts
  at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".

  Return the resulting string.

  > Example 1:
      Input: word = "abcdefd", ch = "d"
      Output: "dcbaefd"
      Explanation:
        The first occurrence of "d" is at index 3.
        Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".

  > Example 2:
      Input: word = "xyxzxe", ch = "z"
      Output: "zxyxxe"
      Explanation:
        The first and only occurrence of "z" is at index 3.
        Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".

  > Example 3:
      Input: word = "abcd", ch = "z"
      Output: "abcd"
      Explanation:
        "z" does not exist in word.
        You should not do any reverse operation, the resulting string is "abcd".

--Input:
  string: input string 'word'
  char: reversion character 'ch'

--Output:
  string: reversed string

--Reasoning: Two pointers approach.

--Constraints:
  :: 1 <= word.length <= 250
  :: word consists of lowercase English letters.
  :: ch is a lowercase English letter.

--Time complexity:
    O(N), for the worst case where there is no match for 'ch' in the string 'word', where N is
    the size of the input string.

--Space complexity:
    O(1), there is no additional space allocated dependent on the input string.

*******************************************************************************/

#include <iostream>
#include <string>

std::string reversePrefix(std::string word, char ch) {
  /*
      :: 1 <= word.length <= 250
      :: word consists of lowercase English letters.
      ::ch is a lowercase English letter.
  */

  int L = word.size();
  int i{0}, j{0};

  while (i < L) {
    char curr_char = word.at(i);

    if (curr_char == ch) {
      j = i;
      break;
    }
    ++i;
  }

  i = 0;

  while (i <= j) {
    char temp_char = word.at(j);

    word.at(j) = word.at(i);
    word.at(i) = temp_char;

    ++i;
    --j;
  }

  return word;
}

int main() {
  std::string word{""}, expected{""}, res{""};
  char ch{};

  word = "abcdefd";
  ch = 'd';
  expected = "dcbaefd";
  res = reversePrefix(word, ch);
  std::cout << "String \"" << word << "\" reversed at the first \'" << ch << "\' is: " << res
            << "\t\tExpected: \"" << expected << "\"" << (res == expected ? "\t\t--PASSED\n\n" : "\t\t--FAILED\n\n");

  word = "abchdefd";
  ch = 'd';
  expected = "dhcbaefd";
  res = reversePrefix(word, ch);
  std::cout << "String \"" << word << "\" reversed at the first \'" << ch << "\' is: " << res
            << "\t\tExpected: \"" << expected << "\"" << (res == expected ? "\t\t--PASSED\n\n" : "\t\t--FAILED\n\n");

  word = "abchdefd";
  ch = 'z';
  expected = "abchdefd";
  res = reversePrefix(word, ch);
  std::cout << "String \"" << word << "\" reversed at the first \'" << ch << "\' is: " << res
            << "\t\tExpected: \"" << expected << "\"" << (res == expected ? "\t\t--PASSED\n\n" : "\t\t--FAILED\n\n");

  return 0;
}