/***********************************************************************************/
/* Problem: Longest Common Subsequence - Divide & Conquer Approach           *******/
/***********************************************************************************/
/*
-- Problem Statement:
  Given a string str, find the length of its longest palindromic subsequence (LPS).
  A subsequence is a sequence that can be derived from another string by deleting
  some or no elements without changing the order of the remaining elements. A
  palindrome is a string that reads the same backwards as well as forward and can
  be of odd or even lenght.
-- Reasoning:
  We'll keep two indexes, i_start to initially point to the start of the string and 
  i_end to point to the end and we'll compare the characters at these positions. If they 
  match, we add 2 (since each index represent one character) to the result and move
  both indexes one position, i_start will be incremented and i_end will be decremented:
          lps_res1 = 2 + lcsHelper(str, i_start + 1, i_end - 1);
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

  if (!dp.at(i_start).at(i_end))
  {
    int lps_res1 = 0;

    // CASE 1: current characters match, advance both indices:
    if (str.at(i_start) == str.at(i_end))
    {
      dp.at(i_start).at(i_end) = 2 + lcsHelper(str, dp, i_start + 1, i_end - 1);
    }
    else
    {
      // CASE 2: current characters don't match, advance start index:
      int lps_res2 = lcsHelper(str, dp, i_start + 1, i_end);
      // CASE 3: current characters don't match, advance end index:
      int lps_res3 = lcsHelper(str, dp, i_start, i_end - 1);

      dp.at(i_start).at(i_end) = std::max(lps_res2, lps_res3);
    }
  }

  // RESULT: max value between all cases:
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
}

// ---- Driver code: ----:

int main()
{
  std::string str = "ELRMENMET";

  std::cout << "Longest Palindromic Subsequence length for " << str << ": " << lpsTD(str) << "\n";

  str = "AMEEWMEA";

  std::cout << "Longest Palindromic Subsequence length for " << str << ": " << lpsTD(str) << "\n";

  return 0;
}