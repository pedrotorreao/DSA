/*********************************************************************************************/
/* Problem: Alternating Characters (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are given a string containing characters 'A' and 'B' only. Your task is to change it into
  a string such that there are no matching adjacent characters. To do this, you are allowed to
  delete zero or more characters in the string. Your task is to find the minimum number of
  required deletions.

Example:
  s = AABAAB
  Remove A an at positions 0 and 3 to make s = ABAB in 2 deletions.

--Reasoning:
  Iterate through the string comparing two adjacent characters, keeping track if the previous
  character is an 'A' or a 'B'. If the previous character is the same as the current one,
  increment the deletion counter, otherwise, update the previous character to the current and
  keep going.

--Time complexity: O(N), where N is the size of the string.

--Space complexity: O(1), no additional space required.

*/

#include <iostream>
#include <vector>
#include <string>

int alternatingCharacters(std::string s)
{
  char prev = s.at(0);
  int count = 0;

  for (int i{1}; i < s.size(); i++)
  {
    if (s.at(i) == prev)
    {
      count++;
    }
    else
    {
      prev = s.at(i);
    }
  }

  return count;
}

int main()
{
  std::vector<std::string> test_vec{"AABAAB", "AAAA", "BBBBB", "ABABABAB", "BABABA", "AAABBB"};

  for (auto test : test_vec)
  {
    std::cout << "Minimum amount of deletions for " << test << ": " << alternatingCharacters(test) << "\n";
  }

  return 0;
}