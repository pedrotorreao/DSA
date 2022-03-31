/*********************************************************************************************/
/* Problem: Isomorphic Strings (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given two strings 's' and 't', determine if they are isomorphic.
  Two strings 's' and 't' are isomorphic if the characters in 's' can be replaced to get 't'.
  All occurrences of a character must be replaced with another character while preserving the
  order of characters. No two characters may map to the same character, but a character may map
  to itself.
  > Example 1:
      Input: s = "egg", t = "add"
      Output: true

  > Example 2:
      Input: s = "foo", t = "bar"
      Output: false

  > Example 3:
    Input: s = "paper", t = "title"
    Output: true

--Inputs:
  - strings: 's' and 't'

--Output:
  - boolean

--Constraints:
    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.

--Reasoning: See comments below.

--Time complexity:
  O(N), where N is the size of the strings.

--Space complexity:
  O(N), where N is the size of the strings, for the worst case where we have strings containing
  only unique characters.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

bool isIsomorphic(std::string s, std::string t) {
  if (s.size() != t.size())
    return false;

  // map the characters in 's' to their replacements in 't',
  // s[i] --> t[i]:
  std::unordered_map<char, char> char_map;
  // store the already used characters in 't' in order to avoid
  // used the same char to replace different characters in 's':
  std::unordered_set<char> used;

  for (int i{0}; i < s.size(); ++i) {
    // current character in 's' already has a replacement in 't':
    if (char_map.find(s.at(i)) != char_map.end()) {
      // check if we're trying to match the same character in 's'
      // to a different character in 't':
      if (char_map[s.at(i)] != t.at(i))
        return false;
    }
    // if the current character in 't' has alrady been used, the same
    // character would have to be used to replace different s' characters,
    // therefore, the string are not isomorphic:
    else if (used.count(t.at(i)) > 0)
      return false;
    // map current s' character to the current t' character:
    char_map[s.at(i)] = t.at(i);
    // mark the current t' character as used:
    used.insert(t.at(i));
  }
  return true;
}

int main() {
  std::cout << std::boolalpha;

  std::string s{}, t{};

  s = "egg";
  t = "add";
  std::cout << "\"" << s << "\" and \"" << t << "\" are isomorphic: " << isIsomorphic(s, t) << "\n";

  s = "foo";
  t = "bar";
  std::cout << "\"" << s << "\" and \"" << t << "\" are isomorphic: " << isIsomorphic(s, t) << "\n";

  s = "paper";
  t = "title";
  std::cout << "\"" << s << "\" and \"" << t << "\" are isomorphic: " << isIsomorphic(s, t) << "\n";

  s = "akvvagn";
  t = "jlppjti";
  std::cout << "\"" << s << "\" and \"" << t << "\" are isomorphic: " << isIsomorphic(s, t) << "\n";

  s = "akvvagnk";
  t = "jlppjtio";
  std::cout << "\"" << s << "\" and \"" << t << "\" are isomorphic: " << isIsomorphic(s, t) << "\n";

  return 0;
}