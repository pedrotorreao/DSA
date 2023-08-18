/*********************************************************************************************/
/* Problem: LC 208. Implement Trie (Prefix Tree) ********/
/*********************************************************************************************/
/*
--Problem statement:
  A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently
  store and retrieve keys in a dataset of strings. There are various applications of this data
  structure, such as autocomplete and spellchecker.

  Implement the Trie class:
    * Trie(): Initializes the trie object.
    * void insert(String word): Inserts the string word into the trie.
    * boolean search(String word): Returns true if the string word is in the trie (i.e., was
    inserted before), and false otherwise.
    * boolean startsWith(String prefix): Returns true if there is a previously inserted string
    word that has the prefix prefix, and false otherwise.

  > Example 1:
      Input:
        ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
        [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
      Output:
        [null, null, true, false, true, null, true]
      Explanation:
        Trie trie = new Trie();
        trie.insert("apple");
        trie.search("apple");   // return True
        trie.search("app");     // return False
        trie.startsWith("app"); // return True
        trie.insert("app");
        trie.search("app");     // return True

--Inputs:
  - TreeNode*: root of a binary tree

--Output:
  - vector<TreeNode*>: root nodes for the subtrees found

--Constraints:
  :: 1 <= word.length, prefix.length <= 2000
  :: word and prefix consist only of lowercase English letters.
  :: At most 3 * 104 calls in total will be made to insert, search, and startsWith.


--Reasoning: See comments below.

--Time complexity:
  O(N), since we traverse all the nodes of the tree in order to serialize them.

--Space complexity:
  O(N), since we store the serialization in a N-sized string.

*/
#include <iostream>
#include <string>

struct TrieNode {
  TrieNode *children[26];
  bool end;
  int count;

  TrieNode() {
    for (int i{0}; i < 26; ++i)
      children[i] = nullptr;

    end = false;
    count = 0;
  }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() {
    root = new TrieNode();
  }

  // -- TC: O(L), where L is the size of word.
  void insert(std::string word) {
    TrieNode *curr = this->root;

    for (const auto &charac : word) {
      int i = charac - 'a';

      if (curr->children[i] == nullptr)
        curr->children[i] = new TrieNode();

      ++curr->children[i]->count;

      curr = curr->children[i];
    }

    curr->end = true;
  }

  // -- TC: O(L), where L is the size of word.
  bool search(std::string word) {
    TrieNode *curr = this->root;

    for (const auto &charac : word) {
      int i = charac - 'a';

      if (curr->children[i] == nullptr)
        return false;

      curr = curr->children[i];
    }

    return curr->end;
  }

  // O(P), where P is the size of the prefix.
  bool startsWith(std::string prefix) {
    TrieNode *curr = this->root;

    for (const auto &charac : prefix) {
      int i = charac - 'a';

      if (curr->children[i] == nullptr)
        return false;

      curr = curr->children[i];
    }

    return true;
  }
};

int main() {
  std::cout << std::boolalpha;

  Trie *trie = new Trie();
  trie->insert("apple");

  std::cout << "Trie contains 'apple':" << trie->search("apple") << "\n";                       // return True
  std::cout << "Trie contains 'app':" << trie->search("app") << "\n";                           // return False
  std::cout << "Trie contains word(s) starting with 'app':" << trie->startsWith("app") << "\n"; // return True

  trie->insert("app");
  std::cout << "Trie contains 'app':" << trie->search("app") << "\n"; // return True

  return 0;
}