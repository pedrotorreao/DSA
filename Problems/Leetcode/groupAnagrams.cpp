/******************************************************************************
Problem: LC 49. Group Anagrams
*******************************************************************************/
/*
--Problem statement:
  Given an array of strings strs, group the anagrams together. You can return the
  answer in any order.
  An Anagram is a word or phrase formed by rearranging the letters of a different
  word or phrase, typically using all the original letters exactly once.

  > Example 1
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

  > Example 2:
    Input: strs = [""]
    Output: [[""]]

  > Example 3:
    Input: strs = ["a"]
    Output: [["a"]]

--Inputs:
  string[]: array of strings strs

--Output:
  string[][]: 2D array of grouped anagrams.

--Constraints:
    :: 1 <= strs.length <= 104
    :: 0 <= strs[i].length <= 100
    :: strs[i] consists of lowercase English letters.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void display2D(std::vector<std::vector<std::string>> &arr);

/*
Approach #1:
--Reasoning:
    Anagrams when sorted become the same string since the characters and frequencies
    are the same. So, we iterate over the strings array, sorting each one of them and
    grouping the anagrams together in an array mapped to the sorted string. After that,
    we just iterate over the map and, since the anagrams are already grouped, add them
    to the output array.

--Time complexity:
    To sort each string using the C++ sort() algorithm we take O(L*log(L)), where L
    is the length of the largest string, and since we are sorting all the strings,
    N, the total runtime is O(N*(L*log(L))).

--Space complexity:
    O(N), since we allocate memory proportional to the size of the input.
*/
std::vector<std::vector<std::string>> groupAnagrams_1(std::vector<std::string> &strs) {
  const int N = strs.size();

  // output vector:
  std::vector<std::vector<std::string>> ans;
  // hash map: [key,value] => [sorted string, [anagram1,...]]
  std::unordered_map<std::string, std::vector<std::string>> hm;
  std::string str_sorted{};

  for (int i{0}; i < N; ++i) {
    str_sorted = strs.at(i);
    std::sort(str_sorted.begin(), str_sorted.end());

    hm[str_sorted].push_back(strs.at(i));
  }

  auto it = hm.begin();
  while (it != hm.end()) {
    ans.push_back(it->second);
    ++it;
  }

  return ans;
}

/*
Approach #2:
--Reasoning:
    Anagrams when sorted become the same string since the characters and frequencies
    are the same. So, we iterate over the strings array, sorting each one of them and
    grouping the anagrams together in an array mapped to the sorted string. After that,
    we just iterate over the map and, since the anagrams are already grouped, add them
    to the output array.

--Time complexity:
    To sort each string using the 'Counting Sort-ish' algorithm we take O(k+L), where L
    is the length of the largest string and k=26, so:
        O(k+L) = O(26+L) = O(L),
    and since we are sorting all the strings,N, the total runtime is O(N*L).

--Space complexity:
    O(N), since we allocate memory proportional to the size of the input.
*/
std::string strCountingSorta(const std::string &s) {
  const int k{26}; // we are considering lower case letters
  std::vector<int> count(k, 0);

  for (auto &ch : s)
    ++count.at(ch - 'a');

  std::string srtd{};
  for (int ch{0}; ch < k; ++ch) {
    srtd += std::string(count.at(ch), ch + 'a');
  }

  return srtd;
}

std::vector<std::vector<std::string>> groupAnagrams_2(std::vector<std::string> &strs) {
  const int N = strs.size();

  std::vector<std::vector<std::string>> ans;
  std::unordered_map<std::string, std::vector<std::string>> hm;
  std::string str_sorted{};

  for (int i{0}; i < N; ++i) {
    str_sorted = strCountingSorta(strs.at(i));
    hm[str_sorted].push_back(strs.at(i));
  }

  auto it = hm.begin();
  while (it != hm.end()) {
    ans.push_back(it->second);
    ++it;
  }

  return ans;
}

int main() {
  std::vector<std::string> s{};
  std::vector<std::vector<std::string>> res{};

  s = {"eat", "tea", "tan", "ate", "nat", "bat"};
  res = groupAnagrams_1(s);
  display2D(res);
  res = groupAnagrams_2(s);
  display2D(res);
  std::cout << "\n";

  s = {"abets", "actress", "marine", "beast", "alert", "beats", "casters"};
  res = groupAnagrams_1(s);
  display2D(res);
  res = groupAnagrams_2(s);
  display2D(res);
  std::cout << "\n";

  return 0;
}

void display2D(std::vector<std::vector<std::string>> &arr) {
  for (const auto &line : arr) {
    std::cout << "[ ";
    for (const auto &str : line)
      std::cout << str << " ";
    std::cout << "] ";
  }
  std::cout << "\n\n";
}