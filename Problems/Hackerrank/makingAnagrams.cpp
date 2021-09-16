/****************************************************************/
/*Problem: Making Anagrams (HR)  ********/
/****************************************************************/
/*
-- Summary:
Given two strings, a and b, that may or may not be of the same length, determine the minimum number of character deletions required to make a and b anagrams. Any characters can be deleted from either of the strings.  
-- Input(s):
string: a and b
-- Expected output(s):
int: the minimum total characters that must be deleted
*/

#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

int makeAnagram(std::string a, std::string b)
{
  std::unordered_map<char, int> charMap; // unordered_map<character, frequency>
  int charsToRemove = 0;

  // map each character of one of the strings and the frequency it appears:
  for (auto i{0}; i < a.size(); i++)
  {
    char currentChar = a.at(i);
    // if current character has not been mapped yet, map it w/ freq. 1:
    if (!charMap[currentChar])
    {
      charMap[currentChar] = 1;
    }
    // otherwise, increment freq.:
    else
    {
      charMap[currentChar]++;
    }
  }

  // go over each character of the other string looking for it in the map:
  for (auto i{0}; i < b.size(); i++)
  {
    char currentChar = b.at(i);
    // if current character is not on the map, it means that it is not present in the
    // mapped string so it should be added to the characters to be removed:
    if (!charMap[currentChar])
    {
      charsToRemove++;
    }
    // otherwise, decrement the freq. of this character in the map to indicate that it a
    // common character:
    else
    {
      charMap[currentChar]--;
    }
  }

  // go over the mapped data and check the freq. count for each character:
  //  - if freq. equal to 0, it means that the same amount of this character is present in both strings;
  //  - if freq. < 0, the second string has a higher freq. of this character, and this excess should be removed;
  //  - if freq. > 0, the first string has a higher freq. of this character, and this excess should be removed;
  auto it = charMap.begin();
  while (it != charMap.end())
  {
    if (it->second != 0)
    {
      charsToRemove += abs(it->second);
    }

    it++;
  }

  return charsToRemove;
}

int main()
{
  std::string a1 = "abc";
  std::string b1 = "cde";

  std::cout << "characters to remove: " << makeAnagram(a1, b1) << "\n";

  std::string a2 = "cde";
  std::string b2 = "cde";

  std::cout << "characters to remove: " << makeAnagram(a2, b2) << "\n";

  std::string a3 = "dcf";
  std::string b3 = "cde";

  std::cout << "characters to remove: " << makeAnagram(a3, b3) << "\n";

  return 0;
}
