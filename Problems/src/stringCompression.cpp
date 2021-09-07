/*********************************************************************************************/
/* Problem: String Compression (CtCi 1.6) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Implement a method to perform basic string compression using the counts of repeated characters.
  For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would
  not become smaller than the original string, your method should return the original string.
  You can assume the string has only uppercase and lower case letters (a-z).
  Example:
    aabcccccaaa    ->    a2b1c5a3
--Reasoning:
  
--Time complexity: 
--Space complexity: 
*/

#include <iostream>
#include <string>

std::string stringCompression(const std::string &str)
{
  std::string compressedString{""};

  // ... code

  return (compressedString.size() < str.size()) ? compressedString : str;
}

int main()
{
  std::string s{"aabcccccaaa"};
  std::cout << "\"" << s << "\" compressed becomes: " << stringCompression(s) << "\n"; // a2b1c5a3

  s = "nnnnattrrrrkkkllisssissspqqqqv";
  std::cout << "\"" << s << "\" compressed becomes: " << stringCompression(s) << "\n"; // n4a1t2r4k3l2i1s3p1q4v1

  s = "bbddffhhjjllnn";
  std::cout << "\"" << s << "\" compressed becomes: " << stringCompression(s) << "\n"; // bbddffhhjjllnn (compressed has same length as original)

  return 0;
}