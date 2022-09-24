/******************************************************************************
Problem: Find the longest substring with k unique characters.
*******************************************************************************/
/*
--Problem statement:
  Given a string 'str', print longest possible 'substring' that has exactly 'k'
  unique characters. If there are more than one substring of longest possible
  length, then print any one of them.

  > Example 1:
      Input: str = “aabbcc”, k = 1
      Output: “aa” , “bb” , “cc”

  > Example 2:
      Input: str = “aabbcc”, k = 2
      Output: “aabb” , “bbcc”


  > Example 3:
      Input: str = "aabbcc”, k = 3
      Output: “aabbcc”

--Inputs:
  string s: string to be analyzed

--Output:
  string: longest substring of 's' that has exactly 'k' unique characters.

--Constraints:
    ::

--Reasoning: Sliding window approach.

--Time complexity: O(N): only one pass needed, where N is the length of the input string.

--Space complexity: O(N), for the hash table in the worst case where all the
  characters are unique, where N is the length of the original string.
*/
#include <iostream>
#include <string>
#include <unordered_map>

std::string longestSubstrKUniqueCharac(std::string &str, int k) {
  const int L = str.size();

  if (L < k)
    return 0;

  int l{0}, r{0};
  std::unordered_map<char, int> hm;
  std::string curr_str{""}, best_str{""};

  for (; r < L; ++r) {
    ++hm[str.at(r)];

    if (hm.size() > k) {
      if (!--hm[str.at(l)])
        hm.erase(str.at(l));
      ++l;
      curr_str = str.substr(l, r - l + 1);
    } else {
      curr_str.push_back(str.at(r));
    }

    best_str = (best_str.size() >= curr_str.size()) ? best_str : curr_str;
  }

  return (hm.size() == k) ? best_str : "";
}

int main() {
  std::string s{"aabbcc"};
  int k{1};
  std::cout << "Longest Substring with " << k
            << " unique characters: " << longestSubstrKUniqueCharac(s, k) << "\n";

  k = 2;
  std::cout << "Longest Substring with " << k
            << " unique characters: " << longestSubstrKUniqueCharac(s, k) << "\n";

  k = 3;
  std::cout << "Longest Substring with " << k
            << " unique characters: " << longestSubstrKUniqueCharac(s, k) << "\n";

  s = "aaabbb";
  std::cout << "Longest Substring with " << k
            << " unique characters: " << longestSubstrKUniqueCharac(s, k) << "\n";

  s = "aabacbebebe";
  std::cout << "Longest Substring with " << k
            << " unique characters: " << longestSubstrKUniqueCharac(s, k) << "\n";

  return 0;
}