/*******************************************************************************************/
/* Edit Distance (Convert one string into another) - Dynamic Programming Approach **********/
/*******************************************************************************************/
/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
  --Insert a character
  --Delete a character
  --Replace a character
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// ---- Top Down Approach - Memoization ----:
int minDistanceHelper(std::string word1, std::string word2, int w1, int w2, std::vector<std::vector<int>> &dp)
{
  if (dp.at(w1).at(w2) == -1)
  {
    // if we reach the end of one of the strings, the remaining characters
    // of the other should be deleted:
    if (w1 == word1.size())
    {
      dp.at(w1).at(w2) = word2.size() - w2;
    }
    else if (w2 == word2.size())
    {
      dp.at(w1).at(w2) = word1.size() - w1;
    }
    // if the characters match, advance for the next character:
    else if (word1.at(w1) == word2.at(w2))
    {
      dp.at(w1).at(w2) = minDistanceHelper(word1, word2, w1 + 1, w2 + 1, dp);
    }
    else
    {
      // perform deletion:
      int accumDel = minDistanceHelper(word1, word2, w1, w2 + 1, dp);
      // perform insertion:
      int accumIns = minDistanceHelper(word1, word2, w1 + 1, w2, dp);
      // perform replacement:
      int accumRep = minDistanceHelper(word1, word2, w1 + 1, w2 + 1, dp);

      dp.at(w1).at(w2) = 1 + std::min(std::min(accumDel, accumIns), accumRep);
    }
  }

  return dp.at(w1).at(w2);
}

int minDistance(std::string word1, std::string word2)
{
  std::vector<std::vector<int>> memo(word1.size() + 1, std::vector<int>(word2.size() + 1, -1));

  return minDistanceHelper(word1, word2, 0, 0, memo);
}
// ---- Bottom Up Approach - Tabulation ----:

// ---- Driver code: ----:
int main()
{
  std::string str1 = "horse";
  std::string str2 = "ros";

  std::cout << "Minimum cost to convert " << str1 << " into " << str2 << ": " << minDistance(str1, str2) << "\n";

  str1 = "intention";
  str2 = "execution";

  std::cout << "Minimum cost to convert " << str1 << " into " << str2 << ": " << minDistance(str1, str2) << "\n";

  /* The following case would take a very long time to compute the answer and exceed the time limit
    if a traditional DC recursive approach was used: */
  str1 = "dinitrophenylhydrazine";
  str2 = "acetylphenylhydrazine";
  std::cout << "Minimum cost to convert " << str1 << " into " << str2 << ": " << minDistance(str1, str2) << "\n";

  return 0;
}