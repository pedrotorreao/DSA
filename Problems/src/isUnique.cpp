/*********************************************************************************************/
/* Problem: Is Unique (CtCi 1.1) ********/
/*********************************************************************************************/
/*
--Problem statement:
Implement an algorithm to determine if a string has all unique characters. What if you cannot
use additional data structures?
*/

#include <iostream>
#include <string>
#include <algorithm>

bool isUnique(std::string &str)
{
  //sort string:
  std::sort(str.begin(), str.end());

  for (int i{1}; i < str.size(); i++)
  {
    if (str.at(i) == str.at(i - 1))
      return false;
  }

  return true;
}

int main()
{
  std::cout << std::boolalpha;

  std::string str{"Hello"};
  std::cout << str << " has all unique characters: " << isUnique(str) << "\n";

  str = "oijnhfsba";
  std::cout << str << " has all unique characters: " << isUnique(str) << "\n";

  str = "qwertyuipolkjhmnbvgfdsavcxzq";
  std::cout << str << " has all unique characters: " << isUnique(str) << "\n";

  return 0;
}
