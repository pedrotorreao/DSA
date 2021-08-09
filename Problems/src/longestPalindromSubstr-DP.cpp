/***********************************************************************************/
/* Problem: Longest Palindromic Substring - Dynamic Programming Approach     *******/
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
#include <vector>
#include <string>
#include <cmath>

// ---- Top Down Approach - Memoization ----:
int lcsHelper(std::string str, std::vector<std::vector<int>> &dp, int i_start, int i_end)
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

  if (!dp.at(i_start).at(i_end))
  {
    // CASE 1: current characters match, check characters in between:
    if (str.at(i_start) == str.at(i_end))
    {
      int characs_in_between = i_end - i_start - 1;

      if (characs_in_between == lcsHelper(str, dp, i_start + 1, i_end - 1))
      {
        lps_res1 = 2 + characs_in_between;
      }
    }

    // CASE 2: current characters don't match, advance start index:
    int lps_res2 = lcsHelper(str, dp, i_start + 1, i_end);
    // CASE 3: current characters don't match, advance end index:
    int lps_res3 = lcsHelper(str, dp, i_start, i_end - 1);

    dp.at(i_start).at(i_end) = std::max(lps_res1, std::max(lps_res2, lps_res3));
  }
  // RESULT:
  return dp.at(i_start).at(i_end);
}

int lpsTD(std::string s)
{
  std::vector<std::vector<int>> memo(s.size(), std::vector<int>(s.size()));

  return lcsHelper(s, memo, 0, s.size() - 1);
}

// ---- Bottom Up Approach - Tabulation ----:
int lpsBU(std::string s)
{
  std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size()));

  for (int col = 0; col < s.size(); col++)
  {
    for (int row = (s.size() - 1); row >= 0; row--)
    {
      // BASE CASE: if the indices cross each other, there are no more
      // characters to check, return 0:
      // std::cout << row << "--" << col << "\n";
      if (row > col)
      {
        dp.at(row).at(col) = 0;
      }
      // BASE CASE: if the indices are equal, then this is a palindrome
      // of 1 character, return 1:
      else if (row == col)
      {
        dp.at(row).at(col) = 1;
      }
      else
      {
        // CASE 1: current characters match, advance both indices:
        if (s.at(row) == s.at(col))
        {
          int characs_in_between = col - row - 1;
          int length_in_between = (characs_in_between == dp.at(row + 1).at(col - 1)) ? (2 + dp.at(row + 1).at(col - 1)) : 0;

          dp.at(row).at(col) = std::max(length_in_between, std::max(dp.at(row).at(col - 1), dp.at(row + 1).at(col)));
        }
        // CASE 2: current characters don't match, advance each index separately and get the max value betrween the two:
        else
        {
          dp.at(row).at(col) = std::max(dp.at(row).at(col - 1), dp.at(row + 1).at(col));
        }
      }
    }
  }
  return dp.at(0).at(s.size() - 1);
}

// ---- Driver code: ----:
int main()
{
  std::string str = "ABCYRCFBTUA";

  std::cout << "Longest Palindromic Substring length for " << str << ":\n"
            << "\tTop Down: " << lpsTD(str) << "\n"
            << "\tBottom Up: " << lpsBU(str) << "\n"; //1

  str = "ABCCBUA";
  std::cout << "Longest Palindromic Substring length for " << str << ":\n"
            << "\tTop Down: " << lpsTD(str) << "\n"
            << "\tBottom Up: " << lpsBU(str) << "\n"; //4

  str = "MQADASM";
  std::cout << "Longest Palindromic Substring length for " << str << ":\n"
            << "\tTop Down: " << lpsTD(str) << "\n"
            << "\tBottom Up: " << lpsBU(str) << "\n"; //3

  return 0;
}