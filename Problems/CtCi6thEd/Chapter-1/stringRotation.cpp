/*********************************************************************************************/
/* Problem: String Rotation (CtCi 1.9) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Assume you have a method 'isSubstring' which checks if one word is a substring of another. Given
  two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to the
  method 'isSubstring'.
  Example:
    "waterbottle" is a rotation of "erbottlewat".

--Reasoning:
    If s2 is a rotation of s1, s2 will be a substring of s1 concatenated with itself.

--Time complexity: O(N), where N is the size of the concatenated string.

--Space complexity: O(N), where N is the size of the concatenated string.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

bool isRotation(const std::string &s1, const std::string &s2)
{
  if (s1.length() != s2.length())
  {
    return false;
  }

  std::string s1_concat = s1 + s1;

  if (s1_concat.find(s2) != std::string::npos)
  {
    return true;
  }

  return false;
}

int main()
{
  std::cout << std::boolalpha;

  std::string s1{"waterbottle"};
  std::string s2{"erbottlewat"};

  std::cout << "\"" << s1 << "\""
            << " is a rotation of "
            << "\"" << s2 << "\": " << isRotation(s1, s2) << "\n";

  s1 = "complaints";
  s2 = "intscompla";
  std::cout << "\"" << s1 << "\""
            << " is a rotation of "
            << "\"" << s2 << "\": " << isRotation(s1, s2) << "\n";

  s1 = "aaaabbbbabab";
  s2 = "ababaaaabbba";
  std::cout << "\"" << s1 << "\""
            << " is a rotation of "
            << "\"" << s2 << "\": " << isRotation(s1, s2) << "\n";

  s1 = "aaaabbbbabab";
  s2 = "ababaaaabbbb";
  std::cout << "\"" << s1 << "\""
            << " is a rotation of "
            << "\"" << s2 << "\": " << isRotation(s1, s2) << "\n";

  return 0;
}
