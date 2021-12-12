/*********************************************************************************************/
/* Problem: Gaming Array 1 (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Andy wants to play a game with his little brother, Bob. The game starts with an array of
  distinct integers and the rules are as follows:
    - Bob always plays first.
    - In a single move, a player chooses the maximum element in the array. He removes it and all
    elements to its right. For example, if the starting array "arr=[2,3,5,4,1]", then it becomes
    "arr'=[2,3]" after removing [5,4,1].
    - The two players alternate turns.
    - The last player who can make a move wins.
  Andy and Bob play 'g' games. Given the initial array for each game, find and print the name of
  the winner on a new line. If Andy wins, print ANDY; if Bob wins, print BOB.
    - To continue the example above, in the next move Andy will remove 3. Bob will then remove 2
    and win because there are no more integers to remove.

--Inputs:
  - int arr[n]: an array of integers

--Outputs:
  - string: either ANDY or BOB

--Constraints:
  - Array "arr" contains "n" distinct integers.

--Reasoning:
  Solution below is commented.

--Time complexity: O(N), in the worst case in which "arr" is an array sorte in ascending order.

--Space complexity: O(N), since we map all of "arr" elements.

*/

#include <iostream>
#include <vector>
#include <map>

std::string gamingArray(std::vector<int> arr)
{
  // C++ map stores (key,value) pairs in a sorted manner. By default, keys are sorted in ascending
  // order, so we add the std::greater<int> class to the declaration to make sure that key are
  // being sorted in descending order:
  std::map<int, int, std::greater<int>> m;

  // Total number of moves so far:
  int moves{0};

  // Keep track of where the updated array is ending so we know when there are no elements left to
  // be removed and the game ends:
  int rightBorder = arr.size() - 1;

  // Use the map to store the array elements and their positions in the original array in the form
  // [key,value]=[arr[i],i]. Since the keys, arr[i], are sorted in descending order, we know that
  // the first element in the map (arr.begin()->first) is the current maximum element:
  for (int i{0}; i < arr.size(); ++i)
  {
    m[arr.at(i)] = i;
  }

  // Iterate while there are elements left in the array, i.e., there are still moves to be made:
  while (rightBorder >= 0)
  {
    // Get iterator to the first element in the map, i.e. the max value:
    auto it = m.begin();
    // Get also its position in the original array:
    int pos = it->second;
    // If current max value is still part of the valid array and not removed by previous moves, update
    // end of the game array to one position before it and increment the number of moves so far:
    if (pos <= rightBorder)
    {
      rightBorder = pos - 1;
      ++moves;
    }
    // Delete current max value, whether valid or not, from the map:
    m.erase(it);
  }

  // Since BOB always begins the game, "moves" will always be an odd value when he plays, while "ANDY"
  // will always play on even "moves" count:
  return (((moves % 2) != 0) ? "BOB" : "ANDY");
}

int main()
{
  std::vector<int> vec{3, 4, 2, 7, 0, 1, 5};

  std::cout << "Winner: " << gamingArray(vec) << "\n";

  return 0;
}

/*
    i = 0:  arr = [3,4,2,7,0,1,5]       size = 7        <max,pos> = <7,3>       "BOB"
    i = 1:  arr = [3,4,2]               size = 3        <max,pos> = <4,1>       "ANDY"
    i = 2:  arr = [3]                   size = 1        <max,pos> = <3,0>       "BOB"

*/