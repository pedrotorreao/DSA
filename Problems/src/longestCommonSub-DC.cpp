/***********************************************************************************/
/* Problem: Longest Common Subsequence - Divide & Conquer Approach           *******/
/***********************************************************************************/

#include <iostream>
#include <string>
#include <cmath>

int lcs(std::string str1, std::string str2, int i1, int i2)
{
  // base case:
  if (i1 == str1.size() || i2 == str2.size())
  {
    return 0;
  }

  int common3 = 0;

  // current characters match, advance in both strings:
  if (str1.at(i1) == str2.at(i2))
  {
    common3 = 1 + lcs(str1, str2, i1 + 1, i2 + 1);
  }

  // current characters differ, advance in second strings:
  int common1 = lcs(str1, str2, i1, i2 + 1);
  // current characters differ, advance in first strings:
  int common2 = lcs(str1, str2, i1 + 1, i2);

  return std::max(common1, std::max(common2, common3));
}

int main()
{
  std::string s1 = "elephant";
  std::string s2 = "eretpat";

  std::cout << "Longest Common Subsequence length: " << lcs(s1, s2, 0, 0) << "\n";

  s1 = "houdini";
  s2 = "hdupti";

  std::cout << "Longest Common Subsequence length: " << lcs(s1, s2, 0, 0) << "\n";

  return 0;
}