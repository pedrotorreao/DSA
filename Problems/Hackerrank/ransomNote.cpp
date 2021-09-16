/****************************************************************/
/* Problem - Ransom Note (HR)  ********/
/****************************************************************/
/*
-- Problem statement:
Given the words in a magazine and the words in a ransom note, print 
'Yes' if you can replicate the ransom note exactly using whole words 
from the magazine; otherwise, print 'No'.
-- Rules:
The words in the note are case-sensitive and you must use only whole 
words available in the magazine. You cannot use substrings or 
concatenation to create the words you need.
-- Inputs: 
string magazine[m]: the words in the magazine
string note[n]: the words in the ransom note 
-- Output:
Print 'Yes' if the note can be formed using the magazine, or 'No'. 
*/
#include <iostream>
#include <vector>
#include <unordered_map>

void checkMagazine(std::vector<std::string> magazine, std::vector<std::string> note)
{
  std::unordered_map<std::string, int> ransomMap;

  // go through the maganize and map each word in it as
  // well as how many times it appears:
  for (auto &word : magazine)
  {
    if (!ransomMap[word])
    {
      ransomMap[word] = 1;
    }
    else
    {
      ransomMap[word] += 1;
    }
  }

  // go through the ransom note and for each word in it
  // check if it's on the words mapped from the magazine;
  // if not, it's not possible to form the ransom note
  // from the magazine; if it is, decrement the quantity
  // available of that word and keep checking:
  for (auto &word : note)
  {
    if (!ransomMap[word])
    {
      std::cout << "No"
                << "\n";
      return;
    }
    ransomMap[word] -= 1;
  }
  std::cout << "Yes"
            << "\n";
  return;
}

int main()
{

  std::cout << "\nMagazine: give me one grand today night\n"
            << "Ransom note: give one grand today\n";
  std::cout << "Can the ransom note be formed from the magazine: ";
  checkMagazine({"give", "me", "one", "grand", "today", "night"}, {"give", "one", "grand", "today"});

  std::cout << "\nMagazine: o l x imjaw bee khmla v o v o imjaw l khmla imjaw x\n"
            << "Ransom note: imjaw l khmla x imjaw o l l o khmla v bee o o imjaw imjaw o\n";
  std::cout << "Can the ransom note be formed from the magazine: ";
  checkMagazine({"o", "l", "x", "imjaw", "bee", "khmla", "v", "o", "v", "o", "imjaw", "l", "khmla", "imjaw", "x"}, {"imjaw", "l", "khmla", "x", "imjaw", "o", "l", "l", "o", "khmla", "v", "bee", "o", "o", "imjaw", "imjaw", "o"});

  return 0;
}