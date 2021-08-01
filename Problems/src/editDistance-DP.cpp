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

int minDistanceTD(std::string word1, std::string word2)
{
  std::vector<std::vector<int>> memo(word1.size() + 1, std::vector<int>(word2.size() + 1, -1));

  return minDistanceHelper(word1, word2, 0, 0, memo);
}

// ---- Bottom Up Approach - Tabulation ----:
int minDistanceBU(std::string word1, std::string word2)
{
  std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1));

  for (int w1{0}; w1 <= word1.size(); w1++)
  {
    dp.at(w1).at(0) = w1;
  }

  for (int w2{0}; w2 <= word2.size(); w2++)
  {
    dp.at(0).at(w2) = w2;
  }

  for (int w1{1}; w1 <= word1.size(); w1++)
  {
    for (int w2{1}; w2 <= word2.size(); w2++)
    {
      if (word1.at(w1 - 1) == word2.at(w2 - 1))
      {
        dp.at(w1).at(w2) = dp.at(w1 - 1).at(w2 - 1);
      }
      else
      {
        dp.at(w1).at(w2) = 1 + std::min(std::min(dp.at(w1 - 1).at(w2), dp.at(w1).at(w2 - 1)), dp.at(w1 - 1).at(w2 - 1));
      }
    }
  }

  return dp.at(word1.size()).at(word2.size());
}

// ---- Driver code: ----:
int main()
{
  std::string str1 = "horse";
  std::string str2 = "ros";

  std::cout << "Minimum cost to convert " << str1 << " into " << str2 << ":\n"
            << "\tTop Down: " << minDistanceTD(str1, str2)
            << "\tBottom Up: " << minDistanceBU(str1, str2) << "\n";

  str1 = "intention";
  str2 = "execution";

  std::cout << "Minimum cost to convert " << str1 << " into " << str2 << ":\n"
            << "\tTop Down: " << minDistanceTD(str1, str2)
            << "\tBottom Up: " << minDistanceBU(str1, str2) << "\n";

  /* The following case would take a very long time to compute the answer and exceed the time limit
    if a traditional DC recursive approach was used: */
  str1 = "dinitrophenylhydrazine";
  str2 = "acetylphenylhydrazine";

  std::cout << "Minimum cost to convert " << str1 << " into " << str2 << ":\n"
            << "\tTop Down: " << minDistanceTD(str1, str2)
            << "\tBottom Up: " << minDistanceBU(str1, str2) << "\n";

  return 0;
}