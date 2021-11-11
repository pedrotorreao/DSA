/*********************************************************************************************/
/* Problem: Pangram (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  A pangram is a string that contains every letter of the alphabet. Given a sentence determine
  whether it is a pangram in the English alphabet. Ignore case. Return either pangram or not
  pangram as appropriate.
  > Example:
    s = "The quick brown fox jumps over the lazy dog" --->  pangram

  > Input: string s: a string to test

  > Output: string: either pangram or not pangram

  > Constraints:
    0 < s.length() <= 10^3
    s[i] e {a-z, A-Z, space}

--Reasoning:
    Iterate over the input string and add the characters not seen yet to a hash table. Since we
    may ignore case, at the end, there must be 27 characters mapped to the table, i.e. characters
    'a' to 'z' and the space character.

--Time complexity: O(s), where s is the length of the input string.

--Space complexity: O(s), due to the hash table created which, in the worst case, will have the same
size as the input string.

*/

#include <iostream>
#include <string>
#include <unordered_map>

std::string pangrams(std::string s)
{
  if (s.size() < 27)
  {
    return "not pangram";
  }
  std::unordered_map<char, bool> map_char;

  for (const auto &c : s)
  {
    if (map_char.find(c) == map_char.end())
    {
      map_char[tolower(c)] = true;
    }
    if (map_char.size() == 27)
    {
      return "pangram";
    }
  }

  return "not pangram";
}

int main()
{
  std::string str{"We promptly judged antique ivory buckles for the next prize"};
  std::cout << "Result: " << pangrams(str) << "\n"; // Expected: pangram

  str = {"We promptly judged antique ivory buckles for the prize"};
  std::cout << "Result: " << pangrams(str) << "\n"; // Expected: not pangram

  str = {"a"};
  std::cout << "Result: " << pangrams(str) << "\n"; // Expected: not pangram

  str = {"qmExzBIJmdELxyOFWv LOCmefk TwPhargKSPEqSxzveiun"};
  std::cout << "Result: " << pangrams(str) << "\n"; // Expected: pangram

  str = {"NOVmETKPTbYu ftZPEykhjgF GGkdGjWGwW skjPJsea dtwdqcr DERCUgxOxrRgDQbdzL IZjyXs"};
  std::cout << "Result: " << pangrams(str) << "\n"; // Expected: pangram

  return 0;
}