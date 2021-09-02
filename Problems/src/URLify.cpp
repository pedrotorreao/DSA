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
  Iterate trrough the string looking for spaces and once we find one, we append the characters '%20'
  to the string.
--Time complexity: O(s), where s is the length of the string
--Space complexity: O(s'), where s' is the length of the new string
*/

#include <iostream>
#include <string>

std::string urlify(const std::string &str, int &strTrueSize)
{
  std::string strURL;

  for (int i = 0; i < strTrueSize; i++)
  {
    if (str.at(i) == ' ')
    {
      strURL.push_back('%');
      strURL.push_back('2');
      strURL.push_back('0');
    }
    else
    {
      strURL.push_back(str.at(i));
    }
  }

  return strURL;
}

int main()
{
  std::string s{"Mr John Smith    "};
  int s_trueSize = 13;

  std::cout << s << " url format: " << urlify(s, s_trueSize) << "\n";

  s = " Today is a good day!";
  s_trueSize = 21;
  std::cout << s << " url format: " << urlify(s, s_trueSize) << "\n"; //"%20Today%20is%20a%20good%20day!"

  return 0;
}