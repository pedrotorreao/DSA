/******************************************************************************
Problem: Find First Palindromic String in the Array
*******************************************************************************/
/*
--Problem statement:
  Given an array of strings words, return the first palindromic string in the array.
  If there is no such string, return an empty string "".
  A string is palindromic if it reads the same forward and backward.

  > Example 1:
      Input: words = ["abc","car","ada","racecar","cool"]
      Output: "ada"
      Explanation:
        The first string that is palindromic is "ada".
        Note that "racecar" is also palindromic, but it is not the first.

  > Example 2:
      Input: words = ["notapalindrome","racecar"]
      Output: "racecar"
      Explanation:
        The first and only string that is palindromic is "racecar".

  > Example 3:
      Input: words = ["def","ghi"]
      Output: ""
      Explanation:
        There are no palindromic strings, so the empty string is returned.

--Inputs:
  string[]: array of strings

--Output:
  string: first palindromic string or empty string.

--Constraints:
    :: 1 <= words.length <= 100
    :: 1 <= words[i].length <= 100
    :: words[i] consists only of lowercase English letters.

--Reasoning: Two pointers approach.

--Time complexity:
    O(W * L/2) ~ O(W*L), where W is the length of the input array and L is the length
    of the largest string in 'words'.

--Space complexity:
    O(1), no input dependet space is allocated.

*/

#include <iostream>
#include <string>
#include <vector>

std::string firstPalindrome(std::vector<std::string> &words) {
  if (words.size() == 0)
    return "";

  const int W = words.size();

  for (int w{0}; w < W; ++w) {
    std::string cur_word = words.at(w);
    int L = cur_word.size();
    // a 1 character string is a palindrome itself:
    if (L == 1)
      return cur_word;

    int i{0}, j{L - 1};

    while (i < j) {
      // in case characters don't match, it's not a palindrome, so no need to
      // keep checking:
      if (cur_word.at(i) != cur_word.at(j))
        break;

      ++i;
      --j;

      // in case we reached the middle of the string withou mismatch, the current
      // string is a palindrome:
      if (i == j || i > j)
        return cur_word;
    }
  }

  return "";
}

int main() {
  std::vector<std::string> words{"abc", "car", "ada", "racecar", "cool"};
  std::cout << "palindrome: " << firstPalindrome(words) << "\n\n";

  words = {"notapalindrome", "racecar"};
  std::cout << "palindrome: " << firstPalindrome(words) << "\n\n";

  words = {"xngla", "e", "itrn", "y", "s", "pfp", "rfd"};
  std::cout << "palindrome: " << firstPalindrome(words) << "\n\n";

  return 0;
}