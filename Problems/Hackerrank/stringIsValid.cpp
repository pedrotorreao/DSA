/*********************************************************************************************/
/* Problem: String is valid (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Sherlock considers a string to be valid if all characters of the string appear the same number
  of times. It is also valid if he can remove just 1 character at 1 index in the string, and the
  remaining characters will occur the same number of times. Given a string s, determine if it is
  valid. If so, return YES, otherwise return NO.
  > Example:
    a. s = abc  ->  {a:1, b:1, c:1}   >> return "YES"
    b. s = abcc  ->  {a:1, b:1, c:2}   >>  return "YES"
    c. s = abccc  ->  {a:1, b:1, c:3}   >>  return "NO"

--Inputs:
  -string s: a string

--Outputs:
  -string: either YES or NO

--Reasoning: see comments below.

--Time complexity: O(L), where is L is the length of the string.

--Space complexity: O(26)->O(1), no input-dependent space is allocated.

*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
//#include <bits/stdc++.h>

std::string isValid(std::string s)
{
  // --- check edge cases:
  // a. string is empty:
  if (s.empty())
    return "NO";
  // b. string is valid by default, i.e, [1 1 1], [3] or [2 1]:
  if (s.size() <= 3)
    return "YES";

  // array of size 26 (# letters in the alphabet) to map the frequencies:
  std::vector<int> charac_map(26, 0);

  // map each character' frequency:
  for (int i{0}; i < s.size(); ++i)
  {
    int curr_pos = s.at(i) - 'a';

    ++charac_map.at(curr_pos);
  }

  // sort the frequencies array to make it easier to compare them:
  std::sort(charac_map.begin(), charac_map.end());

  // ignore all the characters mapped as zero, i.e, characters that do not exist in the string:
  int firstValidPos{0};

  while (charac_map.at(firstValidPos) == 0)
  {
    ++firstValidPos;
  }

  int min_freq = charac_map.at(firstValidPos);
  int max_freq = charac_map.at(charac_map.size() - 1);

  // all characters happen with the same frequency:
  if (min_freq == max_freq)
    return "YES";

  // difference in frequencies is at most 1 and there are not more than 1 character
  // with different frequencies:
  if ((max_freq - min_freq == 1) && (max_freq > charac_map.at(charac_map.size() - 2)))
    return "YES";

  if (min_freq == 1 && charac_map.at(firstValidPos + 1) == max_freq)
    return "YES";

  return "NO";
}

int main()
{
  std::cout << std::boolalpha << std::uppercase;

  std::string str{"aabbcd"};
  std::cout << "String '" << str << "' is valid: " << isValid(str) << "\n"; // Expected: NO
  std::cout << "\n";

  str = "bbccddaaa";
  std::cout << "String '" << str << "' is valid: " << isValid(str) << "\n"; // Expected: YES
  std::cout << "\n";

  str = "bbccddaaaa";
  std::cout << "String '" << str << "' is valid: " << isValid(str) << "\n"; // Expected: NO
  std::cout << "\n";

  str = "bbcccddd";
  std::cout << "String '" << str << "' is valid: " << isValid(str) << "\n"; // Expected: NO
  std::cout << "\n";

  return 0;
}