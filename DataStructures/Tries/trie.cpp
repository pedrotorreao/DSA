/****************************************************************/
/* Tries C++ ********/
/****************************************************************/

#include <iostream>
#include <vector>

class TrieNode
{
public:
  //TrieNode * children[26];
  std::vector<TrieNode *> children;
  bool endOfWord;
  int count;

  TrieNode()
  {
    endOfWord = false;
    count = 0;
    children.reserve(26);
    for (auto it = children.begin(); it != children.end(); it++)
    {
      *it = nullptr;
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
    if (current->children.at(j) == nullptr)
    {
      current->children.at(j) = new TrieNode();
    }

    // increment the word count for node children[j] since a new word is being added which whis node is part of:
    ++current->children.at(j)->count;

    // advance to the next character in the word:
    current = current->children.at(j);
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

    if (current->children.at(j) == nullptr)
    {
      return false;
    }

    current = current->children.at(j);
  }

  return (current->endOfWord);
}

bool Trie::deleteHelper(std::string word, TrieNode *parent, int idx)
{
  char currentCharac = word.at(idx);
  TrieNode *current = parent->children.at(int(currentCharac) - 97);
  bool removable = false;

  if (current->count)
  {
    deleteHelper(word, current, idx + 1);
    return false;
  }

  if (idx == word.size() - 1)
  {
    if (current->count)
    {
      current->endOfWord = false;
      return false;
    }
    else
    {
      current = nullptr;
      return true;
    }
  }

  if (current->endOfWord)
  {
    deleteHelper(word, current, idx + 1);
    return false;
  }

  removable = deleteHelper(word, current, idx + 1);

  if (removable)
  {
    current = nullptr;
  }
}

int Trie::searchPrefix(std::string word)
{
  TrieNode *current = this->root;

  for (size_t i{0}; i < word.length(); i++)
  {
    size_t j = int(word.at(i)) - 97;
    if (current->children.at(j) == nullptr)
    {
      return 0;
    }
    current = current->children.at(j);
  }
  return current->count;
}

int main()
{
  Trie trieDS;

  return 0;
}