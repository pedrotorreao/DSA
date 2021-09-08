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
  Iterate through the string incrementing the char count while the current character is
  the same as the next one (i.e. repeated). Once they differ, append the current character
  as well as its frequency to the compressed string and restart the counter. Finally, check
  if next iteration is the last one, if it is, append current character and its frequency.

--Time complexity: O(s), where s is the length of the original string.
--Space complexity: O(s), sue to the compressed string length.
*/

#include <iostream>
#include <string>

std::string stringCompression(const std::string &str)
{
  std::string compressedString{""};
  unsigned int char_count{1};

  for (int i{0}; i < str.size() - 1; i++)
  {
    char current_char = str.at(i);
    char next_char = str.at(i + 1);

    if (current_char == next_char)
    {
      char_count++;
    }
    else
    {
      compressedString.push_back(current_char);
      compressedString.push_back(std::to_string(char_count).at(0));

      char_count = 1;
    }

    if (i + 1 == (str.size() - 1))
    {
      compressedString.push_back(next_char);
      compressedString.push_back(std::to_string(char_count).at(0));
    }
  }

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