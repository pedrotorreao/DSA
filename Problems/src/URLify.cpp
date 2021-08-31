/*********************************************************************************************/
/* Problem: URLify (CtCi 1.3) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Write a method to replace all spaces in a string with '%20'. You may assume that the string 
  has sufficient space at the end to hold the additional characters, and that you are given the 
  "true" length of the string.
  Example:
    Input: "Mr John Smith    ", 13
    Ouptut: "Mr%20John%20Smith"
--Reasoning:

--Time complexity: O(s), where s is the length of the string
--Space complexity: O(s), in case we have a valid permutation and got to store all characters.
*/

#include <iostream>
#include <string>

std::string urlify(const std::string &str, int &strTrueSize)
{
  std::string strURL;
  // code solution ..

  return strURL;
}

int main()
{
  std::string s{"Mr John Smith    "};
  int s_trueSize = 13;

  std::cout << s << " url format: " << urlify(s, s_trueSize);

  return 0;
}