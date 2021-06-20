/****************************************************************/
/* Tries C++ ********/
/****************************************************************/

#include <iostream>
#include <vector>

class TrieNode
{
public:
  TrieNode *children[26];
  bool endOfWord;
  int count;

  TrieNode()
  {
    endOfWord = false;
    count = 0;

    for (size_t i{0}; i < 26; i++)
    {
      children[i] = nullptr;
    }
  }
};

class Trie
{
private:
  TrieNode *root;

public:
  void insertWord(std::string word);
  void deleteWord(std::string word);
  bool searchWord(std::string word);

  bool deleteHelper(std::string word, TrieNode *parent, int idx);
  bool hasDependent(TrieNode *node);
  int searchPrefix(std::string word);

  Trie()
  {
    this->root = new TrieNode();
  }
  ~Trie() {}
};

void Trie::insertWord(std::string word)
{
  TrieNode *current = this->root;

  for (auto i{0}; i < word.size(); i++)
  {
    // the position in the nodes vector is determined by subtracting the
    // ascii code for the letter word[i] by the ascii code for 'a':
    auto j = int(word.at(i)) - 97; // ascii('a') = 97

    // check if there is already a word which uses the letter word[i],
    // if not, initialize a new node at that position:
    if (current->children[j] == nullptr)
    {
      current->children[j] = new TrieNode();
    }

    // increment the word count for node children[j] since a new word is being added which whis node is part of:
    ++current->children[j]->count;

    // advance to the next character in the word:
    current = current->children[j];
  }

  current->endOfWord = true;
}

void Trie::deleteWord(std::string word)
{
  if (searchWord(word))
  {
    deleteHelper(word, this->root, 0);
  }
}

bool Trie::searchWord(std::string word)
{
  TrieNode *current = this->root;

  for (auto i{0}; i < word.size(); i++)
  {
    auto j = int(word.at(i)) - 97;

    if (current->children[j] == nullptr)
    {
      return false;
    }

    current = current->children[j];
  }

  return (current->endOfWord);
}

bool Trie::deleteHelper(std::string word, TrieNode *parent, int idx)
{
  char currentCharac = word.at(idx);
  TrieNode *current = parent->children[int(currentCharac) - 97];
  bool removable = false;

  if (current->count && idx + 1 < word.size())
  {
    deleteHelper(word, current, idx + 1);

    parent->children[int(currentCharac) - 97]->count--;

    return false;
  }

  if (idx == word.size() - 1)
  {
    if (current->count)
    {
      parent->children[int(currentCharac) - 97]->count--;
      current->endOfWord = false;

      return false;
    }
    else
    {
      parent->children[int(currentCharac) - 97]->count--;
      current = nullptr;

      return true;
    }
  }

  if (current->endOfWord && idx + 1 < word.size())
  {
    deleteHelper(word, current, idx + 1);
    return false;
  }

  removable = deleteHelper(word, current, idx + 1);

  if (removable)
  {
    parent->children[int(currentCharac) - 97]->count--;
    current = nullptr;
  }

  return false;
}

int Trie::searchPrefix(std::string word)
{
  TrieNode *current = this->root;

  for (size_t i{0}; i < word.length(); i++)
  {
    size_t j = int(word.at(i)) - 97;
    if (current->children[j] == nullptr)
    {
      return 0;
    }
    current = current->children[j];
  }
  return current->count;
}

int main()
{
  std::cout.setf(std::ios::boolalpha);

  Trie myTrie;

  myTrie.insertWord("trial");
  myTrie.insertWord("tree");
  myTrie.insertWord("man");
  myTrie.insertWord("mind");
  myTrie.insertWord("mid");
  myTrie.insertWord("apple");
  myTrie.insertWord("middle");

  std::cout << "'trial' is on Trie: " << myTrie.searchWord("trial") << "\n";
  std::cout << "'time' is on Trie: " << myTrie.searchWord("time") << "\n";

  std::cout << "prefix 'tr': " << myTrie.searchPrefix("tr") << "\n";
  std::cout << "prefix 'mi': " << myTrie.searchPrefix("mi") << "\n";

  myTrie.deleteWord("trial");
  std::cout << "'trial' is on Trie: " << myTrie.searchWord("trial") << "\n";

  myTrie.deleteWord("mind");
  std::cout << "'mind' is on Trie: " << myTrie.searchWord("mind") << "\n";
  std::cout << "prefix 'mi': " << myTrie.searchPrefix("mi") << "\n";

  return 0;
}