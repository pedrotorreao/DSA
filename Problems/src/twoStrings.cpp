/****************************************************************/
/* Problem - Two Strings (HR)  ********/
/****************************************************************/
/*
-- Problem statement:
You are given two strings, determine if they share a common substring.
Return 'Yes' if the strings share a common substring, otherwise return'No'.
-- Rules:
Note: a substring may be as small as one character.
-- Inputs: 
strings s1 and s2.
-- Output:
String 'Yes' or 'No', depending if they share a substring or not. 
*/

#include <iostream>
#include <string>
#include <unordered_map>

std::string twoStrings(std::string s1, std::string s2)
{
  std::unordered_map<char, bool> stringMap;

  for (auto letter : s1)
  {
    stringMap[letter] = true;
  }

  for (auto letter : s2)
  {
    if (stringMap[letter])
    {
      return "YES";
    }
  }

  return "NO";
}

int main()
{
  std::string str1 = "aaaaaaaaaaaaaaa";
  std::string str2 = "sdlfkgjfgjgoirjgsfkgja";

  std::cout << "Does (" << str1 << ") and (" << str2 << ") share a substring? " << twoStrings(str1, str2) << "\n";

  str1 = "woerigjdfgjslkgjslgjlglkgjslgkjlgja";
  str2 = ",cmvbncbncvbmncz,mcv";

  std::cout << "Does (" << str1 << ") and (" << str2 << ") share a substring? " << twoStrings(str1, str2) << "\n";

  return 0;
}