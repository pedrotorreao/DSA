/*********************************************************************************************/
/* Problem: Check Permutation (CtCi 1.2) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given two strings, write a method to decide if one is a permutation of the other.
--Reasoning:
  Map all characters in one of the strings to a hash table accounting for the frequence that each
  character appears. After that, iterate through the other string checking if all the characters
  in the second string are present at the hash table in the same frequence. If so, it is a valid
  permutation.

--Time complexity: O(s), where s is the length of the largest string
--Space complexity: O(s), in case we have a valid permutation and got to store all characters.
*/

#include <iostream>
#include <string>
#include <unordered_map>

bool isPermutation(std::string &str1, std::string &str2)
{
  std::unordered_map<char, int> map;

  // map string str1 characters:
  for (auto s : str1)
  {
    if (!map[s])
    { // if character was not mapped yet, add it to the table
      map[s] = 1;
    }
    else
    {
      map[s]++; // if character is repeated, update frequence
    }
  }

  // iterate over str2 characters checking if they are
  // present in the hash table:
  for (auto s : str2)
  {
    if (!map[s])
    { // s is not in str1, not a permutation
      return false;
    }
    map[s]--; // update character frequence
  }

  auto it = map.begin();

  while (it != map.end())
  {
    // map[s] > 0: there are more of charac. s in str1 -> not a permutation
    // map[s] < 0: there are more of charac. s in str2 -> not a permutation
    if (it->second != 0)
    {
      return false;
    }
    it++;
  }
  return true;
}

int main()
{
  std::cout << std::boolalpha;

  std::string str1{"house"};
  std::string str2{"uehso"};

  std::cout << "'" << str1 << "' is a permutation of '"
            << str2 << "': " << isPermutation(str1, str2) << "\n";

  str2 = "uehsa";
  std::cout << "'" << str1 << "' is a permutation of '"
            << str2 << "': " << isPermutation(str1, str2) << "\n";

  return 0;
}
