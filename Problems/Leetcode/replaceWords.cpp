/*********************************************************************************************/
/* Problem: Replace Words (LC)  ********/
/*********************************************************************************************/
/*
--Problem statement:
  In English, we have a concept called 'root', which can be followed by some other word to form
  another longer word - let's call this word 'successor'. For example, when the 'root' "an" is
  followed by the successor word "other", we can form a new word "another".
  Given a dictionary consisting of many 'roots' and a sentence consisting of words separated by
  spaces, replace all the 'successors' in the sentence with the root forming it. If a 'successor'
  can be replaced by more than one 'root', replace it with the 'root' that has the shortest length.
  Return the sentence after the replacement.
  > Example 1:
    Input:
      dictionary = ["cat","bat","rat"],
      sentence = "the cattle was rattled by the battery"
    Output:
      "the cat was rat by the bat"
  > Example 2:
    Input:
      dictionary = ["a","b","c"],
      sentence = "aadsfasf absbs bbab cadsfafs"
    Output:
      "a a b c"

--Inputs:
  - std::vector<std::string>: dictionary consisting of many 'roots'
  - std::string: original sentence consisting of words separated by spaces

--Output:
  - std::string: sentence after replacements

--Constraints:
  1 <= dictionary.length <= 1000
  1 <= dictionary[i].length <= 100
  dictionary[i] consists of only lower-case letters.
  1 <= sentence.length <= 106
  sentence consists of only lower-case letters and spaces.
  The number of words in sentence is in the range [1, 1000]
  The length of each word in sentence is in the range [1, 1000]
  Every two consecutive words in sentence will be separated by exactly one space.
  sentence does not have leading or trailing spaces.

--Reasoning:
  Create a Trie data structure, iterate through the dictionary and add all the roots to the Trie.
  However, when adding a root which has a prefix (another root) already added to the Trie, only
  add the shortest.
  After that, split the sentence in its words and search for each one in the Trie, in case there
  is a root for it, return it, otherwise keep the original word.

--Time complexity:
  O(W*D), where W is the average word length and D is the number of roots in the dictionary.

--Space complexity:
  O(W*N), where W is the average word length and N is the number of words in the Trie.

*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class TrieNode {
public:
  TrieNode *children[26];
  bool endChar;
  std::string prefix;

  TrieNode() {
    endChar = false;
    prefix = "";
    for (int i{0}; i < 26; ++i) {
      children[i] = nullptr;
    }
  }
};

class Trie {
public:
  TrieNode *root;

  Trie() {
    root = new TrieNode();
  }

  void buildTrieFromList(std::vector<std::string> &dictionary) {
    for (std::string &s : dictionary) {
      insertWord(s);
    }
  }

  void insertWord(std::string &str) {
    TrieNode *current = root;

    for (char &c : str) {
      int charac_pos = int(c) - 'a';

      if (current->children[charac_pos] == nullptr) {
        current->children[charac_pos] = new TrieNode();
        current = current->children[charac_pos];
      } else if (current->children[charac_pos]->endChar == true) {
        current = nullptr;
        break;
      } else {
        current = current->children[charac_pos];
      }
    }
    if (current != nullptr) {
      current->endChar = true;
      current->prefix = str;
    }
  }

  std::string replaceByPrefix(std::string str) {
    TrieNode *current = root;
    std::string str_res{};

    for (char &c : str) {
      int charac_pos = int(c) - 'a';
      current = current->children[charac_pos];

      if (current == nullptr)
        break;
      if (current->endChar == true) {
        str_res = current->prefix;
        break;
      }
    }
    if (!str_res.empty())
      return str_res;
    return str;
  }
};

std::string replaceWords(std::vector<std::string> &dictionary, std::string sentence) {
  std::stringstream ss(sentence);
  std::string str_res{};
  std::string token{};

  Trie tr;
  tr.buildTrieFromList(dictionary);

  while (getline(ss, token, ' ')) {
    str_res = str_res + tr.replaceByPrefix(token);
    str_res += " ";
  }
  return str_res.substr(0, str_res.size() - 1);
}

int main() {
  std::vector<std::string> dictionary{"cat", "bat", "rat"};
  std::string sentence{"the cat was rat by the bat"};

  std::cout << replaceWords(dictionary, sentence) << "\n";

  return 0;
}