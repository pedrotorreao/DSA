/*********************************************************************************************/
/* Problem: Anagram (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Two words are anagrams of one another if their letters can be rearranged to form the other word.
  Given a string, split it into two contiguous substrings of equal length. Determine the minimum
  number of characters to change to make the two substrings into anagrams of one another.
  > Example:
    s = "abccde"
    Break 's' into two parts: 'abc' and 'cde'. Note that all letters have been used, the substrings
    are contiguous and their lengths are equal. Now you can change 'a' and 'b' in the first substring
    to 'd' and 'e' to have 'dec' and 'cde' which are anagrams. Two changes were necessary.

--Inputs:
  - string s: a string

--Outputs:
  - int: the minimum number of characters to change or -1.

--Reasoning:
  If the string has an odd length, we return -1 since there's no way to split it into anagrams.
  Otherwise, split it into two strings using the C++ substr method and map the characters of one
  of the strings to a hash table along with their frequencies. After that, iterate over the second
  substring and check which characters are present in the same frequency, decrementing it as we
  find the element.

--Time complexity:
  - O(N/2) --> O(N), where N is the size of the string.

--Space complexity:
  - O(N/2) --> O(N), for the space allocated into the hash table.

*/
#include <iostream>
#include <unordered_map>
#include <string>

int anagram(const std::string &s)
{
  if ((s.size() % 2) != 0)
    return -1;

  std::unordered_map<char, int> char_count;
  int changes{0};

  std::string s_1 = s.substr(0, (s.size() / 2));
  std::string s_2 = s.substr((s.size() / 2), (s.size() - 1));

  for (const auto &c : s_1)
  {
    ++char_count[c];
  }

  for (const auto &c : s_2)
  {
    --char_count[c];
  }

  auto it = char_count.begin();

  while (it != char_count.end())
  {
    if (it->second > 0)
    {
      changes += it->second;
    }

    ++it;
  }

  return changes;
}

int main()
{
  std::string s{"abcabc"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 0\n";

  s = {"aaabbb"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 3\n";

  s = {"ab"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 1\n";

  s = {"abc"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: -1\n";

  s = {"mnop"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 2\n";

  s = {"xyyx"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 0\n";

  s = {"xaxbbbxx"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 1\n";

  return 0;
}
