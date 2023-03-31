/*********************************************************************************************/
/* Problem: ???. Shortest Word Distance ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array of strings 'words' and two different strings that already exist in the array
  'word1' and 'word2', return the shortest distance between these two words in the list.

  Example 1:
    Input:  words = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"],
            word1 = "fox",
            word2 = "dog"
    Output: 5
    Explanation: The distance between "fox" and "dog" is 5 words.

  Example 2:
    Input:  words = ["a", "c", "d", "b", "a"],
            word1 = "a",
            word2 = "b"
    Output: 1
    Explanation: The shortest distance between "a" and "b" is 1 word. Please note that "a" appeared twice.

  Example 3:
    Input:  words = ["a", "b", "c", "d", "e"],
            word1 = "a",
            word2 = "e"
    Output: 4
    Explanation: The distance between "a" and "e" is 4 words.


--Inputs:
  -string[]: array of strings, 'words'
  -string: two different strings that already exist in the array, 'word1' and 'word2'

--Output:
  -int: shortest distance between 'word1' and 'word2'.

--Reasoning: See comments below.

--Time complexity: O(N), where N is the size of the array.

--Space complexity: O(1), no additional input dependent space is allocated.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int shortestDistance(std::vector<std::string> &words, std::string word1, std::string word2) {
  int l_w = 0, r_w = 1, distance = words.size();

  // check all windows until we've reached the end of the array:
  while (r_w < words.size()) {
    // expand the window by moving the right pointer until we find a
    // match for 'word1' or 'word2':
    while (r_w < words.size() && words.at(r_w) != word1 && words.at(r_w) != word2)
      ++r_w;
    // shrink the window by moving the left pointer until we find a
    // match for 'word1' or 'word2':
    while (l_w <= r_w && words.at(l_w) != word1 && words.at(l_w) != word2)
      ++l_w;
    // compute the distance if each pointer correspond to one of the words,
    // and shrink the window once again by incrementing the left pointer:
    if (words.at(l_w) != words.at(r_w)) {
      distance = std::min(distance, r_w - l_w);
      ++l_w;
    }
    // expand the window by moving the right pointer:
    ++r_w;
  }

  return distance;
}

int main() {
  std::vector<std::string> words{};
  std::string word1{""}, word2{""};
  int expec{}, distance{};

  words = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
  word1 = "fox";
  word2 = "dog";
  expec = 5;
  distance = shortestDistance(words, word1, word2);
  std::cout << "Shortest distance between \"" << word1 << " and \"" << word2 << ": " << distance
            << ((distance == expec)
                    ? "    --PASSED"
                    : "    --FAILED")
            << "\n\n";

  words = {"a", "c", "d", "b", "a"};
  word1 = "a";
  word2 = "b";
  expec = 1;
  distance = shortestDistance(words, word1, word2);
  std::cout << "Shortest distance between \"" << word1 << " and \"" << word2 << ": " << distance
            << ((distance == expec)
                    ? "    --PASSED"
                    : "    --FAILED")
            << "\n\n";

  words = {"a", "b", "c", "d", "e"};
  word1 = "a";
  word2 = "e";
  expec = 4;
  distance = shortestDistance(words, word1, word2);
  std::cout << "Shortest distance between \"" << word1 << " and \"" << word2 << ": " << distance
            << ((distance == expec)
                    ? "    --PASSED"
                    : "    --FAILED")
            << "\n\n";

  return 0;
}