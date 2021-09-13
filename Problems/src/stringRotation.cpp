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
  
--Time complexity: 

--Space complexity:
*/

#include <iostream>
#include <string>
#include <iomanip>

bool isSubstring(const std::string &s1, const std::string &s2)
{
  // .. code
}

int main()
{
  std::cout << std::boolalpha;

  std::string s1{"waterbottle"};
  std::string s2{"erbottlewat"};

  std::cout << "\"" << s1 << "\""
            << " is a rotation of "
            << "\"" << s2 << "\": " << isSubstring(s1, s2) << "\n";

  s1 = "complaints";
  s2 = "intscompla";
  std::cout << "\"" << s1 << "\""
            << " is a rotation of "
            << "\"" << s2 << "\": " << isSubstring(s1, s2) << "\n";

  s1 = "aaaabbbbabab";
  s2 = "ababaaaabbba";
  std::cout << "\"" << s1 << "\""
            << " is a rotation of "
            << "\"" << s2 << "\": " << isSubstring(s1, s2) << "\n";

  return 0;
}