/*********************************************************************************************/
/* Problem: Pangram (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  A space explorer's ship crashed on Mars! They send a series of SOS messages to Earth for help.
  Letters in some of the SOS messages are altered by cosmic radiation during transmission. Given
  the signal received by Earth as a string, s, determine how many letters of the SOS message
  have been changed by radiation.

  > Example:
    s = "SOSTOT"    -->   2 letters changed

  > Input: string s - the string as received on Earth

  > Output: int - the number of letters changed during transmission

  > Constraints:
      1 <= s.length() <= 99
      s.length() % 3 = 0
      s contains only uppercase letters

--Reasoning:
  Iterate over the input string in increments of three (length of 'SOS'), at each step compare if
  the current 3-character substring matches 'SOS'. If it does, evaluate the next three; otherwise,
  count how many characters differ and the count to the result.

--Time complexity: O(n/3) -> O(n), where n is the length of the string.

--Space complexity: O(1), no additional space dependent on the input size is needed.

*/

#include <iostream>
#include <string>

int marsExploration(std::string s)
{
  int changes{0};

  for (size_t i{0}; i < s.size(); i += 3)
  {
    if (s.substr(i, 3) != "SOS")
    {
      if (s.at(i) != 'S')
        changes++;
      if (s.at(i + 1) != 'O')
        changes++;
      if (s.at(i + 2) != 'S')
        changes++;
    }
  }

  return changes;
}

int main()
{
  std::string msg{"SOSTOT"};
  std::cout << "number of changes in '" << msg << "': " << marsExploration(msg) << "\n";

  msg = {"SOSSPSSQSSOR"};
  std::cout << "number of changes in '" << msg << "': " << marsExploration(msg) << "\n";

  msg = {"SOSSOT"};
  std::cout << "number of changes in '" << msg << "': " << marsExploration(msg) << "\n";

  return 0;
}