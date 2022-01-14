/*********************************************************************************************/
/* Problem: Sherlock and Anagrams (HR)  ********/
/*********************************************************************************************/
/*
--Problem statement:
  Two strings are anagrams of each other if the letters of one string can be rearranged to form
  the other string. Given a string, find the number of pairs of substrings of the string that are
  anagrams of each other.

--Inputs:
  -string s: a string

-- Output:
  -int: the number of unordered anagrammatic pairs of substrings in s.

--Constraints:
  1<=q<=10
  2<=length of s<=100
  s contains only lowercase letters in the range ascii[a-z].

--Reasoning:
  > If there are no repeated letters, there are no anagrams.
  > Since the problem statement specified substring, rearrangement of letters is not possible.
  > [1]: Get all possible substrings from 's'.
  > [2]: Sort each substring, if there are anagrams, the result from the sorting will be the same:
      - Example: "abc" and "cba", when sorted they both become "abc".
  > [3]: Map each sorted substring and the frequency it happens:
      - [key,value]: [sorted substring, frequency]
  > [4]: Now, we iterate over the map and for each substring frequency we count how many pairs
        it is possible to form from "frequency" elements. For this, we use the formula:
          -- number of pairs you can form from an 'n' element set: n*(n-1)/2
          where 'n' for us is the mapped frequency for each subtring.

--Time complexity: O((N^2)*logN)
  getAllSubstrings() - O(N^2)
  buildSubstringMap() - O(N*(N*logN)) --> O((N^2)*logN)

--Space complexity: O(N^2/2)-->O(N^2), since we store all possible subtrings.

*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

void getAllSubstrings(std::string str, std::vector<std::string> &allSubstrings)
{
  for (int i{0}; i < str.size(); i++)
  {
    std::string tempString;

    for (int j{i}; j < str.size(); j++)
    {
      tempString.push_back(str.at(j));
      allSubstrings.push_back(tempString);
    }
  }
}

void buildSubstringMap(std::vector<std::string> subs, std::map<std::string, int> &stringMap)
{
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
}

int sherlockAndAnagrams(std::string s)
{
  // get all substrings of s:
  std::vector<std::string> allSubstrings;
  getAllSubstrings(s, allSubstrings);

  // map substrings sorted:
  std::map<std::string, int> substringMap;
  buildSubstringMap(allSubstrings, substringMap);

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