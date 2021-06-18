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
  int searchPrefix(std::string word);

  Trie()
  {
    this->root = new TrieNode();
  }
  ~Trie() {}
};

void Trie::insertWord(std::string word)
{
}

void Trie::deleteWord(std::string word)
{
}

int Trie::searchPrefix(std::string word)
{
}

int main()
{

  return 0;
}