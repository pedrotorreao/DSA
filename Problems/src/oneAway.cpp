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
#include <unordered_map>

bool isOneAway(const std::string &str1, const std::string &str2)
{
  std::unordered_map<char, int> str_map;
  int diffs{0};

  // map string characters and their frequency:
  for (auto s : str1)
  {
    char c = std::tolower(s);

    if ((!str_map[c]))
    { // if character was not mapped yet, add it to the table
      str_map[c] = 1;
    }
    else
    {
      str_map[c]++; // if character is repeated, update frequence
    }
  }

  // update map by crossing it w/ characters from str2:
  for (auto s : str2)
  {
    char c = std::tolower(s);

    if (!str_map[c] && (str_map[c] != 0) /*str_map.find(c) == str_map.end()*/)
    { // s is not in str1, not a permutation
      //str_map[s] = 1;
      diffs++;
    }
    str_map[s]--; // update character frequence
  }

  auto it = str_map.begin();

  while (it != str_map.end())
  {
    if (it->second != 0)
    {
      diffs++;
    }
    it++;
  }

  return ((diffs > 1) ? false : true);
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