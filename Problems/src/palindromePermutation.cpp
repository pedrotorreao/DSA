/*********************************************************************************************/
/* Problem: Palindrome Permutation (CtCi 1.4) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a string, write a function to check if it is a permutation of a palindrome. A palindrome
  is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement
  of letters. The palindrome does not need to be limited to just dictionary words.
  Example:
    Input: "Tact Coa"
    Ouptut: TRUE (permutations: "taco cat", "atco cta", etc.)
--Reasoning:
  Map the string characters and their frequencies (only letters from a-z) into a hash table i.e. char: int).
  Iterate over the map elements and check if there is more than one character with an odd frequency. If so,
  return false, if not, keep going. If there is an odd frequency character, the string will be mirrored around
  it, so there cannot be more than one.
--Time complexity: O(s), where is the length of the string
--Space complexity: O(s), where is the length of the string
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <unordered_map>

// -- for testing purposes only:
// void displayMap(std::unordered_map<char, int> &m);

bool isPalindromePermutation(const std::string &str)
{
  std::unordered_map<char, int> map;

  // map string characters:
  for (auto s : str)
  {
    char c = std::tolower(s);

    if ((int(c) >= 97) && (int(c) <= 122))
    {
      if ((!map[c]))
      { // if character was not mapped yet, add it to the table
        map[c] = 1;
      }
      else
      {
        map[c]++; // if character is repeated, update frequence
      }
    }
  }

  // -- for testing purposes only:
  // displayMap(map);

  auto it = map.begin();
  int oddCount{0};

  while (it != map.end())
  {

    if ((it->second % 2 != 0))
      oddCount++;

    if (oddCount > 1)
    {
      return false;
    }

    ++it;
  }

  return true;
}

int main()
{
  std::cout << std::boolalpha;

  std::string s{"Tact Coa"};
  std::cout << "\"" << s << "\" is a permutation of a palindrome: " << isPalindromePermutation(s) << "\n";

  s = "rum, is red murder sir,";
  std::cout << "\"" << s << "\" is a permutation of a palindrome: " << isPalindromePermutation(s) << "\n";

  s = "never or even odd";
  std::cout << "\"" << s << "\" is a permutation of a palindrome: " << isPalindromePermutation(s) << "\n";

  s = "never or even odx";
  std::cout << "\"" << s << "\" is a permutation of a palindrome: " << isPalindromePermutation(s) << "\n";

  s = "in Eva, cave I bees a can see";
  std::cout << "\"" << s << "\" is a permutation of a palindrome: " << isPalindromePermutation(s) << "\n";

  s = "saw cat Was it I a";
  std::cout << "\"" << s << "\" is a permutation of a palindrome: " << isPalindromePermutation(s) << "\n";

  s = "saw caat Was it I a";
  std::cout << "\"" << s << "\" is a permutation of a palindrome: " << isPalindromePermutation(s) << "\n";

  return 0;
}

// -- for testing purposes only:
// void displayMap(std::unordered_map<char, int> &m)
// {
//   auto it = m.begin();

//   while (it != m.end())
//   {
//     std::cout << it->first << ": " << it->second << "\n";

//     it++;
//   }
// }

/*
evacaniseebeesinacave
e: 6      i: 2
v: 2      s: 2
a: 4      b: 1
c: 2
n: 2
*/