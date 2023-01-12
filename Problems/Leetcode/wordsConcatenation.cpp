/*********************************************************************************************/
/* Problem: LC 30. Substring with Concatenation of All Words /********************************/
/*********************************************************************************************/
/*
--Problem statement:

You are given a string 's' and an array of strings 'words'. All the strings of 'words' are of
the same length.
A concatenated substring in 's' is a substring that contains all the strings of any permutation
of 'words' concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd",
and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it
is not the concatenation of any permutation of 'words'.

Return the starting indices of all the concatenated substrings in 's'. You can return the answer
in any order.

  > Example 1:
    Input: s = "barfoothefoobarman", words = ["foo","bar"]
    Output: [0,9]
    Explanation:
      Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of
      length 6.
      The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is
      a permutation of words.
      The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is
      a permutation of words.
      The output order does not matter. Returning [9,0] is fine too.

  > Example 2:
    Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
    Output: []
    Explanation:
      Since words.length == 4 and words[i].length == 4, the concatenated substring has to be of
      length 16.
      There is no substring of length 16 is s that is equal to the concatenation of any permutation
      of words.
      We return an empty array.

  > Example 3:
    Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
    Output: [6,9,12]
    Explanation:
      Since words.length == 3 and words[i].length == 3, the concatenated substring has to be of
      length 9.
      The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which
      is a permutation of words.
      The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which
      is a permutation of words.
      The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which
      is a permutation of words.

--Inputs:
  -string: input string to search in
  -string[]: list of words to be searched for

--Output:
  -int[]: starting indices of all the concatenated substrings in 's'

--Constraints:
    :: 1 <= s.length <= 104
    :: 1 <= words.length <= 5000
    :: 1 <= words[i].length <= 30
    :: s and words[i] consist of lowercase English letters.

--Reasoning: See comments below.

--Time complexity: O(S*W*L)
    S: length of the given string
    W: number of words in the list
    L: length of each word in the list ("str.substr(nextWordStart, WORD_SIZE)")

--Space complexity: O(W + M)
    W: for the worst case in which we store all the words in the list.
    M: output list of indices
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void display1D(const std::vector<int> &vec);

std::vector<int> getSubstringIndexes(std::string &str, std::vector<std::string> &wordList) {
  const int WORD_COUNT = wordList.size();      // number of words in the list
  const int WORD_SIZE = wordList.at(0).size(); // size of each word in the list
  const int STR_SIZE = str.size();             // size of the string to be analyzed

  // if the string passed in has a length smaller than the combined length of all the
  // words in the list, a concatenated substring won't be possible, return -1:
  if (STR_SIZE < (WORD_COUNT * WORD_SIZE))
    return std::vector<int>(1, -1);

  std::unordered_map<std::string, int> wordFreqMap;
  // store the frequency of each word in the list in a hashmap:
  for (const std::string &s : wordList)
    ++wordFreqMap[s];

  std::vector<int> substringIDs{}; // array for storing the substring indices

  int substringStart{0}, // starting position of the current substring
      wordInList{0},     // multiplier to keep track of how many word in the list have been seen
      lastPossibleStartingPoint = STR_SIZE - (WORD_COUNT * WORD_SIZE);

  // check all the substrings from the start until the "lastPossibleStartingPoint":
  while (substringStart <= lastPossibleStartingPoint) {
    // keep a hash map to keep track of all the words seen if we begin at "substringStart":
    std::unordered_map<std::string, int> wordsSeen;

    while (wordInList < WORD_COUNT) {
      // considering the length of each word in the list, calculate the starting point of
      // the next word:
      int nextWordStart = substringStart + (wordInList * WORD_SIZE);

      // extract current word from the string passed in:
      std::string currentWord = str.substr(nextWordStart, WORD_SIZE);
      // exit if the current word is not part of the word list:
      if (wordFreqMap.find(currentWord) == wordFreqMap.end())
        break;

      // "currentWord" is part of the target list, increment its count:
      ++wordsSeen[currentWord];

      // skip current word if its count has been exceeded, i.e. no longer needed:
      if (wordsSeen[currentWord] > wordFreqMap[currentWord])
        break;

      // if all the words in the list have been found in the substring starting at "substringStart",
      // add this index to the result:
      if (wordInList + 1 == WORD_COUNT)
        substringIDs.push_back(substringStart);

      ++wordInList;
    }

    // clear multiplier for next iteration:
    wordInList = 0;

    ++substringStart;
  }

  return substringIDs;
}

int main() {
  std::string str{};
  std::vector<std::string> wordList{};
  std::vector<int> res{};

  /*
  Input: String="catfoxcat", Words=["cat", "fox"]
  Output: [0, 3]
  */
  str = "catfoxcat";
  wordList = {"cat", "fox"};
  res = getSubstringIndexes(str, wordList);
  std::cout << "Substring found at indices: ";
  display1D(res);

  /*
  Input: String="catcatfoxfox", Words=["cat", "fox"]
  Output: [3]
  */
  str = "catcatfoxfox";
  wordList = {"cat", "fox"};
  res = getSubstringIndexes(str, wordList);
  std::cout << "Substring found at indices: ";
  display1D(res);

  return 0;
}

void display1D(const std::vector<int> &vec) {
  for (const auto &v : vec)
    std::cout << v << "  ";
  std::cout << "\n\n";
}