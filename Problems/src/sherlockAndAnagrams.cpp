/****************************************************************/
/*Problem: Sherlock and Anagrams (HR)  ********/
/****************************************************************/
/*
-- Summary:
Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other. 
-- Input(s):
string s: a string 
-- Expected output(s):
int: the number of unordered anagrammatic pairs of substrings in s.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

std::vector<std::string> getAllSubstrings(std::string str)
{
  std::vector<std::string> allSubstrings;

  for (int i{0}; i < str.size(); i++)
  {
    std::string tempString;

    for (int j{i}; j < str.size(); j++)
    {
      tempString.push_back(str.at(j));
      allSubstrings.push_back(tempString);
    }
  }

  return allSubstrings;
}

std::map<std::string, int> buildSubstringMap(std::vector<std::string> subs)
{
  std::map<std::string, int> stringMap;

  for (int i{0}; i < subs.size(); i++)
  {
    std::string tempString = subs.at(i);
    std::sort(tempString.begin(), tempString.end());

    if (!stringMap[tempString])
    {
      stringMap[tempString] = 1;
    }
    else
    {
      stringMap[tempString]++;
    }
  }

  return stringMap;
}

int sherlockAndAnagrams(std::string s)
{
  // get all substrings of s:
  std::vector<std::string> allSubstrings = getAllSubstrings(s);

  // map substrings sorted:
  std::map<std::string, int> substringMap = buildSubstringMap(allSubstrings);

  // count substrings mapped more than once:
  int count{0};
  auto it = substringMap.begin();

  while (it != substringMap.end())
  {
    if (it->second > 1)
    {
      count += ((it->second) * (it->second - 1)) / 2;
    }
    it++;
  }

  return count;
}

int main()
{
  std::string s1 = "cdcd";
  std::string s2 = "kkkk";
  std::string s3 = "mom";
  std::string s4 = "abba";

  std::cout << "String --> number of anagrammatic pairs"
            << "\n";
  std::cout << s1 << " --> " << sherlockAndAnagrams(s1) << "\n";
  std::cout << s2 << " --> " << sherlockAndAnagrams(s2) << "\n";
  std::cout << s3 << " --> " << sherlockAndAnagrams(s3) << "\n";
  std::cout << s4 << " --> " << sherlockAndAnagrams(s4) << "\n";

  return 0;
}