/*********************************************************************************************/
/* Problem: Two Characters (HR)  ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a string, remove characters until the string is made up of any two alternating characters.
  When you choose a character to remove, all instances of that character must be removed. Determine
  the longest string possible that contains just two alternating letters. Given a string 's',
  convert it to the longest possible string 't' made up only of alternating characters. Return the
  length of string 't'. If no string can be formed, return 0.
  > Example:
    a.) s="abaacdabd":
      Delete 'a', to leave "bcdbd". Now, remove the character 'c' to leave the valid string "bdbd"
      with a length of 4. Removing either 'b' or 'd' at any point would not result in a valid string.
      Return 4.
    b.) s="beabeefeab":
      The characters present in are 'a', 'b', 'e', and 'f'. This means that 't' must consist of
      two of those characters and we must delete two others. Our choices for characters to leave
      are [a,b], [a,e], [a, f], [b, e], [b, f] and [e, f]. If we delete 'e' and 'f', the resulting
      string is "babab". This is a valid as there are only two distinct characters ('a' and 'b'),
      and they are alternating within the string. If we delete 'a' and 'f', the resulting string
      is "bebeeeb". This is not a valid string because there are consecutive 'e''s present.
      Removing them would leave consecutive 'b''s, so this fails to produce a valid string. Other
      cases are solved similarly. "babab" is the longest string we can create, return 5.

--Inputs:
  -string s: a string

--Output:
  -int: the length of the longest valid string, or 0 if there are none.

--Constraints:
  1<=length of s<=1000
  s contains only lowercase letters in the range ascii[a-z].

--Reasoning: See comments below.

--Time complexity:
  O(constant * L) --> O(L), where L is the length of the string.

--Space complexity: O(L'), where L' is the length of the resulting string.

*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

bool validateString(std::string &s)
{
  for (int i{1}; i < s.size(); ++i)
  {
    if (s.at(i) == s.at(i - 1))
    {
      return false;
    }
  }
  return true;
}

int alternate(std::string s)
{
  int max_length{0};
  // iterate over the alphabet creating strings with the characters that are present in 's':
  for (char ch_1{'a'}; ch_1 <= 'z'; ++ch_1)
  {
    for (char ch_2{'a'}; ch_2 <= 'z'; ++ch_2)
    {
      if (ch_1 != ch_2)
      {
        // if any of the current characters are not present in the string, skip this iteration:
        if (s.find(ch_1) == std::string::npos || s.find(ch_2) == std::string::npos)
          continue;

        std::string curr_str;
        // creates a string using 'ch_1' and 'ch_2' if these characters are part of 's':
        for (const auto &ch_s : s)
        {
          if (ch_1 == ch_s || ch_2 == ch_s)
            curr_str.push_back(ch_s);
        }
        // validates the string to make sure that there are no adjacent repeated elements:
        if (validateString(curr_str))
        {
          // if the string created is valid, check if its length is the greatest so far:
          max_length = std::max(max_length, (int)curr_str.size());
        }
      }
    }
  }

  return max_length;
}

int main()
{
  std::string str{"abaacdabd"};
  std::cout << "Length of the longest string possible w/ just two alternating letters: " << alternate(str) << "\n"; // Expected: 4

  str = "beabeefeab";
  std::cout << "Length of the longest string possible w/ just two alternating letters: " << alternate(str) << "\n"; // Expected: 5

  str = "asdcbsdcagfsdbgdfanfghbsfdab";
  std::cout << "Length of the longest string possible w/ just two alternating letters: " << alternate(str) << "\n"; // Expected: 8

  str = "asvkugfiugsalddlasguifgukvsa";
  std::cout << "Length of the longest string possible w/ just two alternating letters: " << alternate(str) << "\n"; // Expected: 0

  return 0;
}