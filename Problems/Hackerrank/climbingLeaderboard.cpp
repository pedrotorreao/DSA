/*********************************************************************************************/
/* Problem: Climbing the leaderboard (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  An arcade game player wants to climb to the top of the leaderboard and track their ranking.
  The game uses Dense Ranking, so its leaderboard works like this:
    - The player with the highest score is ranked number 1 on the leaderboard.
    - Players who have equal scores receive the same ranking number, and the next player(s)
    receive the immediately following ranking number.
    > Example:
      a.) ranked=[100,90,90,80]   player=[70,80,105]
          The ranked players will have ranks 1, 2, 2, and 3, respectively. If the player's scores
          are 70, 80 and 105, their rankings after each game are 4th, 3rd and 1st. Return [4,3,1].
--Inputs:
  -int ranked[n]: the leaderboard scores
  -int player[m]: the player's scores

--Outputs:
  -int[m]: the player's rank after each new score

--Constraints:
  0<=ranked[i]<=10^9 for 0<=i<n, where n is the size of 'ranked'
  0<=player[i]<=10^9 for o<=j<m, where m is the size of 'player'
  The existing leaderboard, 'ranked', is in descending order.
  The player's scores, 'player', are in ascending order.

--Reasoning:
  See comments below. We are using a C++ STL map container which is a sorted
  associative container that contains key-value pairs w/ unique keys and these keys are sorted.
  Search, removal and insertion operations all have logarithmic time complexity because under
  the hood 'map' are implemented as Red-Black Trees.

--Time complexity:
  O(R + P), where R is the number of elements in the leaderboard, 'ranked, and P is the number of
  games the player has played, 'player'. Even though there is a nested loop, the inner while loop
  only runs once.

--Space complexity:
  O(R), where R is the number of elements in the leaderboard. In the worst case, there is no repeated
  elements in 'ranked' and we need to allocate space for all of them in the map.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>

void displayVec(const std::vector<int> &vec)
{
  std::cout << "Result: ";
  for (const auto &v : vec)
  {
    std::cout << v << "  ";
  }
  std::cout << "\n";
}

std::vector<int> climbingLeaderboard(std::vector<int> ranked, std::vector<int> player)
{
  // result: vector of player ranks
  std::vector<int> player_ranks;
  // since 'ranked' is sorted in descending order by default, the maximum value is the
  // first one in the vector:
  int max = ranked.at(0);
  // c++ map to build the ranks based on the 'ranked' vector:
  std::map<int, int, std::greater<int>> ranked_map;
  // we know that the greatest value in 'ranked' get rank 1:
  ranked_map[max] = 1;
  // now, since equal scores will get the same rank, we only map a repeated score once,
  // this can save us some space and time when iterarting through the map later. Also,
  // since 'ranked' is ordered and we skip repeated values, each current value gets
  // the rank of previous +1:
  for (int i{1}; i < ranked.size(); ++i)
  {
    int prev_rank = ranked_map[ranked[i - 1]];

    if (ranked.at(i) == ranked.at(i - 1))
      continue;

    ranked_map[ranked.at(i)] = prev_rank + 1;
  }
  // since the player's scores are sorted in ascending order and the 'ranked_map' is sorted
  // in descending order, we'll check the elements of 'ranked_map' from the end:
  auto it = ranked_map.rbegin();
  // now, we iterate over the player's scores and for each one of them we look for the first
  // higher score in 'ranked_map', if there's no larger score (it = ranked_map.rend()), it means
  // that the current player' score, 'player[i]', is the highest so far; otherwise, if there is
  // a higher score, we stop looking and add 1 to the rank of the element found and that will be
  // the rank of 'player[i]'. It's good to mention that we are not checking all the elements of
  // 'ranked_map' for each element of 'player' since the iterator 'it' is not restarted for every
  // iteration of the for loop and keeps the state/position from the last iteration. So, we'll
  // only go over 'ranked_map' elements once.
  for (int i{0}; i < player.size(); ++i)
  {
    while (it != ranked_map.rend())
    {
      if (it->first > player.at(i))
        break;
      ++it;
    }
    if (it != ranked_map.rend())
      player_ranks.push_back(it->second + 1);
    else
      player_ranks.push_back(1);
  }

  return player_ranks;
}

int main()
{
  std::vector<int> ranked{100, 90, 90, 80};
  std::vector<int> player{70, 80, 105};
  displayVec(climbingLeaderboard(ranked, player)); // Expected: [4,3,1]

  ranked = {100, 100, 50, 40, 40, 20, 10};
  player = {5, 25, 50, 120};
  displayVec(climbingLeaderboard(ranked, player)); // Expected: [6,4,2,1]

  ranked = {100, 90, 90, 80, 75, 60};
  player = {50, 65, 77, 90, 102};
  displayVec(climbingLeaderboard(ranked, player)); // Expected: [6,5,4,2,1]

  return 0;
}