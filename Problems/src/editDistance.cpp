/****************************************************************/
/* Edit Distance (Convert one string into another) (LC)* *******/
/****************************************************************/
/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
  --Insert a character
  --Delete a character
  --Replace a character
*/
#include <iostream>
#include <string>
#include <cmath>

int minDistanceHelper(std::string word1, std::string word2, int w1, int w2)
{
  // if we reach the end of one of the strings, the remaining characters
  // of the other should be deleted:
  if (w1 == word1.size())
  {
    return word2.size() - w2;
  }
  if (w2 == word2.size())
  {
    return word1.size() - w1;
  }

  // if the characters match, advance for the next character:
  if (word1.at(w1) == word2.at(w2))
  {
    return minDistanceHelper(word1, word2, w1 + 1, w2 + 1);
  }
  // perform deletion:
  int accumDel = 1 + minDistanceHelper(word1, word2, w1, w2 + 1);
  // perform insertion:
  int accumIns = 1 + minDistanceHelper(word1, word2, w1 + 1, w2);
  // perform replacement:
  int accumRep = 1 + minDistanceHelper(word1, word2, w1 + 1, w2 + 1);

  return std::min(std::min(accumDel, accumIns), accumRep);
}

int minDistance(std::string word1, std::string word2)
{
  return minDistanceHelper(word1, word2, 0, 0);
}

int main()
{
  std::string str1 = "horse";
  std::string str2 = "ros";

  std::cout << "Minimum cost to convert " << str1 << " into " << str2 << ": " << minDistance(str1, str2) << "\n";

  str1 = "intention";
  str2 = "execution";

  std::cout << "Minimum cost to convert " << str1 << " into " << str2 << ": " << minDistance(str1, str2) << "\n";

  /* The following case takes a very long time to compute the answer which exceeds the time limit: 
  str1 = "dinitrophenylhydrazine";
  str2 = "acetylphenylhydrazine";
  std::cout << "Minimum cost to convert " << str1 << " into " << str2 << ": " << minDistance(str1, str2) << "\n";
  */

  return 0;
}

/* -- Comments:
This solution works but the recursive approach is way too expensive and the amount of operations needed to compute
a solution grows impressively fast in regards to the size of the input.
*/