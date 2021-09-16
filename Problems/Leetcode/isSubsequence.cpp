/******************************************************************************
Problem: Is Subsequence (LC)
*******************************************************************************/
/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isSubsequence(string s, string t)
{
  // if size of s is greater, s cannot be a subsequence of t:
  if (s.size() > t.size())
  {
    return false;
  }
  // if sizes of s and t are the same, check if they are equal:
  if (s.size() == t.size())
  {
    return (s == t);
  }
  // i goes over s and j goes over t:
  size_t i = 0, j = 0;
  // while the iterators don't get to the end of their respective
  // strings, keep looking:
  while (i < s.size() && j < t.size())
  {
    // if there's is a match, check the next character in s by
    // incrementing i; otherwise just go to the next character
    // in t by incrementing j:
    if (s.at(i) == t.at(j))
    {
      i++;
    }

    j++;
  }
  // i will be the same as the length of s if there is a match for each
  // character of s in the correct sequence in t:
  return (i == s.size());
}
// Time complexity: O(n), where n is the length of the largest string, t.
int main()
{
  string s1 = "abc", t1 = "ahbgdc";
  cout << s1 << " is subsequence of " << t1 << "? " << isSubsequence(s1, t1) << "\n"; // true

  string s2 = "ab", t2 = "baab";
  cout << s2 << " is subsequence of " << t2 << "? " << isSubsequence(s2, t2) << "\n"; // true

  string s3 = "axc", t3 = "ahbgdc";
  cout << s3 << " is subsequence of " << t3 << "? " << isSubsequence(s3, t3) << "\n"; // false

  return 0;
}
