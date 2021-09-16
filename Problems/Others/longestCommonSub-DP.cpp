/***********************************************************************************/
/* Problem: Longest Common Subsequence - Dynamic Programming Approach           *******/
/***********************************************************************************/
/*
Problem statement:
  Given two strings s1 and s2, find the length of the longest subsequence which is
  common to both strings. A subsequence is a sequence that can be derived from another
  sequence by deleting some of the elements as long as the order of the remaining
  elements is not changed.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// ---- Top Down Approach - Memoization ----:

int lcsHelper(std::string str1, std::string str2, std::vector<std::vector<int>> &dp, int i1, int i2)
{
  // base case:
  if (i1 == str1.size() || i2 == str2.size())
  {
    return 0;
  }

  if (dp.at(i1).at(i2) == -1)
  {
    int common3 = 0;

    // current characters match, advance in both strings:
    if (str1.at(i1) == str2.at(i2))
    {
      common3 = 1 + lcsHelper(str1, str2, dp, i1 + 1, i2 + 1);
    }
    // current characters differ, advance in second strings:
    int common1 = lcsHelper(str1, str2, dp, i1, i2 + 1);
    // current characters differ, advance in first strings:
    int common2 = lcsHelper(str1, str2, dp, i1 + 1, i2);

    dp.at(i1).at(i2) = std::max(common1, std::max(common2, common3));
  }

  return dp.at(i1).at(i2);
}

int lcsTD(std::string str1, std::string str2, int i1, int i2)
{
  std::vector<std::vector<int>> memo(str1.size() + 1, std::vector<int>(str2.size() + 1, -1));

  return lcsHelper(str1, str2, memo, i1, i2);
}

// ---- Bottom Up Approach - Tabulation ----:
int lcsBU(std::string str1, std::string str2)
{
  std::vector<std::vector<int>> dp(str1.size() + 1, std::vector<int>(str2.size() + 1));

  for (auto i1{str1.size()}; i1 > 0; i1--)
  {
    for (auto i2{str2.size()}; i2 > 0; i2--)
    {
      if (str1.at(i1 - 1) == str2.at(i2 - 1))
      {
        dp.at(i1 - 1).at(i2 - 1) = std::max(1 + dp.at(i1).at(i2), std::max(dp.at(i1 - 1).at(i2), dp.at(i1).at(i2 - 1)));
      }
      else
      {
        dp.at(i1 - 1).at(i2 - 1) = std::max(dp.at(i1 - 1).at(i2), dp.at(i1).at(i2 - 1));
      }
    }
  }

  return dp.at(0).at(0);
}

// ---- Driver code: ----:
int main()
{
  std::string s1 = "elephant";
  std::string s2 = "eretpat";

  std::cout << "Longest Common Subsequence length: \n"
            << "\tTop Down: " << lcsTD(s1, s2, 0, 0) << "\n"
            << "\tBottom Up: " << lcsBU(s1, s2) << "\n";

  s1 = "houdini";
  s2 = "hdupti";

  std::cout << "Longest Common Subsequence length: \n"
            << "\tTop Down: " << lcsTD(s1, s2, 0, 0) << "\n"
            << "\tBottom Up: " << lcsBU(s1, s2) << "\n";

  return 0;
}