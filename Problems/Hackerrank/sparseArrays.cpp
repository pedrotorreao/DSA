/*********************************************************************************************/
/* Problem: Sparse Arrays (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  There is a collection of input strings and a collection of query strings. For each query
  string, determine how many times it occurs in the list of input strings. Return an array
  of the results.

--Reasoning:
  Iterate over the 'strings' vector mapping each individual string to amount of times it
  appears, i.e. map each string to its frequency. After that, iterate over the 'queries'
  vector, and for each of its string check if it was added to the map, if it was, get its
  frequency from the map and add it to the result vector:

--Time complexity:
  O(A + B), where A is the size of the 'strings' vector and B the size of the 'queries' vector.

--Space complexity:
  O(A + B), where A is the size of the 'strings' vector and B the size of the 'queries' vector.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<int> matchingStrings(std::vector<std::string> strings, std::vector<std::string> queries)
{
  std::vector<int> res(queries.size(), 0);
  std::unordered_map<std::string, int> str_map;

  for (const auto &s : strings)
  {
    if (str_map.find(s) != str_map.end())
    {
      str_map[s]++;
    }
    else
    {
      str_map[s] = 1;
    }
  }

  for (size_t i{0}; i < queries.size(); i++)
  {
    if (str_map.find(queries.at(i)) != str_map.end())
    {
      res.at(i) = str_map[queries.at(i)];
    }
  }

  return res;
}

void displayVec(const std::vector<int> &vec)
{
  for (const auto &v : vec)
  {
    std::cout << v << "  ";
  }
  std::cout << "\n";
}

int main()
{
  std::vector<std::string> s{"ab", "ab", "abc"};
  std::vector<std::string> q{"ab", "abc", "bc"};
  std::vector<int> matches = matchingStrings(s, q);
  std::cout << "Matches: "; // expected: [2,1,0]
  displayVec(matches);

  s = {"aba", "baba", "aba", "xzxb"};
  q = {"aba", "xzxb", "ab"};
  matches = matchingStrings(s, q);
  std::cout << "Matches: "; // expected: [2,1,0]
  displayVec(matches);

  s = {"def", "de", "fgh"};
  q = {"de", "lmn", "fgh"};
  matches = matchingStrings(s, q);
  std::cout << "Matches: "; // expected: [1,0,1]
  displayVec(matches);

  s = {"abcde", "sdaklfj", "asdjf", "na", "basdn", "sdaklfj", "asdjf", "na", "asdjf", "na", "basdn", "sdaklfj", "asdjf"};
  q = {"abcde", "sdaklfj", "asdjf", "na", "basdn"};
  matches = matchingStrings(s, q);
  std::cout << "Matches: "; // expected: [1,3,4,3,2]
  displayVec(matches);

  return 0;
}