/******************************************************************************
- - - - Trie
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

class Node
{
public:
  Node *children[26];
  bool endOfWord;
  int count;

  Node()
  {
    endOfWord = false;
    count = 0;
    for (size_t i{0}; i < 26; i++)
    {
      children[i] = nullptr;
    }
  }
  // add destructor later
};

class Trie
{
public:
  Node *insert(std::string str, Node *root)
  {
    // if(root == nullptr){
    //         return new Node();
    // }

    Node *current = root;

    for (size_t i{0}; i < str.length(); i++)
    {
      size_t j = int(str.at(i)) - 97;
      if (current->children[j] == nullptr)
      {
        current->children[j] = new Node();
      }
      ++current->children[j]->count;
      current = current->children[j];
    }
    return root;
  }
  int search(std::string str, Node *root)
  {
    Node *current = root;

    for (size_t i{0}; i < str.length(); i++)
    {
      size_t j = int(str.at(i)) - 97;
      if (current->children[j] == nullptr)
      {
        return 0;
      }
      current = current->children[j];
    }
    return current->count;
  }
};

std::vector<int> contacts(std::vector<std::vector<std::string>> queries)
{
  Trie contacts;
  Node *root = new Node();
  std::vector<int> prefixCount;
  int count = 0;

  for (size_t i{0}; i < queries.size(); i++)
  {
    if (queries.at(i).at(0) == "add")
    {
      contacts.insert(queries.at(i).at(1), root);
    }
    else if (queries.at(i).at(0) == "find")
    {
      count = contacts.search(queries.at(i).at(1), root);
      prefixCount.push_back(count);
    }
  }
  return prefixCount;
}

int main()
{
  std::vector<std::vector<std::string>> queries{
      {"add", "s"},
      {"add", "ss"},
      {"add", "sss"},
      {"add", "ssss"},
      {"add", "sssss"},
      {"find", "s"},
      {"find", "ss"},
      {"find", "sss"},
      {"find", "ssss"},
      {"find", "sssss"},
      {"find", "ssssss"},
  };
  std::vector<int> c;

  c = contacts(queries);

  for (size_t i{0}; i < c.size(); i++)
  {
    std::cout << c.at(i) << "\n";
  }

  return 0;
}