/*********************************************************************************************/
/* Problem: Strong Password (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:

-- Inputs:

--Outputs:

--Reasoning:

--Time complexity:

--Space complexity:

*/
#include <iostream>
#include <unordered_map>
#include <string>

int anagram(const std::string &s)
{
  if ((s.size() % 2) != 0)
    return -1;

  std::unordered_map<char, int> char_count;
  int changes{0};

  std::string s_1 = s.substr(0, (s.size() / 2));
  std::string s_2 = s.substr((s.size() / 2), (s.size() - 1));

  for (const auto &c : s_1)
  {
    ++char_count[c];
  }

  for (const auto &c : s_2)
  {
    --char_count[c];
  }

  auto it = char_count.begin();

  while (it != char_count.end())
  {
    if (it->second > 0)
    {
      changes += it->second;
    }

    ++it;
  }

  return changes;
}

int main()
{
  std::string s{"abcabc"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 0\n";

  s = {"aaabbb"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 3\n";

  s = {"ab"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 1\n";

  s = {"abc"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: -1\n";

  s = {"mnop"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 2\n";

  s = {"xyyx"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 0\n";

  s = {"xaxbbbxx"};
  std::cout << "Changes to make anagram: " << anagram(s) << "\tExpected: 1\n";

  return 0;
}
