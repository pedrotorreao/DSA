/*********************************************************************************************/
/* Problem: Is Unique (CtCi 1.1) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Implement an algorithm to determine if a string has all unique characters. What if you cannot
  use additional data structures?
--Reasoning:
  First, we sort the string using C++ STL's std::sort() function and after we iterate through
  the sorted string comparing adjacent characters to check if there is repetition. This will
  run in O(n*log n) time, since the sorting is guaranteed to be O(n*log n) in the worst case
  and the comparisons will run in linear time.

  If using an additional data structure was allowed, a better approach would be to use a hash 
  table to map the string characters as we iterate through the string, counting the characters 
  as we go (e.g. map[charac] += 1) and as soon as a character is repeated we'd return false or
  true if there's no repetition. This would have a linear running time, O(n).
--Time complexity: O(n * log n)
--Space complexity: O(1), no additional space is taken.
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
