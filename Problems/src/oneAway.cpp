/*********************************************************************************************/
/* Problem: One Away (CtCi 1.5) ********/
/*********************************************************************************************/
/*
--Problem statement:
  There are three types of edit that can be performed on strings: insert a character, remove a
  character, or replace a character. Given two strings, write a function to check if they are
  one edit (or zero edits) away.
  Example:
    pale - ple    ->    true
    pales - pale  ->    true
    pale  - bale  ->    true
    pale  - bake  ->    false
--Reasoning:
   
--Time complexity: 
--Space complexity: 
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

bool isOneAway(const std::string &str1, const std::string &str2)
{
  // if size difference is > 1, more than 1 edit is needed, return false:
  if (abs(str1.size() - str2.size()) > 1)
    return false;

  // determine the smaller and larger strings:
  std::string bigger = (str1.size() >= str2.size()) ? str1 : str2;
  std::string smaller = (str1.size() < str2.size()) ? str1 : str2;

  int ids{0}, idb{0};
  bool oneEditDone{false};

  while (ids < smaller.size() && idb < bigger.size())
  {
    // characters differ:
    if (smaller.at(ids) != bigger.at(idb))
    {
      // check if 1 edit was already accounted for, if so, return false:
      if (oneEditDone)
      {
        return false;
      }
      // if not, set the flag to TRUE:
      oneEditDone = true;

      // if the strings are the same size, the edit is a replacement,
      // increment both pointers (idb is incremented outside if checks):
      if (bigger.size() == smaller.size())
      {
        ids++;
      }
    }
    // characters match:
    // increment both pointers (idb is incremented outside if checks):
    else
    {
      ids++; // not incremented for first edit when string sizes differ (delete, insert)
    }

    idb++;
  }

  return true;
}

int main()
{
  std::cout << std::boolalpha;

  std::string s1{"pale"};
  std::string s2{"ple"};
  std::cout << "Strings \"" << s1 << "\" and \"" << s2 << "\" are one edit away: " << isOneAway(s1, s2) << "\n"; // Expect TRUE

  s1 = "pales";
  s2 = "pale";
  std::cout << "Strings \"" << s1 << "\" and \"" << s2 << "\" are one edit away: " << isOneAway(s1, s2) << "\n"; // Expect TRUE

  s1 = "pale";
  s2 = "bale";
  std::cout << "Strings \"" << s1 << "\" and \"" << s2 << "\" are one edit away: " << isOneAway(s1, s2) << "\n"; // Expect TRUE

  s1 = "pale";
  s2 = "bake";
  std::cout << "Strings \"" << s1 << "\" and \"" << s2 << "\" are one edit away: " << isOneAway(s1, s2) << "\n"; // Expect TRUE

  return 0;
}
