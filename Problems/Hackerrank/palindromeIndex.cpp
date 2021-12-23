/*********************************************************************************************/
/* Problem: Palindrome Index (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:

  > Example:

  > Input:

  > Output:

  > Constraints:

--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <unordered_map>
#include <string>

bool isPalindrome(std::string s);

int palindromeIndex(std::string s)
{
  int left = 0, right = s.size() - 1, id = -1, changes = 0;

  while (left < right)
  {
    if (s.at(left) != s.at(right))
    {
      if ((s.at(left + 1) == s.at(right)) && (s.at(left + 2) == s.at(right - 1)))
      {
        id = left;
        ++left;
        ++changes;
      }
      else if ((s.at(left) == s.at(right - 1)) && (s.at(left + 1) == s.at(right - 2)))
      {
        id = right;
        --right;
        ++changes;
      }
    }
    if (changes > 1 || s.at(left) != s.at(right))
    {
      return -1;
    }
    ++left;
    --right;
  }

  return id;
}

int main()
{
  std::string str{"baa"};
  std::cout << "Palindrome index: " << palindromeIndex(str) << "\n";

  str = "aaabbbb";
  std::cout << "Palindrome index: " << palindromeIndex(str) << "\n";

  str = "aaaabccccaaaa";
  std::cout << "Palindrome index: " << palindromeIndex(str) << "\n";

  return 0;
}

bool isPalindrome(std::string s)
{
  std::cout << "substring: " << s << "\n";
  for (int i{0}; i < (s.size() / 2); ++i)
  {
    if (s.at(i) != s.at(s.size() - 1 - i))
    {
      return false;
    }
  }
  return true;
}

// for (int i{0}; i < (s.size() / 2); ++i)
// {
//   if (s.at(i) != s.at(s.size() - i - 1))
//   {
//     if (isPalindrome(s.substr(i + 1, s.size() - i)))
//     {
//       return i;
//     }
//     else if (isPalindrome(s.substr(i, s.size() - i - 1)))
//     {
//       return (s.size() - i - 1);
//     }
//     else
//     {
//       return -1;
//     }
//   }
// }

// if (isPalindrome(s.substr(left + 1, s.size() - right - 1)))
// {
//   return left;
// }
// else if (isPalindrome(s.substr(left, s.size() - right)))
// {
//   return right;
// }
// else
// {
//   return -1;
// }