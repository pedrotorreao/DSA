/***********************************************************************************/
/* Problem: Longest Palindromic Substring - Divide & Conquer Approach           *******/
/***********************************************************************************/
/*
-- Problem Statement:
  Given a string str, find the length of its longest palindromic substring (LPS). A
  palindrome is a string that reads the same backwards as well as forward and can
  be of odd or even lenght. A subsequence is a sequence that can be derived from 
  another string by >deleting< some or no elements without changing the order of the
  remaining elements.  In a substring these elements have to be contiguous, so it is
  not possible to remove elements in order to form the palindrome.
-- Reasoning:
  We'll keep two indexes, i_start to initially point to the start of the string and 
  i_end to point to the end and we'll compare the characters at these positions. If they 
  match, since we cannot modify the string, we need to assure that the characters between
  i_start and i_end also form a palindrome so we move the indexes and perform a recursive 
  call for these characters in between. This result should match the amount of characters
  between i_start and i_end if they do, we add 2 (since each index represent one 
  character) to this amount and we're done:
          if (characs_in_between == lcsHelper(str, i_start + 1, i_end - 1)) lps_res1 = 2 + characs_in_between;
  If the characters differ, we need to individually check each case, moving only the 
  i_start index and moving only the i_end index.
          lps_res2 = lcsHelper(str, i_start + 1, i_end);
          lps_res3 = lcsHelper(str, i_start, i_end - 1);
  The result will be the max value between lps1, lps2 and lps3.
*/
#include <iostream>
#include <string>
#include <cmath>

int lcsHelper(std::string str, int i_start, int i_end)
{
  // BASE CASE: if the indices cross each other, there are no more
  // characters to check, return 0:
  if (i_start > i_end)
  {
    return 0;
  }

  // BASE CASE: if the indices are equal, then this is a palindrome
  // of 1 character, return 1:
  if (i_start == i_end)
  {
    return 1;
  }

  int lps_res1 = 0;

  // CASE 1: current characters match, check characters in between:
  if (str.at(i_start) == str.at(i_end))
  {
    int characs_in_between = i_end - i_start - 1;

    if (characs_in_between == lcsHelper(str, i_start + 1, i_end - 1))
    {
      lps_res1 = 2 + characs_in_between;
      return lps_res1;
    }
  }

  // CASE 2: current characters don't match, advance start index:
  int lps_res2 = lcsHelper(str, i_start + 1, i_end);
  // CASE 3: current characters don't match, advance end index:
  int lps_res3 = lcsHelper(str, i_start, i_end - 1);

  // RESULT: max value between all cases:
  return std::max(lps_res1, std::max(lps_res2, lps_res3));
}

int lps(std::string s)
{
  return lcsHelper(s, 0, s.size() - 1);
}

int main()
{
  std::string str = "ABCYRCFBTUA";

  std::cout << "Longest Palindromic Substring length for " << str << ": " << lps(str) << "\n";

  str = "ABCCBUA";

  std::cout << "Longest Palindromic Substring length for " << str << ": " << lps(str) << "\n";

  str = "MQADASM";
  std::cout << "Longest Palindromic Substring length for " << str << ": " << lps(str) << "\n";

  return 0;
}