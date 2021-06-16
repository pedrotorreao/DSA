/****************************************************************/
/*Problem: Sherlock and Anagrams (HR)  ********/
/****************************************************************/
/*
-- Summary:

-- Input(s):

-- Expected output(s):

-- Constraints:
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
      //std::cout << it->first << " ";
      count += (it->second - 1);
    }
    it++;
  }

  return count;
}

int main()
{
  std::string s = "kkkk";

  //std::vector<std::string> subs = getAllSubstrings(s);

  std::cout << sherlockAndAnagrams(s) << "\n";

  return 0;
}